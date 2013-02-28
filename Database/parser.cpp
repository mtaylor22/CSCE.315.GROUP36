#include "parser.h"
#include "DatabaseAPI.h"
#include <algorithm>
using namespace DatabaseAPI;
bool keyChar( char j){
	if (j == '(' || j == ')' || j == ' ' || j == '>' || j == '<' || j == '=') 
		return true;
	return false;
}
int getParen(std::string j){
	int buffer = 0;
	std::string currstring = "";
	currstring+=j[1];
	for (int i = 1; i++; i<j.length()){
		if (j[i] ==  ')' && buffer == 0) {
			if ((std::string::npos != currstring.find("AND")) || (std::string::npos != currstring.find("OR"))){
				return -1;
			}else{
				return i;
			}	
		}
		if (j[i] == ')' && buffer>0) buffer--;
		if (j[i] == '(') buffer++;
		if (buffer == 0) currstring+=j[i];
	}
	//currstring == a singular expression minimized to one level
	//find and||or
	
};
std::string removeParens(std::string j){
	for (int i = 0;i<j.length(); i++){
			if (j[i] == '('){
				int k = getParen(j.substr(i));
				if (k > 0 && j[i] == '(' && j[k+i] == ')'){
					j.erase(i, 1);
					j.erase(k+i-1, 1);
				}
			}
		}
		return(j);
}
std::string readToken(std::string partialStr){
	int i = 0;
	if (partialStr.empty()) return "";
	std::string token = "";
	while (!keyChar(partialStr.at(i)) && i<partialStr.length()-1){
		token+=partialStr.at(i);
		i++;
	}
	if (partialStr.length() > i+2 ){
	if ((partialStr.at(i) == '<' || partialStr.at(i) == '>') && partialStr.at(i+1) == '='){
		return token+partialStr.at(i)+partialStr.at(i+1);
	} else return token+partialStr.at(i);
	} else return token+partialStr.at(i);
}
std::vector<std::string> buildStrVec(std::string queryStr){
	std::string bkQueryStr = queryStr;
	std::string token = readToken(queryStr);
	std::vector<std::string> strVec;
	while (!token.empty()){
		
		queryStr.erase(0, token.length());
		if (*token.rbegin() == ')' && token != ")"){
			strVec.push_back(token.substr(0, token.length()-1));
			strVec.push_back(")");
		} else if (token != " " && !token.empty())
		
			strVec.push_back(token);
		token = readToken(queryStr);
	}
	strVec.push_back("");
	return strVec;
}
std::string remSpaces(std::string fullStr){
	for(int i = 3; i < fullStr.length(); i++){
		if(fullStr.at(i) == ' ' && !(readToken(fullStr.substr(i+1)) == "AND " || readToken(fullStr.substr(i+1)) == "OR " || readToken(fullStr.substr(i-3)) == "NOT " || readToken(fullStr.substr(i-3)) == "AND " || readToken(fullStr.substr(i-2)) == "OR "|| readToken(fullStr.substr(i-3)) == "OR "))
			fullStr.erase(i, 1);
	}
	return fullStr;
}
std::vector< std::vector< Proposition > > generateProps(std::vector<std::string> strVec){
	std::vector< std::vector< Proposition > > propVec;
	std::vector< Proposition> emptypVec;
	propVec.push_back(emptypVec);
	propVec.push_back(emptypVec);
	propVec.push_back(emptypVec);
	std::reverse(strVec.begin(), strVec.end());
	int currentLevel=0;
	while (strVec.back()!=""){
		if (strVec.back() == "(") {
			
			currentLevel++;
			strVec.pop_back();
		} else if (strVec.back() == ")") {
			currentLevel--;
			strVec.pop_back();
		} else if (strVec.back() == "NOT "){
			//adding element
			Proposition j;
			j.propNot=true;
			strVec.pop_back();
			j.propOperator=strVec.back().substr(strVec.back().length()-1, 1);
			if (j.propOperator == "=" && (strVec.back().substr(strVec.back().length()-2, 1)== "<" || strVec.back().substr(strVec.back().length()-2, 1)== ">")){
				j.propOperator = strVec.back().substr(strVec.back().length()-2, 1)+j.propOperator;
				j.propAttribute = strVec.back().substr(0, strVec.back().length()-2);
			}else
			j.propAttribute=strVec.back().substr(0, strVec.back().length()-1);
			strVec.pop_back();
			j.propValue=strVec.back();
			strVec.pop_back();
			j.connType="prop";
			propVec.at(currentLevel).push_back(j);
			
		
			
		
		}else if (strVec.back() == "AND " || strVec.back() == "OR "){
		strVec.pop_back();
		}else{
		Proposition j;
			j.propNot=false;
			j.propOperator=strVec.back().substr(strVec.back().length()-1, 1);
			if (j.propOperator == "=" && (strVec.back().substr(strVec.back().length()-2, 1)== "<" || strVec.back().substr(strVec.back().length()-2, 1)== ">")){
				j.propOperator = strVec.back().substr(strVec.back().length()-2, 1)+j.propOperator;
				j.propAttribute = strVec.back().substr(0, strVec.back().length()-2);
			}else
			j.propAttribute=strVec.back().substr(0, strVec.back().length()-1);
			strVec.pop_back();
			j.propValue=strVec.back();
			strVec.pop_back();
			j.connType="prop";
			propVec.at(currentLevel).push_back(j);
		}
	}
	return propVec;
}
std::vector< std::vector< std::string > > generatecVec(std::vector<std::string> strVec){
	std::vector< std::vector<std::string> > cVec;
	std::vector< std::string > emptyVec;
	cVec.push_back(emptyVec);
	cVec.push_back(emptyVec);
	cVec.push_back(emptyVec);
	std::reverse(strVec.begin(), strVec.end());
	int currentLevel=0;
	while (strVec.back()!=""){
		if (strVec.back() == "(") {
			cVec.at(currentLevel).push_back(strVec.back());		
			//cout<<"pushed to cVec["<<currentLevel<<"] "<< strVec.back()<<"\n";	
			currentLevel++;
			strVec.pop_back();
		} else if (strVec.back() == ")") {
			cVec.at(currentLevel).push_back(strVec.back());
			//cout<<"pushed to cVec["<<currentLevel<<"] "<< strVec.back()<<"\n";
			currentLevel--;
			strVec.pop_back();
		} else if (strVec.back() == "AND " ||strVec.back() == "OR " ){
			cVec.at(currentLevel).push_back(strVec.back());
			//cout<<"pushed to cVec["<<currentLevel<<"] "<< strVec.back()<<"\n";
			strVec.pop_back();			
		} else strVec.pop_back();
	}
	return cVec;
}
void pVecPrintout(std::vector< std::vector< Proposition > > pVec){
	for (int i=0; i<3; i++){
		std::cout<<"pVec["<<i<<"]\n";
		for(std::vector<Proposition>::iterator it = pVec.at(i).begin(); it != pVec.at(i).end(); ++it) {
			 it->printout();
		}
	}
	return;
}
void cVecPrintout(std::vector< std::vector< std::string > > cVec){
	for (int i=0; i<3; i++){
		std::cout<<"cVec["<<i<<"]\n";
		for(std::vector<std::string>::iterator it = cVec.at(i).begin(); it != cVec.at(i).end(); ++it) {
			 std::cout << "'"<<*it<<"'\n"; 
		}
	}
	return;
}

 class FindAttribute
{
    std::string name_;

public:
    FindAttribute(const std::string& name)
        : name_(name)
        {}

    bool operator()(const DatabaseAPI::Attribute& attr)
        { return attr.attributeName == name_; }
};
std::vector< std::vector< Proposition > >  linkTree(std::vector< std::vector< std::string > > cVec, std::vector< std::vector< Proposition > > pVec){
//link everything
	std::vector< std::vector< Proposition* > > cpVec;
	std::vector< Proposition*> emptyVec;
		cpVec.push_back(emptyVec);
		cpVec.push_back(emptyVec);
		cpVec.push_back(emptyVec);
	for (int i=0; i<3; i++){
		for(std::vector<Proposition>::iterator it = pVec.at(i).begin(); it != pVec.at(i).end(); ++it) {
			cpVec.at(i).push_back(&(*it));
		}
	}
	

	for (int i=0; i < 3; i++){
		std::reverse(cVec.at(i).begin(), cVec.at(i).end());
		std::reverse(cpVec.at(i).begin(), cpVec.at(i).end());
	}
	
	int jc = 2;
	while (cVec[jc].empty()) jc--;
	int currentLevel = jc;
	std::string token = cVec.at(currentLevel).back();
	Proposition* last =  NULL;
	std::vector< std::vector< Proposition > > lVec;
	std::vector<Proposition> emptyPVec;
	lVec.push_back(emptyPVec);
	lVec.push_back(emptyPVec);
	lVec.push_back(emptyPVec);
	bool lastwasand = false;
	bool lastwaspar = false;
	int t = 0;
	std::cout<<"\n\n\n";
	
	while(token != ""){
		//LHS
		//if prev = (, if prev andor
			std::cout<<"token: '"<<token<<"' list: "<<currentLevel<<"\n";
		if (token == "AND " || token == "OR "){
			Proposition r;
			r.connType = token;
			if (lastwaspar){
					t=1;
					while (lVec[currentLevel+1].rbegin()[t].linked == true){
					t++;
					}				
					r.propLeft = &lVec[currentLevel+1].rbegin()[t];
					lVec[currentLevel+1].rbegin()[t].linked = true;
			} else if (lastwasand){
				r.propLeft = &(*last);
			} else {
			//link to normal prop
				r.propLeft = cpVec[currentLevel].back();
				std::cout<<"linking to ";
				cpVec[currentLevel].back()->printout();
				std::cout<<"\n";
				cpVec[currentLevel].pop_back();
			}
			if (cVec.at(currentLevel).size()>1 &&(cVec.at(currentLevel).end()[-2] == "(" && currentLevel < 2)){t=1;
					t=1;
					while (lVec[currentLevel+1].rbegin()[t].linked == true){
					t++;
					}				
					r.propRight = &lVec[currentLevel+1].rbegin()[t];		

					lVec[currentLevel+1].rbegin()[t].linked = true;
					cVec[currentLevel].pop_back();	
			} else {
			//link to normal
				r.propRight = cpVec[currentLevel].back();
				std::cout<<"linking to ";
				cpVec[currentLevel].back()->printout();
				std::cout<<"\n";
				cpVec[currentLevel].pop_back();
				cVec[currentLevel].pop_back();
			}
			lastwasand=true;
			lVec.at(currentLevel).push_back(r);
			last = &lVec[currentLevel].back();
		} else if (token == "("){
				if (!lastwasand) lastwaspar = true;
				cVec[currentLevel].pop_back();				
			} else if (token == ")"){
				cVec[currentLevel].pop_back();	
				lastwasand=false;
				lastwaspar = false;
			}
			if (cVec[currentLevel].empty() && currentLevel != 0){
				currentLevel--;
				token =  cVec[currentLevel].back();
			} else if (cVec[currentLevel].empty() && currentLevel == 0){
				token = "";
			} else {
				token =  cVec[currentLevel].back();
			}
		}
		std::cout<<"\n\n\n";
		t=1;
		while (lVec[0].rbegin()[t].linked == true){
			t++;
		}				
		lVec[0].at(0).printout();
	return lVec;
}
std::vector< std::vector< Proposition > > evalProps(std::vector < std::vector< Proposition >> pVec, DatabaseAPI::Record recordIn, std::vector<DatabaseAPI::Attribute> attList){
	for (int i = 0; i < 3; i++){
		for( std::vector<Proposition>::iterator it = pVec.at(i).begin(); it != pVec.at(i).end(); ++it){
			//for each element in one section; it=single proposition
			//given record and attribute list
			 std::vector<DatabaseAPI::Attribute>::iterator itt;
			    itt = std::find_if(attList.begin(), attList.end(), FindAttribute(it->propAttribute));
				if (itt != attList.end()) {
					int index = itt - attList.begin();
					if(it->propOperator == "="){
						if (recordIn.accessRecord(index) == it->propValue){ 
							it->evaluation = true;
						}else {
							it->evaluation = false;
						}
					}  else if (it->propOperator == "<"){
						if (atof(recordIn.accessRecord(index).c_str()) < atof((it->propValue).c_str())){
							it->evaluation = true;
						}else {
							it->evaluation = false;
						}
					} else if (it->propOperator == ">"){
						if (atof(recordIn.accessRecord(index).c_str()) >  atof((it->propValue).c_str())){
							it->evaluation = true;
						}else {
							it->evaluation = false;
						}
					} else if (it->propOperator == "<="){
						if (atof(recordIn.accessRecord(index).c_str()) <=  atof((it->propValue).c_str())){
							it->evaluation = true;
						}else {
							it->evaluation = false;
						}
					} else if (it->propOperator == ">="){
						if (atof(recordIn.accessRecord(index).c_str()) >=  atof((it->propValue).c_str())){
							it->evaluation = true;
						}else {
							it->evaluation = false;
						}
					} else if (it->propOperator == "!="){
						if (recordIn.accessRecord(index) != it->propValue){
							it->evaluation = true;
						}else {
							it->evaluation = false;
						}
					} 
				}


		}
	}
	return pVec;
};
int main(){


//vector< vector< Proposition > > tree = linkTree(cVec, pVec);
	
return 0;
}

#include "DatabaseAPI.h"


namespace DatabaseAPI {

float Table::minAttribute (std::string attToMin){
	for(std::vector<Attribute>::iterator attIt = attributeVec.begin(); attIt != attributeVec.end(); ++attIt) {
		if (attIt->attributeName == attToMin){
			std::string attType = attIt->attributeType;
			if (attType != "float" && attType != "int") return -1;
			int index = attIt - attributeVec.begin();
			float attMin = atof(recordVec.front().accessRecord(index).c_str());
			for(std::vector<Record>::iterator recIt = recordVec.begin(); recIt != recordVec.end(); ++recIt) {
				if (recIt->accessRecord(index) != "NULL"){
					if (atof(recIt->accessRecord(index).c_str()) < attMin){
						attMin = atof(recIt->accessRecord(index).c_str());
					}
				}
			}
			return attMin;
		}
	}
	return -1;
};

float Table::maxAttribute (std::string attToMax){
	for(std::vector<Attribute>::iterator attIt = attributeVec.begin(); attIt != attributeVec.end(); ++attIt) {
		if (attIt->attributeName == attToMax){
			std::string attType = attIt->attributeType;
			if (attType != "float" && attType != "int") return -1;
			int index = attIt - attributeVec.begin();
			float attMax = atof(recordVec.front().accessRecord(index).c_str());
			for(std::vector<Record>::iterator recIt = recordVec.begin(); recIt != recordVec.end(); ++recIt) {
				if (recIt->accessRecord(index) != "NULL"){
					if (atof(recIt->accessRecord(index).c_str()) > attMax){
						attMax = atof(recIt->accessRecord(index).c_str());
					}
				}
			}
			return attMax;
		}
	}
	return -1;
};

Record::Record(int numEntries){
	for( int i = 0; i < numEntries; i++){
	std::string jstring = "";
	recordData.push_back(jstring);
	}
};

std::string Record::accessRecord(int numAccess){
	try {
		return (recordData.at(numAccess));
	}
	catch (const std::out_of_range& oor) {
    std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
};

int Record::modifyRecord(int numAccess, std::string strReplace){
	try {
		if (this->recordData.size() == 0) return -1; //Handles empty vectors being modified without throwing oor exception
		recordData.at(numAccess) = strReplace;
		return 0;
	}
	catch (const std::out_of_range& oor) {
	    return -1;
	}
	return -1;
};

Attribute::Attribute(std::string attName, std::string attType){
	attributeName = attName;
	attributeType = attType;
};

Table::Table(){
	std::vector<Attribute> attVec;
	attributeVec = attVec;
};

Table::Table(std::vector<Attribute> attVec){
	attributeVec = attVec;
};

int Table::addAttribute(Attribute attToAdd){
	attributeVec.push_back(attToAdd);
	return 0;
};

int Table::delAttribute(std::string attToDel){
	for(std::vector<Attribute>::iterator it = attributeVec.begin(); it != attributeVec.end(); ++it) {
		if (it->attributeName == attToDel){
			attributeVec.erase(it);
			return 0;
		}
	}
	return -1;
};

bool isInt(std::string potentialInt){
	//must contain only numbers, assumes NULL is acceptable
	std::string::const_iterator it = potentialInt.begin();
    while (it != potentialInt.end() && isdigit(*it)) ++it;
    return ((!potentialInt.empty() && it == potentialInt.end()) || potentialInt == "NULL");
};

bool isFloat(std::string potentialFloat){
	//must contain only numbers or '.', assumes NULL is acceptable
	std::string::const_iterator it = potentialFloat.begin();
    while (it != potentialFloat.end() && (isdigit(*it) || *it == '.')) ++it;
    return ((!potentialFloat.empty() && it == potentialFloat.end()) || potentialFloat == "NULL");
};

bool isDate(std::string potentialDate){
	//yyyy/mm/dd
	if (isdigit(potentialDate.at(0)) && isdigit(potentialDate.at(1)) && isdigit(potentialDate.at(2)) &&
		isdigit(potentialDate.at(3)) && potentialDate.at(4) == '/' && isdigit(potentialDate.at(5)) && isdigit(potentialDate.at(6)) &&
		potentialDate.at(7) == '/' && isdigit(potentialDate.at(8)) && isdigit(potentialDate.at(9))){
		return true;
	} else {
		return false;
	}
};

int Table::insertRecord(Record recToIns){
	for(std::vector<Attribute>::iterator it = attributeVec.begin(); it != attributeVec.end(); ++it) {
		if (it->attributeType == "int"){
			if (!isInt(recToIns.accessRecord(it - attributeVec.begin())))
				return -1;
		}else if (it->attributeType == "float"){
			if (!isFloat(recToIns.accessRecord(it - attributeVec.begin())))
				return -1;
		}else if (it->attributeType == "date"){
			if (!isDate(recToIns.accessRecord(it - attributeVec.begin())))
				return -1;
		}
	}
	recordVec.push_back(recToIns);
	return 0;
};

std::vector<Attribute> Table::getAttributes(){
	return attributeVec;
};

int Table::getSize(){
	return (recordVec.size());
};

int Table::renameAttribute(std::string prevName, std::string newName){
	for(std::vector<Attribute>::iterator it = attributeVec.begin(); it != attributeVec.end(); ++it) {
		if (it->attributeName == prevName){
			it->attributeName = newName;
			return 0;
		}
	}
	return -1;
};

Table Table::crossJoin(Table tableA, Table tableB){
	//ignore intelleSense right now
	Table tableC;
	tableC.attributeVec.insert(tableC.attributeVec.begin(), tableA.attributeVec.begin(), tableA.attributeVec.end());
	tableC.attributeVec.insert(tableA.attributeVec.end(), tableB.attributeVec.begin(), tableB.attributeVec.end());
	//attributes added to each other
	for(std::vector<Record>::iterator itA = tableA.recordVec.begin(); itA != tableA.recordVec.end(); ++itA) {
		for(std::vector<Record>::iterator itB = tableB.recordVec.begin(); itB != tableB.recordVec.end(); ++itB) {
			Record crossRec;
			tableC.recordVec.insert(tableC.recordVec.begin(), tableA.recordVec.begin(), tableA.recordVec.end());
			tableC.recordVec.insert(tableA.recordVec.end(), tableB.recordVec.begin(), tableB.recordVec.end());
			tableC.recordVec.push_back(crossRec);
		}
	}
	return tableC;
};

float Table::sumAttribute(std::string attToSum){
//types will be int, float, string, date
	for(std::vector<Attribute>::iterator attIt = attributeVec.begin(); attIt != attributeVec.end(); ++attIt) {
		if (attIt->attributeName == attToSum){
			std::string attType = attIt->attributeType;
			if (attType != "float" && attType != "int") return -1;
			int index = attIt - attributeVec.begin();
			float attSum = 0;
			for(std::vector<Record>::iterator recIt = recordVec.begin(); recIt != recordVec.end(); ++recIt) {
					attSum += atof(recIt->accessRecord(index).c_str());
			}
			return attSum;
		}
	}
	return -1;
};

float Table::countAttribute(std::string attToCount){
	for(std::vector<Attribute>::iterator attIt = attributeVec.begin(); attIt != attributeVec.end(); ++attIt) {
		if (attIt->attributeName == attToCount){
			int index = attIt - attributeVec.begin();
			float attCount = 0;
			for(std::vector<Record>::iterator recIt = recordVec.begin(); recIt != recordVec.end(); ++recIt) {
				if (recIt->accessRecord(index) != "NULL")
				attCount++;
			}
			return attCount;
		}
	}
	return -1;
};

Database::Database(){};

int Database::addTable(Table tabToAdd, std::string tabNameToAdd){
	tableVec.push_back(tabToAdd);
	tableNames.push_back(tabNameToAdd);
	return 0;
};

int Database::dropTable(std::string tabToDrop){
	for(std::vector<std::string>::iterator it = tableNames.begin(); it != tableNames.end(); ++it) {
		if (*it == tabToDrop){
			tableVec.erase( (it - tableNames.begin()) + tableVec.begin());
			tableNames.erase(it);
			return 0;
		}
		}
	return -1;
};

std::vector<std::string> Database::listTables(){
	return tableNames;
};

std::vector<Table> Database::getTables(){
	return tableVec;
};

Record::Record(){};

//unfinished/started

bool isAnOperator(char j){
	if (j == '>' || j == '<' || j == '!' || j == '=') 
		return true;
	else
		return false;
};
std::string formatWhere(std::string strToFormat){
	int limit = strlen(strToFormat.c_str());
	for (int i = 0; i < limit; i++){
		if (isAnOperator(strToFormat[i]) && (strToFormat[i-1] == ' ')){
			strToFormat.erase((i-1), 1);
			i--;
			limit--;
			
		}
		if (isAnOperator(strToFormat[i]) && (strToFormat[i+1] == ' ')){
			strToFormat.erase((i+1), 1);
			limit--;
		}
	}
	return strToFormat;
};
Table Database::queryTable (std::vector<std::string> selectClause, std::string fromClause, std::string whereClause){
	Table tableResults;
	for(std::vector<std::string>::iterator tabIt = tableNames.begin(); tabIt != tableNames.end(); ++tabIt) {
		if (*tabIt == fromClause){
			tableResults = Table(tableVec.at(std::distance(tableNames.begin(), tabIt)));
			if (selectClause.size() != 0){
					std::vector<Attribute> atts = tableResults.getAttributes();
					for(std::vector<Attribute>::iterator attIt = atts.begin(); attIt != atts.end(); ++attIt){
						if(std::find(selectClause.begin(), selectClause.end(), attIt->attributeName) != selectClause.end()){
							//select contains attribute
							tableResults.delAttribute(attIt->attributeName);
						}
					}
			}
		}
	}
	//empty vector indicates all 
	//input -> list of attributes to keep in table, singular table, condition to meet

	//1. check if table exists in database!!
	whereClause = formatWhere(whereClause);		//makes spaces more meaningful

	

	return tableResults;
};
int Database::deleteTable (std::vector<std::string> selectClause, std::string fromClause, std::string whereClause){

	return -1;
};


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
	std::vector< std::vector<string> > cVec;
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
		cout<<"pVec["<<i<<"]\n";
		for(std::vector<Proposition>::iterator it = pVec.at(i).begin(); it != pVec.at(i).end(); ++it) {
			 it->printout();
		}
	}
	return;
}
void cVecPrintout(std::vector< std::vector< string > > cVec){
	for (int i=0; i<3; i++){
		cout<<"cVec["<<i<<"]\n";
		for(std::vector<string>::iterator it = cVec.at(i).begin(); it != cVec.at(i).end(); ++it) {
			 std::cout << "'"<<*it<<"'\n"; 
		}
	}
	return;
}



}

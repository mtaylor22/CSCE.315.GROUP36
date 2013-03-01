// DatabaseApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "database.h"


vector<vector<string>> generateAttributes(){
	vector<vector<string>> attributes;

	vector<string> chefmozacceptsAttributes;
	chefmozacceptsAttributes.push_back("placeID");
	chefmozacceptsAttributes.push_back("Rpayment");
	attributes.push_back(chefmozacceptsAttributes);

	vector<string> chefmozcuizineAttributes;
	chefmozcuizineAttributes.push_back("placeID");
	chefmozcuizineAttributes.push_back("Rcuisine");
	attributes.push_back(chefmozcuizineAttributes);

	vector<string> chefmozhours4Attributes;
	chefmozhours4Attributes.push_back("placeID");
	chefmozhours4Attributes.push_back("hours");
	chefmozhours4Attributes.push_back("days");
	attributes.push_back(chefmozhours4Attributes);

	vector<string> chefmozparkingAttributes;
	chefmozparkingAttributes.push_back("placeID");
	chefmozparkingAttributes.push_back("parking_lot");
	attributes.push_back(chefmozparkingAttributes);

	vector<string> geoplaces2Attributes;
	geoplaces2Attributes.push_back("placeID");
	geoplaces2Attributes.push_back("latitude");
	geoplaces2Attributes.push_back("longitude");
	geoplaces2Attributes.push_back("the_geom_meter");
	geoplaces2Attributes.push_back("address");
	geoplaces2Attributes.push_back("city");
	geoplaces2Attributes.push_back("state");
	geoplaces2Attributes.push_back("country");
	geoplaces2Attributes.push_back("fax");
	geoplaces2Attributes.push_back("zip");
	geoplaces2Attributes.push_back("alcohol");
	geoplaces2Attributes.push_back("smoking_area");
	geoplaces2Attributes.push_back("dress_code");
	geoplaces2Attributes.push_back("accessibility");
	geoplaces2Attributes.push_back("price");
	geoplaces2Attributes.push_back("url");
	geoplaces2Attributes.push_back("Rambience");
	geoplaces2Attributes.push_back("franchise");
	geoplaces2Attributes.push_back("area");
	geoplaces2Attributes.push_back("other_services");
	attributes.push_back(geoplaces2Attributes);


	vector<string> rating_finalAttributes;
	rating_finalAttributes.push_back("userID");
	rating_finalAttributes.push_back("placeID");
	rating_finalAttributes.push_back("rating");
	rating_finalAttributes.push_back("food_rating");
	rating_finalAttributes.push_back("service_rating");
	attributes.push_back(rating_finalAttributes);

	vector<string> usercuisineAttributes;
	usercuisineAttributes.push_back("userID");
	usercuisineAttributes.push_back("Rcuisine");
	attributes.push_back(usercuisineAttributes);

	vector<string> userpaymentAttributes;
	userpaymentAttributes.push_back("userID");
	userpaymentAttributes.push_back("Upayment");
	attributes.push_back(userpaymentAttributes);

	vector<string> userprofileAttributes;
	userprofileAttributes.push_back("userID");
	userprofileAttributes.push_back("latitude");
	userprofileAttributes.push_back("longitude");
	userprofileAttributes.push_back("smoker");
	userprofileAttributes.push_back("drink_level");
	userprofileAttributes.push_back("dress_preference");
	userprofileAttributes.push_back("ambience");
	userprofileAttributes.push_back("transport");
	userprofileAttributes.push_back("marital_status");
	userprofileAttributes.push_back("hijos");
	userprofileAttributes.push_back("birth_year");
	userprofileAttributes.push_back("interest");
	userprofileAttributes.push_back("personality");
	userprofileAttributes.push_back("religion");
	userprofileAttributes.push_back("activity");
	userprofileAttributes.push_back("color");
	userprofileAttributes.push_back("weight");
	userprofileAttributes.push_back("budget");
	userprofileAttributes.push_back("height");
	attributes.push_back(userprofileAttributes);	

	return attributes;
}
vector<vector<Table::RecordType>> generateTypes(){

	vector<vector<Table::RecordType>> types;
	vector<Table::RecordType> chefmozacceptsTypes;
	chefmozacceptsTypes.push_back(Table::integer);
	chefmozacceptsTypes.push_back(Table::varchar);
	types.push_back(chefmozacceptsTypes);

	vector<Table::RecordType> chefmozcuizineTypes;
	chefmozcuizineTypes.push_back(Table::integer);
	chefmozcuizineTypes.push_back(Table::varchar);
	types.push_back(chefmozcuizineTypes);

	vector<Table::RecordType> chefmozhours4Types;
	chefmozhours4Types.push_back(Table::integer);
	chefmozhours4Types.push_back(Table::varchar);		
	chefmozhours4Types.push_back(Table::varchar);
	types.push_back(chefmozhours4Types);

	vector<Table::RecordType> chefmozparkingTypes;
	chefmozparkingTypes.push_back(Table::integer);
	chefmozparkingTypes.push_back(Table::varchar);
	types.push_back(chefmozparkingTypes);

	vector<Table::RecordType> geoplaces2Types;
	geoplaces2Types.push_back(Table::integer);
	geoplaces2Types.push_back(Table::floating);
	geoplaces2Types.push_back(Table::floating);
	geoplaces2Types.push_back(Table::varchar);
	geoplaces2Types.push_back(Table::varchar);
	geoplaces2Types.push_back(Table::varchar);
	geoplaces2Types.push_back(Table::varchar);
	geoplaces2Types.push_back(Table::varchar);
	geoplaces2Types.push_back(Table::varchar);
	geoplaces2Types.push_back(Table::floating);
	geoplaces2Types.push_back(Table::varchar);
	geoplaces2Types.push_back(Table::varchar);
	geoplaces2Types.push_back(Table::varchar);
	geoplaces2Types.push_back(Table::varchar);
	geoplaces2Types.push_back(Table::varchar);
	geoplaces2Types.push_back(Table::varchar);
	geoplaces2Types.push_back(Table::varchar);
	geoplaces2Types.push_back(Table::varchar);
	geoplaces2Types.push_back(Table::varchar);
	geoplaces2Types.push_back(Table::varchar);
	types.push_back(geoplaces2Types);

	vector<Table::RecordType> rating_finalTypes;
	rating_finalTypes.push_back(Table::varchar);
	rating_finalTypes.push_back(Table::integer);
	rating_finalTypes.push_back(Table::integer);
	rating_finalTypes.push_back(Table::integer);
	rating_finalTypes.push_back(Table::integer);
	types.push_back(rating_finalTypes);

	vector<Table::RecordType> usercuisineTypes;
	usercuisineTypes.push_back(Table::varchar);
	usercuisineTypes.push_back(Table::varchar);
	types.push_back(usercuisineTypes);

	vector<Table::RecordType> userpaymentTypes;
	userpaymentTypes.push_back(Table::varchar);
	userpaymentTypes.push_back(Table::varchar);
	types.push_back(userpaymentTypes);

	vector<Table::RecordType> userprofileTypes;
	userprofileTypes.push_back(Table::varchar);
	userprofileTypes.push_back(Table::floating);
	userprofileTypes.push_back(Table::floating);
	userprofileTypes.push_back(Table::varchar);
	userprofileTypes.push_back(Table::varchar);
	userprofileTypes.push_back(Table::varchar);
	userprofileTypes.push_back(Table::varchar);
	userprofileTypes.push_back(Table::varchar);
	userprofileTypes.push_back(Table::varchar);
	userprofileTypes.push_back(Table::varchar);
	userprofileTypes.push_back(Table::integer);
	userprofileTypes.push_back(Table::varchar);
	userprofileTypes.push_back(Table::varchar);
	userprofileTypes.push_back(Table::varchar);
	userprofileTypes.push_back(Table::varchar);
	userprofileTypes.push_back(Table::varchar);
	userprofileTypes.push_back(Table::integer);
	userprofileTypes.push_back(Table::varchar);
	userprofileTypes.push_back(Table::floating);
	types.push_back(userprofileTypes);

	return types;
}
vector<string> generatePaths(){
	vector<string> paths;
	paths.push_back("../RCdata/chefmozaccepts.csv");
	paths.push_back("../RCdata/chefmozcuisine.csv");
	paths.push_back("../RCdata/chefmozhours4.csv");
	paths.push_back("../RCdata/chefmozparking.csv");
	paths.push_back("../RCdata/geoplaces2.csv");
	paths.push_back("../RCdata/rating_final.csv");
	paths.push_back("../RCdata/usercuisine.csv");
	paths.push_back("../RCdata/userpayment.csv");
	paths.push_back("../RCdata/userprofile.csv");
	return paths;
}
void readIn(string path, vector<Table::RecordType> types, vector<string> attributes, Database &inputDB){

	/*
	"../RCdata/userpayment.txt"
	userID (string) Upayment (string)	
	vector<string> userpaymentTypes;
	vector<string> userpaymentAttributes;
	userpaymentAttributes.push_back("userID");
	userpaymentTypes.push_back("string");
	userpaymentAttributes.push_back("Upayment");
	userpaymentTypes.push_back("string");

	"../RCdata/userprofile.txt"
	userID (string) latitude (long) longitude (long) smoker (bool) drink_level (string) dress_preference (string) ambience (string) transport (string) marital_status (string) hijos (string) birth_year (year) interest (string) personality (string) religion (string) activity (string) color (string) weight (int) budget (string) height (long)
	vector<string> userprofileTypes;
	vector<string> userprofileAttributes;
	userprofileAttributes.push_back("userID");
	userprofileTypes.push_back("string");
	userprofileAttributes.push_back("latitude");
	userprofileTypes.push_back("long");
	userprofileAttributes.push_back("longitude");
	userprofileTypes.push_back("long");
	userprofileAttributes.push_back("smoker");
	userprofileTypes.push_back("bool");
	userprofileAttributes.push_back("drink_level");
	userprofileTypes.push_back("string");
	userprofileAttributes.push_back("dress_preference");
	userprofileTypes.push_back("string");
	userprofileAttributes.push_back("ambience");
	userprofileTypes.push_back("string");
	userprofileAttributes.push_back("transport");
	userprofileTypes.push_back("string");
	userprofileAttributes.push_back("marital_status");
	userprofileTypes.push_back("string");
	userprofileAttributes.push_back("hijos");
	userprofileTypes.push_back("string");
	userprofileAttributes.push_back("birth_year");
	userprofileTypes.push_back("int");
	userprofileAttributes.push_back("interest");
	userprofileTypes.push_back("string");
	userprofileAttributes.push_back("personality");
	userprofileTypes.push_back("string");
	userprofileAttributes.push_back("religion");
	userprofileTypes.push_back("string");
	userprofileAttributes.push_back("activity");
	userprofileTypes.push_back("string");
	userprofileAttributes.push_back("color");
	userprofileTypes.push_back("string");
	userprofileAttributes.push_back("weight");
	userprofileTypes.push_back("int");
	userprofileAttributes.push_back("budget");
	userprofileTypes.push_back("string");
	userprofileAttributes.push_back("height");
	userprofileTypes.push_back("long");


	"../RCdata/chefmozhours4.txt"
	placeID (long) hours (time-time or just string) days (string)
	vector<string> chefmozhours4Types;
	vector<string> chefmozhours4Attributes;
	chefmozhours4Attributes.push_back("placeID");
	chefmozhours4Types.push_back("long");
	chefmozhours4Attributes.push_back("hours");
	chefmozhours4Types.push_back("string");		
	chefmozhours4Attributes.push_back("days");
	chefmozhours4Types.push_back("string");

	"../RCdata/chefmozparking.txt"
	placeID (long) parking_lot (string)
	vector<string> chefmozTypes;
	vector<string> chefmozAttributes;
	chefmozAttributes.push_back("placeID");
	chefmozTypes.push_back("long");
	chefmozAttributes.push_back("parking_lot");
	chefmozTypes.push_back("string");

	"../RCdata/geoplaces2.txt"
	placeID (long) latitude (long) longitude (long) the_geom_meter (string) name (string) address (string) city(string) state(string) country(string) fax (long)  zip (long) alcohol (string) smoking_area (string) dress_code (string) accessibility (string) price (string) url (string) Rambience (string) franchise (bool) area (string) other_services (string)
	vector<string> geoplaces2Types;
	vector<string> geoplaces2Attributes;
	geoplaces2Attributes.push_back("placeID");
	geoplaces2Types.push_back("long");
	geoplaces2Attributes.push_back("latitude");
	geoplaces2Types.push_back("long");
	geoplaces2Attributes.push_back("longitude");
	geoplaces2Types.push_back("long");
	geoplaces2Attributes.push_back("the_geom_meter");
	geoplaces2Types.push_back("string");
	geoplaces2Attributes.push_back("address");
	geoplaces2Types.push_back("string");
	geoplaces2Attributes.push_back("city");
	geoplaces2Types.push_back("string");
	geoplaces2Attributes.push_back("state");
	geoplaces2Types.push_back("string");
	geoplaces2Attributes.push_back("country");
	geoplaces2Types.push_back("string");
	geoplaces2Attributes.push_back("fax");
	geoplaces2Types.push_back("string");
	geoplaces2Attributes.push_back("zip");
	geoplaces2Types.push_back("float");
	geoplaces2Attributes.push_back("alcohol");
	geoplaces2Types.push_back("string");
	geoplaces2Attributes.push_back("smoking_area");
	geoplaces2Types.push_back("string");
	geoplaces2Attributes.push_back("dress_code");
	geoplaces2Types.push_back("string");
	geoplaces2Attributes.push_back("accessibility");
	geoplaces2Types.push_back("string");
	geoplaces2Attributes.push_back("price");
	geoplaces2Types.push_back("string");
	geoplaces2Attributes.push_back("url");
	geoplaces2Types.push_back("string");
	geoplaces2Attributes.push_back("Rambience");
	geoplaces2Types.push_back("string");
	geoplaces2Attributes.push_back("franchise");
	geoplaces2Types.push_back("bool");
	geoplaces2Attributes.push_back("area");
	geoplaces2Types.push_back("string");
	geoplaces2Attributes.push_back("other_services");
	geoplaces2Types.push_back("string");


	"../RCdata/rating_final.txt"
	userID (string) placeID(long) rating (int) food_rating (int) service_rating (int)
	vector<string> rating_finalAttributes;
	vector<string> rating_finalTypes;
	rating_finalAttributes.push_back("userID");
	rating_finalTypes.push_back("string");
	rating_finalAttributes.push_back("placeID");
	rating_finalTypes.push_back("long");
	rating_finalAttributes.push_back("rating");
	rating_finalTypes.push_back("int");
	rating_finalAttributes.push_back("food_rating");
	rating_finalTypes.push_back("int");
	rating_finalAttributes.push_back("service_rating");
	rating_finalTypes.push_back("int");

	"../RCdata/usercuisine.txt"
	userID (string) Rcuisine (string)
	vector<string> usercuisineAttributes;
	vector<string> usercuisineTypes;
	usercuisineAttributes.push_back("userID");
	usercuisineTypes.push_back("string");
	usercuisineAttributes.push_back("Rcuisine");
	usercuisineTypes.push_back("string");

	"../RCdata/chefmozaccepts.txt"
	placeID (long) Rpayment (string)
	vector<string> chefmozacceptsAttributes;
	vector<string> chefmozacceptsTypes;
	chefmozacceptsAttributes.push_back("placeID");
	chefmozacceptsTypes.push_back("long");
	chefmozacceptsAttributes.push_back("Rpayment");
	chefmozacceptsTypes.push_back("string");

	"../RCdata/chefmozcuizine.txt"
	placeID (long) Rcuisine (string)
	vector<string> chefmozcuizineAttributes;
	vector<string> chefmozcuizineTypes;
	chefmozcuizineAttributes.push_back("placeID");
	chefmozcuizineTypes.push_back("long");
	chefmozcuizineAttributes.push_back("Rcuisine");
	chefmozcuizineTypes.push_back("string");

	*/
	Table::ColumnList columns;

	for(std::vector<Table::RecordType>::iterator it = types.begin(); it != types.end(); ++it){
		columns.push_back(make_pair(attributes.at(std::distance(types.begin(), it)), *it));
	}
	// According to API, table must be made with new as the destructor is handled in implementation
	Table* currentTable = new Table(columns);
	//Insert table keys with attribute name vector
	//currentTable->set_key(attributes);
	ifstream File(path);
	string line;
	bool switchb=false;
	if(File)
	{
		while(getline(File,line))
		{
			if (switchb!=false){
				//reading line
				vector<string> propVect;

				std::istringstream ss(line);
				std::string token;
				int i = 0;
				vector<pair<string, string>> pears;
				while(std::getline(ss, token, ',')) {
					if (i < attributes.size()){
						pair<string, string> pear (attributes.at(i), token); 
						pears.push_back(pear);
					}
					i++;
				}
				Record pearRecord (pears);
				currentTable->insert(pearRecord);
				//vector filled with csv data
			} else { switchb=true;}
		}
		File.close();
	}
	//Inserts the "working" table into the mainDB
	string shortpath = path.substr(path.find_last_of('/')+1);
	shortpath = shortpath.substr(0, shortpath.length()-4);
	inputDB.add_table(shortpath, currentTable);

}


void printTable(Table workBench, Database &db){
	for( Table::TableIterator tabit = workBench.begin(); tabit != workBench.end(); ++tabit) {
		for( Record::RecordIterator recit = tabit->begin(); recit != tabit->end(); ++recit) {
			/* std::cout << *it; ... */
			pair<string, string> recvalue = *recit;
			cout<<" ("<<recvalue.first<<") '"<<recvalue.second<<"'\n";
		}
	}
}

void printUserSimple(string username, Database &db){
	Table* query_table = db.query("*", "userprofile", "userID = '" + username + "'");
	printTable(*query_table, db);	
	std::system("pause");

}
void printUserAdvanced(string username, Database &db){

}
string lookupUser(Database &db){
	//returns username
	string uID;
	std::system("CLS");
	cout << "Input the user ID you would like to view:\n";
	cin >> uID;
	printUserSimple(uID, db);
	//    printUser(uID);
	return uID;

}
string lookupRes(Database &db){
	//returns resname
	string resID;
	std::system("CLS");
	cout << "Input the restaurant ID you would like to view:\n";
	cin >> resID;
	// printUser(resID);
	return resID;
}
string lookupUserAttr(Database &db){
	//returns username
	string uID;
	std::system("CLS");
	cout << "Input the user ID you would like to view:\n";
	cin >> uID;
	//  printUser(uID);
	return uID;
}
string lookupResAttr(Database &db){
	//returns resname
	string resID;
	std::system("CLS");
	cout << "Input the restaurant ID you would like to view:\n";
	cin >> resID;
	//    printRes(resID);
	return resID;
}


int _tmain(int argc, _TCHAR* argv[]) {
	vector<vector<string>> allAttributes = generateAttributes();
	vector<vector<Table::RecordType>> allTypes = generateTypes();
	vector<string> allPaths = generatePaths();
	Database mainDB = Database();
	cout<<"Adding tables to database: \n";
	for(std::vector<string>::iterator it = allPaths.begin(); it != allPaths.end(); ++it) {
		int index = it - allPaths.begin();
		readIn(allPaths.at(index), allTypes.at(index), allAttributes.at(index), mainDB);
		vector<string> tablenames = mainDB.table_names();
		cout<<"\tadded `"<<tablenames.at(index)<<"` with "<< mainDB.table(tablenames.at(index))->size()<<" entries\n";
	}
	cout<<"Files successfully added to database\n";

	//query example	
	Table* query_table1 = mainDB.query("*", "chefmozaccepts", "placeID >= '133000'");
	Record query_table1_rec = query_table1->at(0);
	cout << "Size: "<< query_table1->size() <<"\n";
	cout << "Column Size: " << query_table1->count("placeID") << "\n";
	cout << "Entry: " << query_table1_rec.get<string>("Rpayment") << "\n";

	//menu


	bool mainMenu = true;
	string mode = "main";
	while (mainMenu){
		std::system("CLS"); 
		string option;
		if (mode == "main"){
			cout<<"Select an item from the menu or type '0' to quit.\n";

			cout << "OPTION 1: Look up by User ID\n";
			cout << "OPTION 2: Look up by Restaurant ID\n";
			cout << "OPTION 3: Look up User by Attributes\n";
			cout << "OPTION 4: Look up Location by ID\n";
			cin>>option;
			switch (atoi(option.c_str())){

			case 0:
				mainMenu=false;
				break;
			case 1:
				//run a function thatse &db) -> string (userid)
				//lookupUser(mainDB); returns user with query?
				lookupUser(mainDB);
				break;
			case 2:
				//run a function that returns user with query?
				//run lookupUser(database &db)
				lookupRes(mainDB);
				break;
			case 3:
				lookupUserAttr(mainDB);
				break;
			case 4:
				lookupResAttr(mainDB);
				break;

			default:
				cout<<"Unexpected input\n";
				break;

			}
		} else if (mode == "user"){
			//display options
			cin>>option;


		} else if (mode == "res"){
			//display options
			cin>>option;
		}
	}





	std::system("pause");
	return 0;
}


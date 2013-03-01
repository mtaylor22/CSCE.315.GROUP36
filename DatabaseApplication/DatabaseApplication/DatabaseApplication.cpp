// DatabaseApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "database.h"
#include <iomanip>



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
	geoplaces2Attributes.push_back("name");
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
	//vector of everything except actual key
	vector<string> j;
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
				unsigned i = 0;
				vector<pair<string, string>> pears;
				while(std::getline(ss, token, ',')) {
					if (i <  attributes.size()){
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
string getResID(string resname, Database &db){
	Table* query_table = db.query("*", "geoplaces2", "name = '" + resname + "'"); 
	string resID = query_table->at(0).get<string>("placeID");
	return resID;
}
string getResName(string resname, Database &db){
	Table* query_table = db.query("*", "geoplaces2", "placeID = '" + resname + "'"); 
	string resID = query_table->at(0).get<string>("name");
	return resID;
}
void printTable(Table workBench, Database &db){
	for( Table::TableIterator tabit = workBench.begin(); tabit != workBench.end(); ++tabit) {
		for( Record::RecordIterator recit = tabit->begin(); recit != tabit->end(); ++recit) {
			/* std::cout << *it; ... */
			pair<string, string> recvalue = *recit;
			//cout<<" ("<<recvalue.first<<") '"<<recvalue.second<<"'\n";
			cout << '|' << setw(25) << recvalue.first << '|';
			cout<< setw(51) << recvalue.second << '|' << endl;
		}
	}
}
void printUserSimple(string username, Database &db){
	Table* query_table = db.query("*", "userprofile", "userID = '" + username + "'");
	query_table->del_column("userID");
	printTable(*query_table, db);	
	std::system("pause");

}
void printUserAdvanced(string username, Database &db){
	cout<<"General user information: \n";
	Table* query_table1 = db.query("*", "userprofile", "userID = '" + username + "'");
	query_table1->del_column("userID");
	printTable(*query_table1, db);	
	cout<<"User payment information: \n";	
	Table* query_table2 = db.query("*", "userpayment", "userID = '" + username + "'");
	query_table2->del_column("userID");
	printTable(*query_table2, db);	
	cout<<"User cuisine information: \n";	
	Table* query_table3 = db.query("*", "usercuisine", "userID = '" + username + "'");
	query_table3->del_column("userID");
	printTable(*query_table3, db);	
	cout<<"User rating information: \n";	
	Table* query_table4 = db.query("*", "rating_final", "userID = '" + username + "'");
	query_table4->del_column("userID");
	printTable(*query_table4, db);	
	std::system("pause");
}
void printResSimple(string resname, Database &db){
	cout<<"General information on "<<resname<<"\n";
	Table* query_tableRes = db.query("*", "geoplaces2", "placeID = " + getResID(resname, db) ); 
	query_tableRes->del_column("placeID");
	printTable(*query_tableRes, db);
	std::system("pause");
};
void printResAdvanced(string resname, Database &db){
	cout<<"General information on "<<resname<<"\n";
	Table* query_table1 = db.query("*", "geoplaces2", "placeID = '" + getResID(resname, db) + "'"); 
	query_table1->del_column("placeID");
	printTable(*query_table1, db);
	cout<<"Cuisine served at "<<resname<<"\n";
	Table* query_table2 = db.query("*", "chefmozcuisine", "placeID = '" +  getResID(resname, db) + "'"); 
	query_table2->del_column("placeID");
	printTable(*query_table2, db);		
	cout<<resname<<" accepts:\n";
	Table* query_table3 = db.query("*", "chefmozaccepts", "placeID = '" +  getResID(resname, db) + "'"); 
	query_table3->del_column("placeID");
	printTable(*query_table3, db);		
	cout<<"Hours for "<<resname<<"\n";
	Table* query_table4 = db.query("*", "chefmozhours4", "placeID = '" +  getResID(resname, db) + "'"); 
	query_table4->del_column("placeID");
	printTable(*query_table4, db);	
	cout<<"Parking information on "<<resname<<"\n";
	Table* query_table5 = db.query("*", "chefmozparking", "placeID = '" +  getResID(resname, db) + "'"); 
	query_table5->del_column("placeID");
	printTable(*query_table5, db);
	cout<<"Ratings for "<<resname<<"\n";
	Table* query_table6 = db.query("*", "rating_final", "placeID = '" +  getResID(resname, db) + "'"); 
	query_table6->del_column("placeID");
	printTable(*query_table6, db);
	std::system("pause");
};
void printResSimpleID(string resname, Database &db){
	cout<<"General information on "<<resname<<"\n";
	Table* query_tableRes = db.query("*", "geoplaces2", "placeID = '" + resname + "'"); 
	query_tableRes->del_column("placeID");
	printTable(*query_tableRes, db);
	std::system("pause");
};
void printResAdvancedID(string resname, Database &db){
	cout<<"General information on "<<resname<<"\n";
	Table* query_table1 = db.query("*", "geoplaces2", "placeID = '" + resname+ "'"); 
	query_table1->del_column("placeID");
	printTable(*query_table1, db);
	cout<<"Cuisine served at "<<resname<<"\n";
	Table* query_table2 = db.query("*", "chefmozcuisine", "placeID = '" +  resname + "'"); 
	query_table2->del_column("placeID");
	printTable(*query_table2, db);		
	cout<<resname<<" accepts:\n";
	Table* query_table3 = db.query("*", "chefmozaccepts", "placeID = '" +  resname + "'"); 
	query_table3->del_column("placeID");
	printTable(*query_table3, db);		
	cout<<"Hours for "<<resname<<"\n";
	Table* query_table4 = db.query("*", "chefmozhours4", "placeID = '" +  resname + "'"); 
	query_table4->del_column("placeID");
	printTable(*query_table4, db);	
	cout<<"Parking information on "<<resname<<"\n";
	Table* query_table5 = db.query("*", "chefmozparking", "placeID = '" +  resname + "'"); 
	query_table5->del_column("placeID");
	printTable(*query_table5, db);
	cout<<"Ratings for "<<resname<<"\n";
	Table* query_table6 = db.query("*", "rating_final", "placeID = '" +  resname + "'"); 
	query_table6->del_column("placeID");
	printTable(*query_table6, db);
	std::system("pause");
};
string lookupUser(Database &db){
	//returns username
	string uID;
	std::system("CLS");
	cout << "Input the user ID you would like to view:\n";
	cin >> uID;
	cout << "Enter 0 for simple information or 1 for advanced: \n";
	int simAdvSwitch;
	cin >> simAdvSwitch;
	switch (simAdvSwitch){
	case 0:
		printUserSimple(uID, db);
		break;
	case 1:
		printUserAdvanced(uID, db);
		break;
	default:
		cout<<"Invalid input\n";
		break;
	}
	//    printUser(uID);
	cout<<"Enter 1 if you would like to perform more operations on this user, anything else to return\n";
	cin >> simAdvSwitch;
	switch (simAdvSwitch){
	case 1:
		return uID;
	default:
		return "";
	}

}
string lookupRes(Database &db){
	//returns resname
	std::string resName;
	std::system("CLS");
	cout << "Input the Restaurant name you would like to view:\n";
	std::getline(cin, resName);
	std::getline(cin, resName);
	cout << "Enter 0 for simple information or 1 for advanced: \n";
	int simAdvSwitch;
	cin >> simAdvSwitch;
	switch (simAdvSwitch){
	case 0:
		printResSimple(resName, db);
		break;
	case 1:
		printResAdvanced(resName, db);
		break;
	default:
		cout<<"Invalid input\n";
		break;
	}
	cout<<"Enter 1 if you would like to perform more operations on this restaurant, anything else to return\n";
	cin >> simAdvSwitch;
	switch (simAdvSwitch){
	case 1:
		return resName;
	default:
		return "";
	}
}
string lookupResID(Database &db){
	//returns resname
	std::string resName;
	std::system("CLS");
	cout << "Input the Restaurant ID you would like to view:\n";
	std::getline(cin, resName);
	std::getline(cin, resName);
	cout << "Enter 0 for simple information or 1 for advanced: \n";
	int simAdvSwitch;
	cin >> simAdvSwitch;
	switch (simAdvSwitch){
	case 0:
		printResSimpleID(resName, db);
		break;
	case 1:
		printResAdvancedID(resName, db);
		break;
	default:
		cout<<"Invalid input\n";
		break;
	}
	cout<<"Enter 1 if you would like to perform more operations on this restaurant, anything else to return\n";
	cin >> simAdvSwitch;
	switch (simAdvSwitch){
	case 1:
		return resName;
	default:
		return "";
	}
}
void findUserPayment(string username, Database &db){
	Table* query_table = db.query("*", "userpayment", "userID = '" + username + "'");
	cout<<"The user prefers to pay with "<<query_table->at(0).get<string>("Upayment")<<"\n";
	std::system("pause");
}
void findUserCuisine(string username, Database &db){
	Table* query_table = db.query("*", "usercuisine", "userID = '" + username + "'");
	cout<<"The user prefers to eat "<<query_table->at(0).get<string>("Rcuisine")<<" cuisine\n";
	std::system("pause");
}
void findUserRating(string username, Database &db){
	Table* query_table = db.query("*", "rating_final", "userID = '" + username + "'");
	cout<<"The average overall rating that this user gives is "<<((float)(query_table->sum<int>("rating"))/query_table->count("rating"))<<"\n";
	cout<<"The average food rating that this user gives is "<<((float)(query_table->sum<int>("food_rating"))/query_table->count("food_rating"))<<"\n";
	cout<<"The average service rating that this user gives is "<<((float)(query_table->sum<int>("service_rating"))/query_table->count("service_rating"))<<"\n";
	std::system("pause");
}
void findHighestRated(Database &db){
	string j = db.table("rating_final")->max<string>("rating");
	Table* query_table = db.query("*", "rating_final", "rating = '"+j+"'");
	cout<<"The highest rated restaurant is "<<getResName(query_table->at(0).get<string>("placeID"), db)<<"\n";
	std::system("pause");
}
void findLowestRated(Database &db){
	string j = db.table("rating_final")->min<string>("rating");
	Table* query_table = db.query("*", "rating_final", "rating = '"+j+"'");
	cout<<"The lowest rated restaurant is "<<getResName(query_table->at(0).get<string>("placeID"), db)<<"\n";
	std::system("pause");
}
void findSmoking(Database &db){
	Table* query_table = db.query("name", "geoplaces2", "smoking_area != 'none'");
	cout<<"Smoking restuarants: \n";
	printTable(*query_table, db);
	std::system("pause");
}
void findByCity(Database &db){
	std::string cityName;
	std::system("CLS");
	cout << "Input the city name you would like to view:\n";
	std::getline(cin, cityName);
	std::getline(cin, cityName);
	Table* query_table = db.query("name", "geoplaces2", "city = '"+cityName+"'");
	cout<<cityName<<" restuarants: \n";
	printTable(*query_table, db);
	std::system("pause");

}
void findByPayment(Database &db){
	std::string payName;
	std::system("CLS");
	cout << "Input the payment you would like to use:\n";
	std::getline(cin, payName);
	std::getline(cin, payName);
	Table* query_table = db.query("*", "chefmozaccepts", "Rpayment = '"+payName+"'");
	query_table->del_column("Rpayment");
	cout<<"Your payment method is supported by the following restaurants:\n";
	printTable(*query_table, db);
	std::system("pause");
}
void findResPriceRange(string resname, Database &db){
	string range;
	cout<<"Enter price range(low, medium, high)\n";
	cin>>range;
	Table* query_table = db.query("name", "geoplaces2", "price = '" + range + "'");
	printTable(*query_table, db);
	std::system("pause");
}
void findResAccess(string resname, Database &db){
	string access;
	cout<<"Enter accessibility options(no_accessibility, partially, completely)\n";
	cin>>access;
	Table* query_table = db.query("name", "geoplaces2", "accessibility = '" + access + "'");
	printTable(*query_table, db);
	std::system("pause");
}
void findDressCode(string resname, Database &db){
	string dress;
	cout<<"Enter dress code options(casual, informal, formal)\n";
	cin>>dress;
	Table* query_table = db.query("name", "geoplaces2", "dress_code = '" + dress + "'");
	printTable(*query_table, db);
	std::system("pause");
}
void findParking(string resname, Database &db){
	string parking;
	cout<<"Enter parking options(none, public, yes, 'valet parking')\n";
	cin>>parking;
	Table* query_table = db.query("placeID", "chefmozparking", "parking_lot = '" + parking + "'");
	printTable(*query_table, db);
	std::system("pause");
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

	bool mainMenu = true;
	string mode = "main";
	string lastUser;
	string lastRes;
	while (mainMenu){
		std::system("CLS"); 
		string option;
		if (mode == "main"){
			cout<<"Select an item from the menu or type '0' to quit.\n";

			cout << "OPTION 1: Look up by User ID\n";
			cout << "OPTION 2: Look up by Restaurant name\n";
			cout << "OPTION 3: Look up by Restaurant ID\n";
			cout << "OPTION 4: Perform Restaurant operations\n";
			cin>>option;
			switch (atoi(option.c_str())){

			case 0:
				mainMenu=false;
				break;
			case 1:
				lastUser = lookupUser(mainDB);
				if (lastUser != ""){
					mode="user";
				}
				break;
			case 2:
				lastRes = lookupRes(mainDB);
				if (lastRes != ""){
					mode="res";
				}
				break;
			case 3:
				lastRes = lookupResID(mainDB);
				if (lastRes != ""){
					mode="res";
				}
				break;
			case 4:
				mode="res";
				break;

			default:
				cout<<"Unexpected input\n";
				std::system("pause");
				break;

			}
		} else if (mode == "user"){
			//display options
			cout<<"Selection an item for '"<<lastUser<<"' or type '0' to return to the main menu\n";
			cout << "OPTION 1: Find user's payment method\n";
			cout << "OPTION 2: Find user's preferred cuisine\n";
			cout << "OPTION 3: Find user rating information\n";
			cin>>option;
			switch (atoi(option.c_str())){
			case 0:
				mode="main";
				break;
			case 1:
				findUserPayment(lastUser, mainDB);
				break;
			case 2:
				findUserCuisine(lastUser, mainDB);
				break;
			case 3:
				findUserRating(lastUser, mainDB);
				break;
			default:
				cout<<"Unexpected input\n";
				std::system("pause");
				break;

			}


		} else if (mode == "res"){
			//display options
			cout<<"Selection an item for '"<<lastUser<<"' or type '0' to return to the main menu\n";
			cout << "OPTION 1: Find highest rated restaurant\n";
			cout << "OPTION 2: Find lowest rated restaurant\n";
			cout << "OPTION 3: Smoking restaurants \n";
			cout << "OPTION 4: Find restaurants  by city\n";
			cout << "OPTION 5: Find restaurants  by payment type\n";
			cout << "OPTION 6: Find restaurants  with parking\n";
			cout << "OPTION 7: Find informal restaurants \n";
			cout << "OPTION 8: Find accessable restaurants \n";
			cout << "OPTION 9: Find restaurants  by price range\n";
			cin>>option;
			switch (atoi(option.c_str())){
			case 1:
				findHighestRated(mainDB);
				break;
			case 2:
				findLowestRated(mainDB);
				break;
			case 3:
				findSmoking(mainDB);
				break;
			case 4:
				findByCity(mainDB);
				break;
			case 5:
				findByPayment(mainDB);
				break;
			case 9:
				findResPriceRange(lastRes, mainDB);
				break;
			case 8:
				findResAccess(lastRes, mainDB);
				break;
			case 7:
				findDressCode(lastRes, mainDB);
				break;
			case 6:
				findParking(lastRes, mainDB);
				break;
			case 0:
				mode="main";
				break;

			default:
				cout<<"Unexpected input\n";
				std::system("pause");
				break;

			}
		}
	}

	return 0;
}


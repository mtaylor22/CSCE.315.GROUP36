#ifdef DATABASE_EXPORTS
#define DBDLL_API __declspec(dllexport) 
#else
#define DBDLL_API __declspec(dllimport) 
#endif
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <vector>

namespace DatabaseAPI {
bool keyChar(char);
int getParen(std::string);
std::string removeParens(std::string);
std::string readToken(std::string );
std::vector<std::string> buildStrVec(std::string );
std::string remSpaces(std::string );
std::vector< std::vector<Proposition>> generateProps(std::vector<std::string> );
std::vector< std::vector< std::string > > generatecVec(std::vector<std::string> );
void pVecPrintout(std::vector< std::vector< Proposition > >);
void cVecPrintout(std::vector< std::vector< std::string > >);
class DBDLL_API Record {
	std::vector<std::string> recordData;
public:	
	Record();
	Record (int);
	std::string accessRecord (int);
	int modifyRecord (int, std::string);
	bool operator== (const Record& other) const {
		if (this->recordData == other.recordData){
			return true;
		} else {
			return false;
		}
	}
};

class DBDLL_API Attribute {
	
	//added late 
	public:
	Attribute(std::string, std::string);
	std::string attributeName;
	std::string attributeType;
	 bool operator== (const Attribute& other) const {
	 // return true if *this == other, otherwise return false
		 if (this->attributeName == other.attributeName && this->attributeType == other.attributeType){
			return true;
		 }else {
			 return false;
		 }
	}
};
	
class DBDLL_API Table {
	std::string tableName;
	std::vector<Record> recordVec;
	std::vector<Attribute> attributeVec;

public:
	Table ();
	Table (std::vector<Attribute>);
	int addAttribute (Attribute);
	int delAttribute (std::string);
	int insertRecord (Record);
	std::vector<Attribute> getAttributes ();
	int getSize ();
	int renameAttribute (std::string, std::string);
	static Table crossJoin (Table, Table);
	float sumAttribute (std::string);
	float countAttribute (std::string);
	float minAttribute (std::string );

	float maxAttribute (std::string);
	std::vector<Record>::iterator iterate;
	bool operator== (const Table& other) const {
	//to be equal, tables must have all the same records and all the same attributes
		return true;
	}
};

class DBDLL_API Database {
	std::vector<Table> tableVec;
	std::vector<std::string> tableNames;
public:
	Database ();
	int addTable (Table, std::string);
	int dropTable (std::string);
	std::vector<std::string> listTables ();
	std::vector<Table> getTables ();
	Table queryTable (std::vector<std::string>, std::string, std::string);
	int deleteTable (std::vector<std::string>, std::string, std::string);
};

class Proposition {
  public:
	Proposition(){
		connType="";
		propLeft=NULL;
		propRight=NULL;
		propNot=false;
		};
	Proposition(std::string propAttr, std::string propOp, std::string propVal, bool notVal){
		propAttribute=propAttr;
		propOperator=propOp;
		propValue=propVal;
		propNot = notVal;
		connType="";
		propLeft=NULL;
		propRight=NULL;
	};
	std::string propAttribute;
	std::string propOperator;
	std::string propValue;
	int height;
	bool propNot;
	bool evaluation;
	bool linked;
	std::string connType;
	Proposition* propLeft;
	Proposition* propRight;
	void printout(){
		if (connType == "prop"){
		std::cout<<"Printing: '"<< this->propAttribute<<"' '"<< this->propOperator<<"' '"<<this->propValue<<"' \n";
		} else {
		std::cout<<"Printing: '"<< this->connType<<"' LEFT:\n";
		if (propLeft != NULL) propLeft->printout();
		std::cout<<"RIGHT:\n";
		if (propRight != NULL) propRight->printout();
		
	}
		}
};








}
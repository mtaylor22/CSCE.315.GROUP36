#ifdef DATABASE_EXPORTS
#define DBDLL_API __declspec(dllexport) 
#else
#define DBDLL_API __declspec(dllimport) 
#endif
#include <stdio.h>
#include <string>
#include <iterator>
#include <vector>

namespace DatabaseAPI {
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

/* the following is necessary to implement query
connector and proposition can logically construct any "while" statement (in theory)
for example

((NOT Gender=female) AND (Age < 21))

would be something like

Connector head = Connector();
Proposition a = Proposition("Gender", "=", "Female", true);
Proposition b = Proposition("Age", "<", "21", true);
head.propLeft = a;
head.propRight = b;
head.connType="AND";


*/
class DBDLL_API Connector {
	Connector(){
		connType="";
		propLeft=NULL;
		propRight=NULL;
	};
	Connector(std::string connTy, Proposition* propL, Proposition* propR){
		connType = connTy;
		propLeft = propL;
		propRight = propR;
	}
	std::string connType;
	Proposition* propLeft;
	Proposition* propRight;
};
class DBDLL_API Proposition {
	Proposition(){};
	Proposition(std::string propAttr, std::string propOp, std::string propVal, bool not){
		propAttribute=propAttr;
		propOperator=propOp;
		propAttribute=propAttr;
		propValue=propVal;
		propNot = not;
	};
	std::string propAttribute;
	std::string propOperator;
	std::string propValue;
	bool propNot;
	bool evaluation;
};


}
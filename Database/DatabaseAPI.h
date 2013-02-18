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
};

class DBDLL_API Attribute {
	//added late 
	Attribute(std::string, std::string);
	std::string attributeName;
	std::string attributeType;
};
	
class DBDLL_API Table {
	std::string tableName;

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
	float minAttribute (std::string);
	float maxAttribute (std::string);
	std::vector<Record>::iterator iterate;
};

class DBDLL_API Database {
public:
	Database ();
	int addTable (Table, std::string);
	int dropTable (std::string);
	std::vector<std::string> listTables ();
	std::vector<Table> getTables ();
	Table queryTable (std::vector<std::string>, std::string, std::string);
	int deleteTable (std::vector<std::string>, std::string, std::string);
};

}

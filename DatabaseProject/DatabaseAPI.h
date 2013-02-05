#ifdef DATABASEPROJECT_EXPORTS
#define DBDLL_API __declspec(dllexport) 
#else
#define DBDLL_API __declspec(dllimport) 
#endif
#include <stdio.h>
#include <string>
#include <iterator>
#include <vector>

namespace DatabaseAPI {

class Record {
	std::vector<std::string> recordData;
public:	
	Record (int);
	std::string accessRecord (int);
	int modifyRecord (int, std::string);
};

class Attribute {
	std::string attributeName;
	std::string attributeType;
};
	
class Table {
	std::string tableName;

public:
	Table ();
	Table (std::vector<Attribute>);
	int addAttribute (Attribute);
	int delAttribute (std::string);
	int insertAttribute (Record);
	std::vector<Attribute> getAttributes ();
	int getSize ();
	int renameAttribute (std::string, std::string);
	static Table crossJoin (Table, Table);
	int sumAttribute (std::string);
	int countAttribute (std::string);
	int minAttribute (std::string);
	int maxAttribute (std::string);
	std::vector<Record>::iterator iterate;
};

class Database {
public:
	Database ();
	int addTable (Table, std::string);
	int dropTable (std::string);
	std::vector<std::string> listTables ();
	std::vector<Table> getTables ();
	Table queryTable (std::vector<std::string>, std::string, std::string);
	Table deleteTable (std::vector<std::string>, std::string, std::string);
};

}

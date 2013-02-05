#include <stdio.h>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

class Database {
public:
	Database ();
	int addTable (Table, string);
	int dropTable (string);
	vector<string> listTables ();
	vector<Table> getTables ();
	//Query
	Table queryTable (
	//Delete
};

class Table {
	string tableName;

public:
	Table ();
	Table (vector<Attribute>);
	int addAttribute (Attribute);
	int delAttribute (string);
	int insertAttribute (Record);
	vector<Attribute> getAttributes ();
	int getSize ();
	int renameAttribute (string, string);
	static Table crossJoin (Table, Table);
	int sumAttribute (string);
	int countAttribute (string);
	int minAttribute (string);
	int maxAttribute (string);
	//Iterator

};

class Attribute {
	string attributeName;
	string attributeType;
};

class Record {
	vector<string> recordData;
public:	
	Record (int);
	string accessRecord (int);
	int modifyRecord (int, string);
	//Access to individual entry
	//Routine that retrives an entry in the record
};

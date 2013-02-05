#include "DatabaseAPI.h"
using namespace DatabaseAPI;

Record a();
Record b(int);
std::string accessRecord (int);
int modifyRecord (int, std::string);

Table c();
Table d(std::vector<Attribute>);
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

Database e();
int addTable (Table, std::string);
int dropTable (std::string);
std::vector<std::string> listTables ();
std::vector<Table> getTables ();
Table queryTable (std::vector<std::string>, std::string, std::string);
Table deleteTable (std::vector<std::string>, std::string, std::string);


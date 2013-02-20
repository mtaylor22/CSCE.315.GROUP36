#define BOOST_TEST_MODULE DatabaseTests
#include <boost/test/unit_test.hpp>

#include "../Database/DatabaseAPI.h"
using namespace DatabaseAPI;

BOOST_AUTO_TEST_CASE( AddTest )
{
	//------Tests for Record------
	
	Record r = Record();	//blank constructor is pointless
	Record r2 = Record(3);
	//check if the constructor gives an error when the argument is not an int.
	Record r3;
	Record r4 = Record(1.5);

	//test each record and see if they are created correctly
	BOOST_CHECK(r.modifyRecord(0,"") != 0);	//blank constructor should have no elements in it
	BOOST_CHECK(r2.accessRecord(0) == "");
	BOOST_CHECK(r2.accessRecord(1) == "");
	BOOST_CHECK(r2.accessRecord(2) == "");
	//check if r3 created something
	//r3 and r4 shouldnt create records because the input if not an int
	BOOST_CHECK(r3.modifyRecord(0,"") != 0);
//	BOOST_CHECK(r4.modifyRecord(0,"") != 0);

	//check if it modifies the records
	BOOST_CHECK(r2.modifyRecord(0, "Bob") == 0);	//I set the index starting at 0
	BOOST_CHECK(r2.modifyRecord(1, "Male") == 0);
	BOOST_CHECK(r2.modifyRecord(2, "21") == 0);
	//test if it gives an error if trying to modify a non-existing record
	BOOST_CHECK(r2.modifyRecord(3, "Smith") != 0);
	//test if the accessor returns the correct string
	BOOST_CHECK(r2.accessRecord(0) == "Bob");
	BOOST_CHECK(r2.accessRecord(1) == "Male");
	BOOST_CHECK(r2.accessRecord(2) == "21");
	//test if the accessor throws an error for accessing an index out of bounds
	BOOST_CHECK(r2.modifyRecord(3,"") != 0);
	//test if it modifies exising records
	BOOST_CHECK(r2.modifyRecord(0, "Jeny") == 0);
	BOOST_CHECK(r2.modifyRecord(1, "Female") == 0);
	BOOST_CHECK(r2.modifyRecord(2, "31") == 0);
	//test if the records have been modified correctly
	BOOST_CHECK(r2.accessRecord(0) == "Jeny");
	BOOST_CHECK(r2.accessRecord(1) == "Female");
	BOOST_CHECK(r2.accessRecord(2) == "31");
	//--------20
	//------Tests for Table------

	Table t= Table();
	// API does not have a constructor for class Attribute..
	
	std::vector<Attribute> v;
	v.push_back(Attribute("Name","string"));
	v.push_back(Attribute("Age","int"));
	v.push_back(Attribute("Gender","string"));
	Table t2=Table(v);

	r= Record(3);
	r.modifyRecord(0, "Bob");
	r.modifyRecord(1, "18");
	r.modifyRecord(2, "male");

	r2= Record(3);
	r2.modifyRecord(0, "Bill");
	r2.modifyRecord(1, "18");
	r2.modifyRecord(2, "male");

	r3= Record(3);
	r3.modifyRecord(0, "Mary");
	r3.modifyRecord(1, "21");
	r3.modifyRecord(2, "female");

	r4= Record(3);
	r4.modifyRecord(0, "Tom");
	r4.modifyRecord(1, "19");
	r4.modifyRecord(2, "male");

	BOOST_CHECK(t.getSize() == 0);

	// API does not have a constructor for class Attribute..
	
	BOOST_CHECK(t.addAttribute(Attribute("Hometown","string")) == 0);
	BOOST_CHECK(t.addAttribute(Attribute("Age","int")) == 0);
	BOOST_CHECK(t.addAttribute(Attribute("Name","string")) == 0);
	

	BOOST_CHECK(t.delAttribute("Name") == 0);

	// API does not have a constructor for class Attribute..
	BOOST_CHECK(t.addAttribute(Attribute("Name","string")) == 0);

	BOOST_CHECK(t.delAttribute("Age") == 0);

	// API does not have a constructor for class Attribute..
	BOOST_CHECK(t.addAttribute(Attribute("Age","int")) == 0);

	BOOST_CHECK(t.delAttribute("Hometown") == 0);

	// API does not have a constructor for class Attribute..
	BOOST_CHECK(t.addAttribute(Attribute("Hometown","string")) == 0);
	
	BOOST_CHECK(t.renameAttribute("Hometown","Gender") == 0);

	BOOST_CHECK(t.renameAttribute("Hometown","Height") != 0);

	BOOST_CHECK(t.getAttributes() == v);

	// This record is invalid because "male" is not an int
	Record invalid_record(3);
	invalid_record.modifyRecord(0, "Bob");
	invalid_record.modifyRecord(1, "male");
	invalid_record.modifyRecord(2, "18");

	BOOST_CHECK(t.insertRecord(invalid_record) != 0);
	BOOST_CHECK(t.insertRecord(r) == 0);
	BOOST_CHECK(t.getSize() == 1);

	BOOST_CHECK(t.insertRecord(r2) == 0);
	BOOST_CHECK(t.insertRecord(r3) == 0);
	BOOST_CHECK(t.insertRecord(r4) == 0);
	BOOST_CHECK(t.sumAttribute("Age") == 76);
	BOOST_CHECK(t.countAttribute("Age") == 4);
	BOOST_CHECK(t.maxAttribute("Age") == 21);
	BOOST_CHECK(t.minAttribute("Age") == 18);
	//-------23
	//------Tests for Database------

	Database d = Database();	//blank database constructor
	std::vector<Attribute> v1;
	//Attribute constructor not defined
	v1.push_back(Attribute("Name","string"));
	v1.push_back(Attribute("Age","int"));
	v1.push_back(Attribute("Gender","string")); //creates a vector in order to create a table

	Table t1 = Table(v1); //creates the table in order to add a table to the database
	std::vector<Attribute> v2;
	//Attribute constructor not defined
	v2.push_back(Attribute("LastName","string"));
	v2.push_back(Attribute("Age","float"));
	v2.push_back(Attribute("Date","string")); //creates a vector in order to create a table

	t2 = Table(v2);
	std::vector<std::string> v3;
	v3.push_back("Table 1");
	v3.push_back("Table 2");	//vector that holds the names of both tables created
	//insert records in order to check for the query function
	BOOST_CHECK(t1.insertRecord(r) == 0);
	BOOST_CHECK(t1.insertRecord(r2) == 0);
	BOOST_CHECK(t1.insertRecord(r3) == 0);
	BOOST_CHECK(t1.insertRecord(r4) == 0);
	
	std::vector<Table> v4;
	v4.push_back(t1);
	v4.push_back(t2);
	//insert records in order to check for the query function
	BOOST_CHECK(t1.insertRecord(r) == 0);
	BOOST_CHECK(t1.insertRecord(r2) == 0);
	BOOST_CHECK(t1.insertRecord(r3) == 0);
	BOOST_CHECK(t1.insertRecord(r4) == 0);
	
	BOOST_CHECK(d.addTable(t1, "Table 1") == 0);
	BOOST_CHECK(d.addTable(t2, "Table 2") == 0);
	BOOST_CHECK(d.listTables() == v3);	//check for a vector string of the table names
	BOOST_CHECK(d.dropTable("Table 2") == 0);	//check if it drops the table
	v3.pop_back();
	BOOST_CHECK(d.listTables() == v3);	//check if the remainder table is table 2
//	BOOST_CHECK(d.getTables() == v4);	//IDK if this is right


	//Testing query function
	std::vector<std::string> v5;
	Table t3 = Table();
	BOOST_CHECK(d.addTable(t, "Test Table") == 0);
	//Testing empty table
	BOOST_CHECK(d.queryTable(v5,"Test Table","Name=Ben").getAttributes() == t3.getAttributes() && 
		d.queryTable(v5,"Test Table","Name=Ben").getSize() == t3.getSize());

	t3 = Table(v1);
	t3.insertRecord(r);
	//Testing = of every Attribute name
	BOOST_CHECK(d.queryTable(v5,"Test Table","Name=Bob").getAttributes() == t3.getAttributes() && 
		d.queryTable(v5,"Test Table","Name=Bob").getSize() == t3.getSize());
	t3.insertRecord(r2);
	BOOST_CHECK(d.queryTable(v5,"Test Table","Age=18").getAttributes() == t3.getAttributes() && 
		d.queryTable(v5,"Test Table","Age=18").getSize() == t3.getSize());
	t3.insertRecord(r4);
	BOOST_CHECK(d.queryTable(v5,"Test Table","Gender=male").getAttributes() == t3.getAttributes() && 
		d.queryTable(v5,"Test Table","Gender=male").getSize() == t3.getSize());
	//Testing != < <=
	BOOST_CHECK(d.queryTable(v5,"Test Table","Name!=Mary").getAttributes() == t3.getAttributes() && 
		d.queryTable(v5,"Test Table","Name!=Mary").getSize() == t3.getSize());
	BOOST_CHECK(d.queryTable(v5,"Test Table","Age<21").getAttributes() == t3.getAttributes() && 
		d.queryTable(v5,"Test Table","Age<21").getSize() == t3.getSize());
	BOOST_CHECK(d.queryTable(v5,"Test Table","Age<=20").getAttributes() == t3.getAttributes() && 
		d.queryTable(v5,"Test Table","Age<=20").getSize() == t3.getSize());

	//Testing > >=
	t3=Table(v1);
	t3.insertRecord(r3);
	BOOST_CHECK(d.queryTable(v5,"Test Table","Age>20").getAttributes() == t3.getAttributes() && 
		d.queryTable(v5,"Test Table","Age>20").getSize() == t3.getSize());
	BOOST_CHECK(d.queryTable(v5,"Test Table","Age>=20").getAttributes() == t3.getAttributes() && 
		d.queryTable(v5,"Test Table","Age>=20").getSize() == t3.getSize());

	//Testing different select sizes
	v5.push_back("Name");
	std::vector<Attribute> vt;
	//vt.push_back(Attribute("Name","string"));
	Record rt = Record(1);
	rt.modifyRecord(1,"Mary");
	t3= Table(vt);
	t3.insertRecord(rt);
	BOOST_CHECK(d.queryTable(v5,"Test Table","Age>=20").getAttributes() == t3.getAttributes() && 
		d.queryTable(v5,"Test Table","Age>=20").getSize() == t3.getSize());
	v5.push_back("Age");
	//vt.push_back(Attribute("Age", "int"));
	rt = Record(2);
	rt.modifyRecord(1,"Mary");
	rt.modifyRecord(2,"21");
	t3= Table(vt);
	t3.insertRecord(rt);
	BOOST_CHECK(d.queryTable(v5,"Test Table","Age>=20").getAttributes() == t3.getAttributes() && 
		d.queryTable(v5,"Test Table","Age>=20").getSize() == t3.getSize());

	//Testing NOT AND OR
	v5.pop_back();
	v5.pop_back();
	t3= Table(v1);
	t3.insertRecord(r);
	BOOST_CHECK(d.queryTable(v5,"Test Table","Age=18 AND Name=Bob").getAttributes() == t3.getAttributes() && 
		d.queryTable(v5,"Test Table","Age=18 AND Name=Bob").getSize() == t3.getSize());
	t3.insertRecord(r2);
	BOOST_CHECK(d.queryTable(v5,"Test Table","Age=18 OR Name=Bob").getAttributes() == t3.getAttributes() && 
		d.queryTable(v5,"Test Table","Age=18 OR Name=Bob").getSize() == t3.getSize());
	t3.insertRecord(r4);
	BOOST_CHECK(d.queryTable(v5,"Test Table","NOT Gender=female").getAttributes() == t3.getAttributes() && 
		d.queryTable(v5,"Test Table","NOT Gender=female").getSize() == t3.getSize());
	//Testing parenthesis
	BOOST_CHECK(d.queryTable(v5,"Test Table","(NOT Gender=female) AND Age < 21").getAttributes() == t3.getAttributes() && 
		d.queryTable(v5,"Test Table","(NOT Gender=female) AND Age < 21").getSize() == t3.getSize());
	BOOST_CHECK(d.queryTable(v5,"Test Table","(NOT Gender=female) AND (Age < 21)").getAttributes() == t3.getAttributes() && 
		d.queryTable(v5,"Test Table","(NOT Gender=female) AND (Age < 21)").getSize() == t3.getSize());
	BOOST_CHECK(d.queryTable(v5,"Test Table","((NOT Gender=female) AND (Age < 21))").getAttributes() == t3.getAttributes() && 
		d.queryTable(v5,"Test Table","((NOT Gender=female) AND (Age < 21))").getSize() == t3.getSize());

	//--------32
	//Delete function
	std::vector<std::string> v6;
	Table t4 = Table();
	BOOST_CHECK(d.addTable(t4, "Test Table2") == 0);
	t4.insertRecord(r);
	//the table contains Bob
	BOOST_CHECK(d.deleteTable(v6,"Test Table2","Name=Bob") == 0);
	t4.insertRecord(r);	//add record for Bob
	t4.insertRecord(r2);	//add record for Bill
	BOOST_CHECK(d.deleteTable(v6,"Test Table2","Age=18") == 0);	//this should delete both Bob and Bill's record
	t4.insertRecord(r);	//add record for Bob
	t4.insertRecord(r2);	//add record for Bill
	t4.insertRecord(r3);	//adds records for Tom
	t4.insertRecord(r4);	//adds records for Mary
	BOOST_CHECK(d.deleteTable(v6,"Test Table2","Gender=male") == 0);	//this also deletes all 3 records except for Marys
	BOOST_CHECK(t4.getSize() == 1);	//to check that only 1 record remains
	t4.insertRecord(r);	//add record for Bob
	t4.insertRecord(r2);	//add record for Bill
	t4.insertRecord(r3);	//adds records for Tom
	BOOST_CHECK(d.deleteTable(v6,"Test Table2","Name!= Bob") == 0);	//deletes all records that are not Bob
	BOOST_CHECK(t4.getSize() == 1);	//to check that only 1 record remains, Bobs record
	t4.insertRecord(r2);	//add record for Bill
	t4.insertRecord(r3);	//adds records for Tom
	t4.insertRecord(r4);	//adds records for Mary
	BOOST_CHECK(d.deleteTable(v6,"Test Table2","Age<21") == 0); //deletes the records of Bob, Bill, and Tom
	BOOST_CHECK(t4.getSize() == 1);	//to check that only 1 record remains, Marys record
	t4.insertRecord(r);	//add record for Bob
	t4.insertRecord(r2);	//add record for Bill
	t4.insertRecord(r3);	//adds records for Tom
	BOOST_CHECK(d.deleteTable(v6,"Test Table2","Age<=19") == t3.getSize()); //deletes all but Marys records
	BOOST_CHECK(t4.getSize() == 1);	//to check that only 1 record remains, Marys record
	t4.insertRecord(r);	//add record for Bob
	t4.insertRecord(r2);	//add record for Bill
	t4.insertRecord(r3);	//adds records for Tom
	BOOST_CHECK(d.deleteTable(v6,"Test Table2","Age>20") == 0); //deletes just Marys records
	BOOST_CHECK(t4.getSize() == 3);	//to check that only 1 record was deleted
	t4.insertRecord(r4);	//adds records for Mary
	BOOST_CHECK(d.deleteTable(v6,"Test Table2","Age>=19") == 0);	//Mary and Tom records should be deleted
	BOOST_CHECK(t4.getSize() == 2);	//to check that only 2 record were deleted
	t4.insertRecord(r3);	//adds records for Tom
	t4.insertRecord(r4);	//adds records for Mary
	
	//Testing NOT AND OR
	BOOST_CHECK(d.deleteTable(v6,"Test Table2","Age=18 AND Name=Bob") == 0);	//deletes only Bobs records
	BOOST_CHECK(t4.getSize() == 3);	//to check that only 1 record was deleted
	t4.insertRecord(r);	//add record for Bob
	
	BOOST_CHECK(d.deleteTable(v6,"Test Table2","Age=18 OR Name=Bob") == 0);	//deletes Bob and Bill records
	BOOST_CHECK(t4.getSize() == 2);	//to check that only 2 record was deleted
	t4.insertRecord(r);	//add record for Bob
	t4.insertRecord(r2);	//add record for Bill
	
	BOOST_CHECK(d.deleteTable(v6,"Test Table2","NOT Gender=male") == 0);	//deletes only Marys records
	BOOST_CHECK(t4.getSize() == 3);	//to check that only 1 record was deleted
	t4.insertRecord(r4);	//adds records for Mary
	
	//Testing parenthesis
	BOOST_CHECK(d.deleteTable(v6,"Test Table2","(NOT Gender=female) AND Age < 19") == 0);	//deletes records for Bob and Bill
	BOOST_CHECK(t4.getSize() == 2);	//to check that only 2 record was deleted
	t4.insertRecord(r);	//add record for Bob
	t4.insertRecord(r2);	//add record for Bill
	
	BOOST_CHECK(d.deleteTable(v6,"Test Table2","(NOT Gender=male) OR (Age <= 18)") == 0);	//deletes Mary, Bob, and Bill records
	BOOST_CHECK(t4.getSize() == 1);	//to check that only 1 record remains
	t4.insertRecord(r);	//add record for Bob
	t4.insertRecord(r2);	//add record for Bill
	t4.insertRecord(r4);	//adds records for Mary
	
	BOOST_CHECK(d.deleteTable(v6,"Test Table2","((NOT Gender=female) AND (NOT Age = 18))") == 0);	//deletes Tom records
	BOOST_CHECK(t4.getSize() == 3);	//to check that only Tom records were deleted
	
	}

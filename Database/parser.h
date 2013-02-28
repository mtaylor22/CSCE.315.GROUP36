#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
class Proposition {
  public:
	Proposition(){
		evaluation=NULL;
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
		evaluation=NULL;
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
		std::cout<<"Printing: '"<< this->propAttribute<<"' '"<< this->propOperator<<"' '"<<this->propValue<<"' t: "<<this->evaluation<<" \n";
		} else {
		std::cout<<"Printing: '"<< this->connType<<"' LEFT:\n";
		if (propLeft != NULL) propLeft->printout();
		std::cout<<"RIGHT:\n";
		if (propRight != NULL) propRight->printout();
		
	}
		}
};

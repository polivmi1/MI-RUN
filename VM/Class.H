#ifndef CLASS_HEADER
#define CLASS_HEADER

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>

#include "Function.H"

class Class{
	private:
		std::string name;
		Class * parent;
		std::map<std::string, Function * > functions;
		std::map<std::string, int > members;	//int is the position in InstanceClass to the field, where is kept reference
		//NEW sets all members to instance of INT(0)
	public:
		Class(std::string name, Class * parent){
			this->name = name;
			this->parent = parent;
		}		
		std::string getName();
		Class * getParent();
		void addFunction(Function * f);
		void addMember(std::string name);
		int getMember(std::string name);
		Function * getFunction(std::string name);
};


#endif

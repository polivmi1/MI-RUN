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
	public:
		Class(std::string name, Class * parent){
			this->name = name;
			this->parent = parent;
		}		
		std::string getName();
		Class * getParent();
		void addFunction(Function * f);
		Function * getFunction(std::string name);
};


#endif

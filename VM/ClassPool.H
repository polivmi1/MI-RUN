#ifndef CLASSPOOL_HEADER
#define CLASSPOOL_HEADER

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>

#include "Class.H"

class ClassPool{
	private:
		std::map<std::string, Class *> members;
	public:
		Class * getClass(const std::string &name);
		void addClass(Class * c);
};


#endif

#ifndef CONSTANTPOOL_HEADER
#define CONSTANTPOOL_HEADER

#include <iostream>

#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>


class ConstantPool{
	private:
		std::map<int, std::string> constants;
	public:
		std::string getConstant(int);
		void addConstant(int, std::string);
};

#endif

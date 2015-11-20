#ifndef FUNCTION_HEADER
#define FUNCTION_HEADER

#include <iostream>

#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>


class Function{
	private:
		std::string name;
		int c_parameters;
		std::vector<char> bc;
	public:
		Function(std::string name, int c_parameters, std::vector<char> bc){
			this->name = name;
			this->c_parameters = c_parameters;
			this->bc = bc;
		}		
		std::string getName();
		char getBC(int pos);
		int getIntBC(int pos);
		int getNumParameters();
};


#endif

#ifndef FRAME_HEADER
#define FRAME_HEADER

#include <iostream>

#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>

#include "Function.H"
#include "Class.H"


class Frame{
	private:
		int ebp;
		int eip;
		Function * frameFunction;
		Class * frameClass;
		std::vector<int> variables;		//references to heap
	public:
		Frame(int ebp, Function * frameFunction, Class * frameClass){
			this->ebp = ebp;
			this->frameFunction = frameFunction;
			this->frameClass = frameClass;
			this->eip = 0;
		}
		void addEIP(int num);
		int getEBP();
		int getEIP();
		int getVariable(int);
		Function * getFunction();
		Class * getClass();
		void setEBP(int);
		void setEIP(int);
		void setVariable(int, int);
};


#endif

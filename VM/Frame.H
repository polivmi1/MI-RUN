#ifndef FRAME_HEADER
#define FRAME_HEADER

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>
#include <stack>

#include "Function.H"
#include "Class.H"


class Frame{
	private:
		int ebp;
		int eip;
		Function * frameFunction;
		Class * frameClass;
		std::vector<int> variables;		//references to heap
		std::stack<int> v_catch;		//vector of catches
	public:
		Frame(int ebp, Function * frameFunction, Class * frameClass){
			this->ebp = ebp;
			this->frameFunction = frameFunction;
			this->frameClass = frameClass;
			this->eip = 0;
		}
		
		void addCatch(int addr){v_catch.push(addr);}
		int decCatch(){int a = v_catch.top(); v_catch.pop(); return a;}
		int sizeCatch(){return v_catch.size();}
		
		void addEIP(int num);
		int getEBP();
		int getEIP();
		int getVariable(int);
		Function * getFunction();
		Class * getClass();
		void setEBP(int);
		void setEIP(int);
		void setVariable(int, int);
		
		friend class GarbageCollector;
		
};


#endif
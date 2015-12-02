#ifndef CALLSTACK_HEADER
#define CALLSTACK_HEADER

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
#include <stdexcept>

#include "Frame.H"
#include "ClassPool.H"

class CallStack{
	private:
		std::vector<Frame *> execStack; 
		int stackSize; 
	public:
    CallStack() : stackSize(0) {}
		void addFrame(int ebp, std::string c_name, std::string f_name, ClassPool *classPool);
		int empty();
		Frame * top();
		Frame * pop();
		
		friend class GarbageCollector;
		
};


#endif

#ifndef DATASTACK_HEADER
#define DATASTACK_HEADER

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stack>
#include <stdexcept>


class DataStack{
	private:
		std::vector<int> dataStack; //references on heap
		int stackSize;
	public:
    DataStack() : stackSize(0) {}
		int size();
		int pop();
		void push(int a);
		//TODO
		
		friend class GarbageCollector;
		
};


#endif
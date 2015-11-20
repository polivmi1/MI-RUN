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
		std::stack<int> dataStack; //references on heap
	public:
		int size();
		int pop();
		void push(int a);
		//TODO
};


#endif

#ifndef INSTRUCTION_HEADER
#define INSTRUCTION_HEADER

#include <iostream>

#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>

#include "CallStack.H"
#include "DataStack.H"
#include "Heap.H"

class Instruction{
	protected:
		CallStack *callStack;
		DataStack * dataStack;
		Heap *heap;
	public:
		Instruction(CallStack *callStack, DataStack * dataStack, Heap * heap){
			this->callStack = callStack;
			this->dataStack = dataStack;
			this->heap = heap;
		}
		
		virtual void execute() = 0;
};

#endif

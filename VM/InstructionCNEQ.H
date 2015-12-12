#ifndef INSTRUCTIONCNEQ_HEADER
#define INSTRUCTIONCNEQ_HEADER

#include <iostream>

#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>

#include "Instruction.H"
#include "Instance.H"
#include "CallStack.H"
#include "DataStack.H"
#include "Heap.H"

class InstructionCNEQ : public Instruction{
	public:
		InstructionCNEQ(CallStack *callStack, DataStack * dataStack, Heap * heap) : Instruction(callStack, dataStack, heap){
			
		}
		
		void execute();
};

#endif

#ifndef INSTRUCTIONSTORE_HEADER
#define INSTRUCTIONSTORE_HEADER

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

class InstructionSTORE : public Instruction{
	public:
		InstructionSTORE(CallStack *callStack, DataStack * dataStack, Heap * heap) : Instruction(callStack, dataStack, heap){
			
		}
		
		void execute();
};

#endif

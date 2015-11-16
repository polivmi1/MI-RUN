#ifndef INSTRUCTIONCJMP_HEADER
#define INSTRUCTIONCJMP_HEADER

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

class InstructionCJMP : public Instruction{
	public:
		InstructionCJMP(CallStack *callStack, DataStack * dataStack, Heap * heap) : Instruction(callStack, dataStack, heap){
			
		}
		
		void execute();
};

#endif

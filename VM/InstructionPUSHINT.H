#ifndef INSTRUCTIONPUSHINT_HEADER
#define INSTRUCTIONPUSHINT_HEADER

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
#include "InstanceINT.H"

class InstructionPUSHINT : public Instruction{
	private:
	public:
		InstructionPUSHINT(CallStack *callStack, DataStack * dataStack, Heap * heap) : Instruction(callStack, dataStack, heap){

		}
		
		void execute();
};

#endif

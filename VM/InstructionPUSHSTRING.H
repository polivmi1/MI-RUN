#ifndef INSTRUCTIONPUSHSTRING_HEADER
#define INSTRUCTIONPUSHSTRING_HEADER

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
#include "InstanceSTRING.H"
#include "ConstantPool.H"
 
class InstructionPUSHSTRING : public Instruction{
	private:
		ConstantPool * constantPool;
	public:
		InstructionPUSHSTRING(CallStack *callStack, DataStack * dataStack, Heap * heap, ConstantPool * constantPool) : Instruction(callStack, dataStack, heap){
			this->constantPool = constantPool;
		}
		
		void execute();
};

#endif

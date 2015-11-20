#ifndef INSTRUCTIONPUSHDOUBLE_HEADER
#define INSTRUCTIONPUSHDOUBLE_HEADER

#include <iostream>

#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <sstream>
#include <stdexcept>

#include "Instruction.H"
#include "Instance.H"
#include "CallStack.H"
#include "DataStack.H"
#include "Heap.H"
#include "InstanceDOUBLE.H"
#include "ConstantPool.H"

class InstructionPUSHDOUBLE : public Instruction{
	private:
		ConstantPool * constantPool;
	public:
		InstructionPUSHDOUBLE(CallStack *callStack, DataStack * dataStack, Heap * heap, ConstantPool * constantPool) : Instruction(callStack, dataStack, heap){
			this->constantPool = constantPool;
		}
		
		void execute();
};

#endif

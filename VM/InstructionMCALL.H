#ifndef INSTRUCTIONMCALL_HEADER
#define INSTRUCTIONMCALL_HEADER

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
#include "ClassPool.H"
#include "ConstantPool.H"

class InstructionMCALL : public Instruction{
	private:
		ClassPool * classPool;
		ConstantPool * constantPool;
	public:
		InstructionMCALL(CallStack *callStack, DataStack * dataStack, Heap * heap, ConstantPool * constantPool, ClassPool * classPool) : Instruction(callStack, dataStack, heap){
			this->classPool = classPool;
			this->constantPool = constantPool;
		}
		
		void execute();
};

#endif

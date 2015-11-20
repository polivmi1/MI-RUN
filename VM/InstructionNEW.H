#ifndef INSTRUCTIONNEW_HEADER
#define INSTRUCTIONNEW_HEADER

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
#include "InstanceCLASS.H" 

class InstructionNEW : public Instruction{
	private:
		ClassPool * classPool;
		ConstantPool * constantPool;
	public:
		InstructionNEW(CallStack *callStack, DataStack * dataStack, Heap * heap, ConstantPool * constantPool, ClassPool * classPool) : Instruction(callStack, dataStack, heap){
			this->classPool = classPool;
			this->constantPool = constantPool;
		}
		
		void execute();
};

#endif

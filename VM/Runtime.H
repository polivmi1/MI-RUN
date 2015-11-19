#ifndef RUNTIME_HEADER
#define RUNTIME_HEADER

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

#include "Loader.H"
#include "Heap.H"
#include "ConstantPool.H"
#include "ClassPool.H"
#include "CallStack.H"
#include "DataStack.H"
#include "GarbageCollector.H"
#include "Frame.H"
#include "Instruction.H"
#include "InstructionADD.H"
#include "InstructionSUB.H"
#include "InstructionDIV.H"
#include "InstructionMUL.H"
#include "InstructionCLT.H"
#include "InstructionCGT.H"
#include "InstructionCEQ.H"
#include "InstructionCNEQ.H"
#include "InstructionCJMP.H"
#include "InstructionJMP.H"
#include "InstructionNEW.H"
#include "InstructionPUSHID.H"
#include "InstructionPUSHINT.H"
#include "InstructionPUSHDOUBLE.H"
#include "InstructionPUSHSTRING.H"
#include "InstructionSTORE.H"
#include "InstructionCALL.H"
#include "InstructionMCALL.H"
#include "InstructionRET.H"
#include "InstructionPUSHMEMBER.H"
#include "InstructionSTOREMEMBER.H"

class Runtime{
	private:
		Heap *heap;
		ConstantPool *constantPool;
		ClassPool *classPool;
		Loader *loader;
		CallStack *callStack;
		DataStack *dataStack;
		GarbageCollector *gc;
		
	public:
	    Runtime(){
			heap = new Heap();
			constantPool = new ConstantPool();
			classPool = new ClassPool();
			loader = new Loader(classPool, constantPool);
			callStack = new CallStack();
			dataStack = new DataStack();
			gc = new GarbageCollector();
		}

		ConstantPool *getConstantPool();		
		ClassPool *getClassPool();
		void initialize(const std::string &file);
		bool run();
		Instruction *fetch();
};


#endif

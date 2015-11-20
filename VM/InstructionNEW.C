#include "InstructionNEW.H"

void InstructionNEW::execute(){ 
	Frame * f = callStack->top();
	int param = f->getFunction()->getIntBC(f->getEIP());
	f->addEIP(4); 
	//param points to constantpool .... in InstanceClass find name of the class,....
	dataStack->push(heap->addInstanceCLASS(classPool->getClass(constantPool->getConstant(param))));
}


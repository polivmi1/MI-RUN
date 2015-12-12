#include "Heap.H"

int Heap::addInstance(Instance * inst){
  if(allocPtr == heapSize) gc->run(this);
  if(allocPtr == heapSize) expandHeap();
  eden[allocPtr] = std::make_pair(inst,0);
  return allocPtr++;
}

int Heap::addInstanceINT(int value){

	InstanceINT * inst = new InstanceINT(value, this);
	return addInstance(inst);
}

int Heap::addInstanceDOUBLE(double value){

	InstanceDOUBLE * inst = new InstanceDOUBLE(value, this);
	return addInstance(inst);
}

int Heap::addInstanceSTRING(std::string value){
	
	InstanceSTRING * inst = new InstanceSTRING(value);
	return addInstance(inst);
}

int Heap::addInstanceCLASS(Class * value){
	
	InstanceCLASS * inst = new InstanceCLASS(value);
	int n_members = inst->getClass()->getMemberSize();
	for(int i = 0; i < n_members; i++){
		inst->members[i] = addInstanceINT(0);
	}
	return addInstance(inst);
}





Instance * Heap::getInstance(int ref){
  DEB("Address: ");
  DEB(ref);
	if(ref >= heap.size() || heap[ref] == NULL){
		throw std::runtime_error("Heap doesn't contain that address " + ref);
	}
	return heap[ref];
}

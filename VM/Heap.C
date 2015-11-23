#include "Heap.H"

int Heap::addInstance(Instance * inst){
	int i = 0;
	std::vector<Instance *>::iterator it = heap.begin();
	while(it != heap.end() && *it != NULL){
		it++;i++;
	}
	if(i >= heap.size()){
		if(heap.size() == 0){
			heap.resize(10);
		}
		else
			heap.resize(i*2);
		
	}
	heap[i] = inst;
	return i;
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
	if(heap[ref] == NULL){
		throw std::runtime_error("Heap doesn't contain that address " + ref);
	}
	return heap[ref];
}

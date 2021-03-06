#include "Heap.H"

int Heap::addInstance(Instance * inst){
  if(allocPtr == heapSize) gc->run(this);
  if(allocPtr == heapSize) expandHeap();
  eden[allocPtr] = std::make_pair(inst,0);
  return allocPtr++;
}

void Heap::expandHeap() {
  DEB("Expanding heap from");
  DEB(heapSize);
  std::pair<Instance*,int> * newEden = new std::pair<Instance*,int>[2*heapSize];
  std::pair<Instance*,int> * newSurvivor = new std::pair<Instance*,int>[2*heapSize];
  //Instance ** newHeap = new Instance*[2*heapSize];
  for(int i = 0; i < heapSize; ++i) newEden[i] = eden[i];
  for(int i = heapSize; i < 2*heapSize; ++i) newEden[i].first = NULL;
  heapSize *= 2;
  delete [] eden;
  delete [] survivor;
  eden = newEden;
  survivor = newSurvivor;
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
    ds->push(addInstanceINT(0)); // TODO address should me -1
	}
	int pos = addInstance(inst);
	for(int i = n_members-1; i >= 0; i--){
    inst->members[i] = ds->pop();
	}
	return pos;
}





Instance * Heap::getInstance(int ref){
  DEB("Address: ");
  DEB(ref);
	if(ref >= heapSize || eden[ref].first == NULL){
		throw std::runtime_error("Heap doesn't contain that address " + ref);
	}
	return eden[ref].first;
}

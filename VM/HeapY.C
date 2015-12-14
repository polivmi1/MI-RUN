#include "Heap.H"

int Heap::addInstance(Instance * inst){
  if(available.empty()) gc->run(this);
  if(available.empty()) expandHeap();
  int pos = available.top();
  available.pop();
  heap[pos] = inst;
  if(occupiedCnt == (int)occupied.size()) occupied.push_back(pos);
  else occupied[occupiedCnt] = pos;
  ++occupiedCnt;
  DEB("Allocate at address");
  DEB(pos);
  return pos;
}

void Heap::expandHeap() {
  DEB("Expanding heap from");
  DEB(heapSize);
  Instance ** newHeap = new Instance*[2*heapSize];
  for(int i = 0; i < heapSize; ++i) newHeap[i] = heap[i];
  for(int i = heapSize; i < 2*heapSize; ++i) newHeap[i] = NULL;
  for(int i = 2*heapSize-1; i >= heapSize; --i) available.push(i);
  heapSize *= 2;
  delete [] heap;
  heap = newHeap;
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
	if(ref >= heapSize || heap[ref] == NULL){
		throw std::runtime_error("Heap doesn't contain that address " + ref);
	}
	return heap[ref];
}
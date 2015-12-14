#include "Heap.H"

int Heap::addInstance(Instance * inst){
  if(allocPtr == newSize) gc->scavenge(this);
  if(allocPtr == newSize) expandNew();
  eden[allocPtr] = std::make_pair(inst,0);
  return ~(allocPtr++);
}

int Heap::tenure(Instance * inst) {
  // instance should already have oracled flag set
  if(available.empty()) gc->runOld(this);
  if(available.empty()) expandOld();
  int pos = available.top();
  available.pop();
  old[pos] = inst;
  if(occupiedCnt == (int)occupied.size()) occupied.push_back(pos);
  else occupied[occupiedCnt] = pos;
  ++occupiedCnt;
  oracle.add(pos);
  return pos;
}

void Heap::expandNew() {
  DEB("Expanding new from");
  DEB(newSize);
  std::pair<Instance*,int> * newEden = new std::pair<Instance*,int>[2*newSize];
  std::pair<Instance*,int> * newSurvivor = new std::pair<Instance*,int>[2*newSize];
  for(int i = 0; i < newSize; ++i) newEden[i] = eden[i];
  for(int i = newSize; i < 2*newSize; ++i) newEden[i].first = NULL;
  newSize *= 2;
  delete [] eden;
  delete [] survivor;
  eden = newEden;
  survivor = newSurvivor;
}

void Heap::expandOld() {
  DEB("Expanding old from");
  DEB(oldSize);
  Instance ** newOld = new Instance*[2*oldSize];
  for(int i = 0; i < oldSize; ++i) newOld[i] = old[i];
  for(int i = oldSize; i < 2*oldSize; ++i) newOld[i] = NULL;
  for(int i = 2*oldSize-1; i >= oldSize; --i) available.push(i);
  oldSize *= 2;
  delete [] old;
  old = newOld;
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
  if(ref < 0) {
    if(~ref >= newSize || eden[~ref].first == NULL) {
  		throw std::runtime_error("Heap doesn't contain that address " + ref);
    }
  	return eden[~ref].first;
	} else {
  	if(ref >= oldSize || old[ref] == NULL){
  		throw std::runtime_error("Heap doesn't contain that address " + ref);
  	}
  	return old[ref];
  }
}

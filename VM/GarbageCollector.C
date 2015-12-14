#include "GarbageCollector.H"

void GarbageCollector::scavenge(Heap * heap){
	scavenge(heap, cs, ds);
}

void GarbageCollector::runOld(Heap * heap){
	runOld(heap, cs, ds);
}

int GarbageCollector::copy(int edenPos, Heap * heap) { // returns heapPos (possibly negative)
  Instance * inst = heap->eden[edenPos].first;
  if(inst->grow()) {
    int pos = heap->tenure(inst);
    heap->eden[edenPos].first = NULL;
    heap->eden[edenPos].second = pos;
    return pos;
  } else {
    heap->survivor[heap->allocPtr] = heap->eden[edenPos];
    heap->eden[edenPos].first = NULL;
    heap->eden[edenPos].second = ~(heap->allocPtr);
    return ~(heap->allocPtr++);
  }
}

void GarbageCollector::scavenge(Heap * heap, CallStack * callStack, DataStack * dataStack) {
  DEB("BEGIN SCAVENGE");
  
  heap->allocPtr = 0;
  
  // handle roots
  
  for(int i = 0; i < dataStack->stackSize; ++i) {
    int heapPos = dataStack->dataStack[i];
    if(heapPos >= 0) continue;
    int edenPos = ~heapPos;
    if(heap->eden[edenPos].first == NULL) { // already copied
      dataStack->dataStack[i] = heap->eden[edenPos].second;
    } else {
      dataStack->dataStack[i] = copy(edenPos, heap);
    }
  }
  for(int i = 0; i < callStack->stackSize; ++i) {
    Frame * frame = callStack->execStack[i];
    for(int j = 0; j < (int)frame->variables.size(); ++j) {
      int heapPos = frame->variables[j];
      if(heapPos >= 0) continue;
      int edenPos = ~heapPos;
      if(heap->eden[edenPos].first == NULL) { // already copied
        frame->variables[j] = heap->eden[edenPos].second;
      } else {
        frame->variables[j] = copy(edenPos, heap);
      }
    }
  }
  
  // handle roots in old space - oracle
  
  for(int i = 0; i < heap->oracle.size(); i++) {
    int oldPos = heap->oracle[i];
    if(heap->old[oldPos]->getType() == "CLASS") {
      InstanceCLASS * c = static_cast<InstanceCLASS*>(heap->old[oldPos]);
  		int n_members = c->getClass()->getMemberSize();
  		bool reachNew = false;
  		for(int j = 0; j < n_members; ++j) {
  		  int heapPos = c->members[j];
        if(heapPos >= 0) continue;
        reachNew = true;
        int edenPos = ~heapPos;
        if(heap->eden[edenPos].first == NULL) { // already copied
          c->members[j] = heap->eden[edenPos].second;
        } else {
          c->members[j] = copy(edenPos, heap);
        }
      }
      if(!reachNew) {
        c->unsetOracled();
        heap->oracle.remove(i);
        i--;
      }
    } else {
      heap->old[oldPos]->unsetOracled();
      heap->oracle.remove(i);
      i--;
    }
  }
  
  // handle other pointers
  
  for(int i = 0; i < heap->allocPtr; ++i) {
    if(heap->survivor[i].first->getType() == "CLASS") {
      InstanceCLASS * c = static_cast<InstanceCLASS*>(heap->survivor[i].first);
  		int n_members = c->getClass()->getMemberSize();
  		for(int j = 0; j < n_members; ++j) {
  		  int heapPos = c->members[j];
        if(heapPos >= 0) continue;
        int edenPos = ~heapPos;
        if(heap->eden[edenPos].first == NULL) { // already copied
          c->members[j] = heap->eden[edenPos].second;
        } else {
          c->members[j] = copy(edenPos, heap);
        }
      }
    }
  }
  
  swap(heap->eden, heap->survivor);
  
  DEB("SURVIVED");
  DEB(heap->allocPtr);
  DEB("END SCAVENGE");
}

void GarbageCollector::marker(int idx, Instance ** heap) {
  if(idx < 0) return;
  if(heap[idx]->isMarked()) return;
  heap[idx]->setMarked();
  if(heap[idx]->getType() == "CLASS") {
    InstanceCLASS * c = static_cast<InstanceCLASS*>(heap[idx]);
		int n_members = c->getClass()->getMemberSize();
		for(int i = 0; i < n_members; ++i) marker(c->members[i], heap);
  }
}

void GarbageCollector::runOld(Heap * heap, CallStack * callStack, DataStack * dataStack) {

  DEB("BEGIN GC");

  for(int i = 0; i < dataStack->stackSize; ++i) {
    marker(dataStack->dataStack[i], heap->old);
  }
  for(int i = 0; i < callStack->stackSize; ++i) {
    Frame * frame = callStack->execStack[i];
    for(int j = 0; j < (int)frame->variables.size(); ++j) {
      marker(frame->variables[j], heap->old);
    }
  }

  for(int i = 0; i < heap->oracle.size(); i++) {
    int oldPos = heap->oracle[i];
    if(!heap->old[oldPos]->isMarked()) {
      heap->old[oldPos]->unsetOracled();
      heap->oracle.remove(i);
      i--;
    }
  }
  
  int occCnt = 0;
  for(int i = 0; i < heap->occupiedCnt; ++i) {
    int oldPos = heap->occupied[i];
    if(heap->old[oldPos]->isMarked()) {
      heap->occupied[occCnt++] = heap->occupied[i];
      heap->old[oldPos]->unsetMarked();
    } else {
      heap->available.push(oldPos);
      delete heap->old[oldPos]; // but scavenge leaks memory anyway...
      heap->old[oldPos] = NULL;
      DEB("Deallocate at address");
  	  DEB(oldPos);
    }
  }
  heap->occupiedCnt = occCnt;
  DEB("SURVIVED");
  DEB(occCnt);
  DEB("END GC");
}





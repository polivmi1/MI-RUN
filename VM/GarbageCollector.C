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
  DEB("BEGIN GC");
  
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
        c->setNotOracled();
        heap->oracle.remove(i);
        i--;
      }
    } else {
      heap->old[oldPos]->setNotOracled();
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
  
  DEB("END GC");
}

void GarbageCollector::runOld(Heap * heap, CallStack * callStack, DataStack * dataStack) {
  // TODO
}






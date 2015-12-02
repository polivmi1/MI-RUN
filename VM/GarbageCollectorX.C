#include "GarbageCollector.H"

void GarbageCollector::run(Heap * heap){
	
	printf("TODO FINISH GC\n");

}

int GarbageCollector::copy(int heapPos, Heap * heap) {
  heap->survivor[heap->allocPtr] = heap->eden[heapPos];
  heap->eden[heapPos].first = NULL;
  heap->eden[heapPos].second = allocPtr;
  return allocPtr++;
}

void GarbageCollector::run(Heap * heap, CallStack * callStack, DataStack * dataStack) {
  printf("BEGIN GC\n");
  
  heap->allocPtr = 0;
  
  // handle roots
  
  for(int i = 0; i < dataStack->stackSize; ++i) {
    int heapPos = dataStack->dataStack[i];
    if(heap->eden[heapPos].first == NULL) { // already copied
      dataStack->dataStack[i] = heap->eden[heapPos].second;
    } else {
      dataStack->dataStack[i] = copy(heapPos);
    }
  }
  for(int i = 0; i < callStack->stackSize; ++i) {
    Frame * frame = callStack->execStack[i];
    for(int j = 0; j < frame->variables.size(); ++j) {
      int heapPos = frame->variables[j];
      if(heap->eden[heapPos].first == NULL) { // already copied
        frame->variables[j] = heap->eden[heapPos].second;
      } else {
        frame->variables[j] = copy(heapPos);
      }
    }
  }
  
  // handle other pointers
  
  for(int i = 0; i < allocPtr; ++i) {
    if(heap->survivor[i].first->getType() == "CLASS") {
      InstanceCLASS * c = static_cast<InstanceCLASS*>(heap->survivor[i].first);
  		int n_members = c->getClass()->getMemberSize();
  		for(int j = 0; j < n_members; ++j) {
  		  int heapPos = c->members[j];
        if(heap->eden[heapPos].first == NULL) { // already copied
          c->members[j] = heap->eden[heapPos].second;
        } else {
          c->members[j] = copy(heapPos);
        }
      }
    }
  }
  
  swap(heap->eden, heap->survivor);
  
  printf("END GC\n");
}









#include "GarbageCollector.H"

void GarbageCollector::run(Heap * heap){
	
	run(heap, cs, ds);

}

void GarbageCollector::marker(int idx, bool * mark, Instance ** heap) {
  if(mark[idx]) return;
  mark[idx] = true;
  if(heap[idx]->getType() == "CLASS") {
    InstanceCLASS * c = static_cast<InstanceCLASS*>(heap[idx]);
		int n_members = c->getClass()->getMemberSize();
		for(int i = 0; i < n_members; ++i) marker(c->members[i], mark, heap);
  }
}

void GarbageCollector::run(Heap * heap, CallStack * callStack, DataStack * dataStack) {
  printf("BEGIN GC\n");
  bool * mark = new bool[heap->heapSize];
  memset(mark,false,heap->heapSize*sizeof(bool));
  for(int i = 0; i < dataStack->stackSize; ++i) {
    marker(dataStack->dataStack[i], mark, heap->heap);
  }
  for(int i = 0; i < callStack->stackSize; ++i) {
    Frame * frame = callStack->execStack[i];
    for(int j = 0; j < (int)frame->variables.size(); ++j) {
      marker(frame->variables[j], mark, heap->heap);
    }
  }
  int occCnt = 0;
  for(int i = 0; i < heap->occupiedCnt; ++i) {
    int heapPos = heap->occupied[i];
    if(mark[heapPos]) {
      heap->occupied[occCnt++] = heap->occupied[i];
    } else {
      heap->available.push(heapPos);
      heap->heap[heapPos] = NULL;
      printf("Deallocate at address %d\n", heapPos);
    }
  }
  heap->occupiedCnt = occCnt;
  printf("END GC\n");
}









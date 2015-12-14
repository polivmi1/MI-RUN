#ifndef GARBAGECOLLECTOR_HEADER
#define GARBAGECOLLECTOR_HEADER

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>

#include "Heap.H"
#include "CallStack.H"
#include "DataStack.H"
#include "Debug.H"
class Heap;

class GarbageCollector{
	private:
    CallStack * cs;
    DataStack * ds;
    int copy(int heapPos, Heap * heap);
	public:
    GarbageCollector(CallStack * callStack, DataStack * dataStack) : cs(callStack), ds(dataStack) {}
		void scavenge(Heap * heap);
		void scavenge(Heap * heap, CallStack * callStack, DataStack * dataStack);
		void runOld(Heap * heap);
		void runOld(Heap * heap, CallStack * callStack, DataStack * dataStack);
		~GarbageCollector() {
		  // TODO
    }
};

#endif

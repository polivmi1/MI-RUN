#ifndef GARBAGECOLLECTOR_HEADER
#define GARBAGECOLLECTOR_HEADER

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>

#include "Heap.H"

class GarbageCollector{
	private:
    CallStack * cs;
    DataStack * ds;
    int copy(int heapPos, Heap * heap);
	public:
    GarbageCollector(CallStack * callStack, DataStack * dataStack) : cs(callStack), ds(dataStack) {}
		void run(Heap * heap);
		void run(Heap * heap, CallStack * callStack, DataStack * dataStack);
};

#endif

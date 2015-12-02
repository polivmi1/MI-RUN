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
class Heap;

class GarbageCollector{
	private:
    CallStack * cs;
    DataStack * ds;
    void marker(int idx, bool * mark, Instance ** heap);
	public:
    GarbageCollector(CallStack * callStack, DataStack * dataStack) : cs(callStack), ds(dataStack) {}
		void run(Heap * heap);
		void run(Heap * heap, CallStack * callStack, DataStack * dataStack);
};

#endif

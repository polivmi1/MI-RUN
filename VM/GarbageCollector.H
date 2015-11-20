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
	
	public:
		void run(Heap * heap);
};

#endif

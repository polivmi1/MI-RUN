#ifndef HEAP_HEADER
#define HEAP_HEADER

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>

#include "Instance.H"
#include "InstanceINT.H"
#include "InstanceDOUBLE.H"
#include "InstanceSTRING.H"
#include "InstanceCLASS.H"
#include "Class.H"
#include "GarbageCollector.h"
#include "Debug.H"
class GarbageCollector;

#define INIT_HEAP_SIZE 2

class Heap{
	private:
    Instance ** heap;
    int heapSize;
		//std::vector<Instance *> heap;
		std::stack<int> available;
		std::vector<int> occupied;
		int occupiedCnt;
		
    GarbageCollector * gc;
    DataStack * ds;
    
		int addInstance(Instance * );
		void expandHeap();

	
	public:
    Heap(GarbageCollector * garbageCollector, DataStack * dataStack) : heapSize(INIT_HEAP_SIZE), occupiedCnt(0) {
      gc = garbageCollector;
      ds = dataStack;
      heap = new Instance*[INIT_HEAP_SIZE];
      for(int i = INIT_HEAP_SIZE-1; i >= 0; --i) available.push(i);
    }
		int addInstanceINT(int value);
		int addInstanceDOUBLE(double value);
		int addInstanceSTRING(std::string value);
		int addInstanceCLASS(Class * myClass);
		Instance * getInstance(int);

    friend class GarbageCollector;
    
};

#endif
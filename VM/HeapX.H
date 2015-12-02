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

#define INIT_HEAP_SIZE 64
#define MAX_AGE 10

class Heap{
	private:
    std::pair<Instance*,int> * eden, * survivor;
    int allocPtr;
    int heapSize;
    
    GarbageCollector * gc;

		int addInstance(Instance * );
	
	public:
    Heap(GarbageCollector * garbageCollector) : allocPtr(0), heapSize(INIT_HEAP_SIZE) {
      eden = new std::pair<Instance*,int>[INIT_HEAP_SIZE];
      survivor = new std::pair<Instance*,int>[INIT_HEAP_SIZE];
      gc = garbageCollector;
    }
		int addInstanceINT(int value);
		int addInstanceDOUBLE(double value);
		int addInstanceSTRING(std::string value);
		int addInstanceCLASS(Class * myClass);
		Instance * getInstance(int);

    friend class GarbageCollector;
    
};

#endif

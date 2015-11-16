#ifndef HEAP_HEADER
#define HEAP_HEADER

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>

#include "Instance.H"

class Heap{
	private:
		std::vector<Instance *> heap;
	
	public:
		int addInstance(Instance * );
		Instance * getInstance(int);
};

#endif

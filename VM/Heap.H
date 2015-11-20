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

class Heap{
	private:
		std::vector<Instance *> heap;
		int addInstance(Instance * );
	
	public:
		int addInstanceINT(int value);
		int addInstanceDOUBLE(double value);
		int addInstanceSTRING(std::string value);
		int addInstanceCLASS(Class * myClass);
		Instance * getInstance(int);
};

#endif

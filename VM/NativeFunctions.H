#ifndef NATIVEFUNCTIONS_HEADER
#define NATIVEFUNCTIONS_HEADER

#include <iostream>

#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>

#include "Instance.H"
#include "DataStack.H"
#include "Heap.H"
#include "InstanceINT.H"
#include "InstanceDOUBLE.H"
#include "InstanceSTRING.H"


class NativeFunctions{
	public:
		static bool callNative(std::string name, DataStack *dataStack, Heap *heap);
		static void addFunction(std::string name);
		
};


#endif

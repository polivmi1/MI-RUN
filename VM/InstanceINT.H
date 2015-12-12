#ifndef INSTANCEINT_HEADER
#define INSTANCEINT_HEADER

#include <iostream>

#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>
#include <sstream>

#include "Instance.H"
#include "InstanceDOUBLE.H"
#include "Heap.H"

class Heap;

class InstanceINT : public Instance{
	private:
		int value;
		Heap * heap;
	public:
		InstanceINT(int value, Heap * heap){
			this->value = value;
			this->heap = heap;
		}
		int  add(Instance * b);
		int  sub(Instance * b);
		int  div(Instance * b);
		int  mul(Instance * b);
		int  clt(Instance * b);
		int  cgt(Instance * b);
		int  ceq(Instance * b);
		int  cneq(Instance * b);
		std::string getType();
		int getValue(){return value;}
		bool isTrue();
		std::string toString(){std::stringstream ss;ss<<value;std::string s;ss>>s;return s;}
};

#endif

#ifndef INSTANCEDOUBLE_HEADER
#define INSTANCEDOUBLE_HEADER

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>
#include <sstream>

#include "Instance.H"
#include "InstanceINT.H"
#include "Heap.H"

class Heap;

class InstanceDOUBLE : public Instance{
	private:
		double value;
		Heap * heap;
	public:
		InstanceDOUBLE(double value, Heap * heap){
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
		double getValue(){return value;}
		bool isTrue();
		std::string toString(){std::stringstream ss;ss<<value;std::string s;ss>>s;return s;}
};

#endif

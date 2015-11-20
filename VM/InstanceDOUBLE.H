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

class InstanceDOUBLE : public Instance{
	private:
		double value;
	public:
		InstanceDOUBLE(double value){
			this->value = value;
		}
		Instance * add(Instance * b);
		Instance * sub(Instance * b);
		Instance * div(Instance * b);
		Instance * mul(Instance * b);
		Instance * clt(Instance * b);
		Instance * cgt(Instance * b);
		Instance * ceq(Instance * b);
		Instance * cneq(Instance * b);
		std::string getType();
		double getValue(){return value;}
		bool isTrue();
		std::string toString(){std::stringstream ss;ss<<value;std::string s;ss>>s;return s;}
};

#endif

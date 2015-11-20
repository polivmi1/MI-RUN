#ifndef INSTANCESTRING_HEADER
#define INSTANCESTRING_HEADER

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>

#include "Instance.H"


class InstanceSTRING : public Instance{
	private:
		std::string value; //not a real value, but pointer to constantpool
	public:
		InstanceSTRING(std::string value){
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
		std::string toString(){return value;}
};

#endif

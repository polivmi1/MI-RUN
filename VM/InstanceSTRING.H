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
		int  add(Instance * b);
		int  sub(Instance * b);
		int  div(Instance * b);
		int  mul(Instance * b);
		int  clt(Instance * b);
		int  cgt(Instance * b);
		int  ceq(Instance * b);
		int  cneq(Instance * b);
		std::string getType();
		std::string toString(){return value;}
};

#endif

#ifndef INSTANCEINT_HEADER
#define INSTANCEINT_HEADER

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>

#include "Instance.H"
#include "InstanceDOUBLE.H"


class InstanceINT : public Instance{
	private:
		int value;
	public:
		InstanceINT(int value){
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
		int getValue(){return value;}
		bool isTrue();
};

#endif

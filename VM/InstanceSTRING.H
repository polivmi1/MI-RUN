#ifndef INSTANCESTRING_HEADER
#define INSTANCESTRING_HEADER

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>

#include "Instance.H"
#include "ConstantPool.H"


class InstanceSTRING : public Instance{
	private:
		int ref; //not a real value, but pointer to constantpool
		ConstantPool * constantPool;
	public:
		InstanceSTRING(int ref, ConstantPool * constantPool){
			this->ref = ref;
			this->constantPool = constantPool;
		}
		Instance * add(Instance * b);
		Instance * sub(Instance * b);
		Instance * div(Instance * b);
		Instance * mul(Instance * b);
		Instance * clt(Instance * b);
		Instance * cgt(Instance * b);
		Instance * ceq(Instance * b);
		Instance * cneq(Instance * b);
};

#endif

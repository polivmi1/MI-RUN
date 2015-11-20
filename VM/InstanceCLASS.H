#ifndef INSTANCECLASS_HEADER
#define INSTANCECLASS_HEADER

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>

#include "Instance.H"
#include "Class.H"


class InstanceCLASS : public Instance{
	private:
		std::vector<int> members;//position [i] is from instanceOf->members[string name]...return reference
		Class * myClass;
	public:
		InstanceCLASS(Class * myClass){
			this->myClass = myClass;
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
		int getRefMember(std::string);
		std::string toString(){return "CLASS";}
};

#endif

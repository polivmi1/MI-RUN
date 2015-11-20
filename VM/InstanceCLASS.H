#ifndef INSTANCECLASS_HEADER
#define INSTANCECLASS_HEADER

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>

#include "Instance.H"
#include "InstanceINT.H"
#include "Class.H"
#include "Heap.H"


class InstanceCLASS : public Instance{
	private:
		std::vector<int> members;//position [i] is from instanceOf->members[string name]...return reference
		Class * myClass;
	public:
		InstanceCLASS(Class * myClass, Heap * heap){
			this->myClass = myClass;
			int n_members = myClass->getMemberSize();
			for(int i = 0; i < n_members; i++){
				members.insert(members.begin() + i, heap->addInstance(new InstanceINT(0)));
			}
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
		void setRefMember(std::string name, int ref);
		std::string toString(){return "CLASS";}
		Class * getClass(){return myClass;}
};

#endif

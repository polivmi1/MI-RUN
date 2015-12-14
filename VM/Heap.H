#ifndef HEAP_HEADER
#define HEAP_HEADER

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>

#include "Instance.H"
#include "InstanceINT.H"
#include "InstanceDOUBLE.H"
#include "InstanceSTRING.H"
#include "InstanceCLASS.H"
#include "Class.H"
#include "GarbageCollector.h"
#include "Debug.H"
class GarbageCollector;

#define INIT_NEW_SIZE 4
#define INIT_OLD_SIZE 8

class Heap{
	private:
    
    class Oracle {
      std::vector<int> v;
      int cnt;
     public:
      Oracle() : cnt(0) {}
      void add(int val) {
        if(cnt == (int)v.size()) v.push_back(val);
        else v[cnt] = val;
        cnt++;
      }
      int& operator[](const int& idx) {
        return v[idx];
      }
      void remove(int idx) {
        std::swap(v[idx],v[cnt-1]);
        cnt--;
      }
      int size() {
        return cnt;
      }
    };
    
    Instance ** old;
		std::stack<int> available;
		std::vector<int> occupied;
		int occupiedCnt;
		int oldSize;

    std::pair<Instance*,int> * eden, * survivor;
    int allocPtr;
    int newSize;
    
    GarbageCollector * gc;
    DataStack * ds;

		int addInstance(Instance * );
		void expandNew();
		void expandOld();
		int tenure(Instance * inst);
	
	public:

    Oracle oracle;

    Heap(GarbageCollector * garbageCollector, DataStack * dataStack) : occupiedCnt(0), oldSize(INIT_OLD_SIZE), allocPtr(0), newSize(INIT_NEW_SIZE) {
      gc = garbageCollector;
      ds = dataStack;
      old = new Instance*[INIT_OLD_SIZE];
      for(int i = INIT_OLD_SIZE-1; i >= 0; --i) available.push(i);
      eden = new std::pair<Instance*,int>[INIT_NEW_SIZE];
      survivor = new std::pair<Instance*,int>[INIT_NEW_SIZE];
      for(int i = 0; i < INIT_NEW_SIZE; i++) eden[i].first = NULL;
    }
    ~Heap() {
      // TODO
      delete [] eden;
      delete [] survivor;
      delete [] old;
    }
		int addInstanceINT(int value);
		int addInstanceDOUBLE(double value);
		int addInstanceSTRING(std::string value);
		int addInstanceCLASS(Class * myClass);
		Instance * getInstance(int);

    friend class GarbageCollector;
    
};

#endif

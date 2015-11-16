#include "Heap.H"

int Heap::addInstance(Instance * inst){
	int i = 0;
	std::vector<Instance *>::iterator it = heap.begin();
	while(it != heap.end() && *it != NULL){
		it++;i++;
	}
	heap.insert(it, inst);
	return i;
}

Instance * Heap::getInstance(int ref){
	if(heap[ref] == NULL){
		throw std::runtime_error("Heap doesn't contain that address " + ref);
	}
	return heap[ref];
}

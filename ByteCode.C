#include "ByteCode.H"

using namespace std;

void Bytecode::addByte(char b){
	bc.push_back(b);
}

void Bytecode::addInt(int b){
	bc.push_back((char)(b >> 24));
	bc.push_back((char)(b >> 16));
	bc.push_back((char)(b >> 8));
	bc.push_back((char)(b));
}


void Bytecode::writeToFile(std::ofstream &file){
	for(unsigned int i = 0; i < bc.size(); i+=1)
		file << bc[i];
	cout<<endl;
}

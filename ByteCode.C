#include "ByteCode.H"

using namespace std;

void Bytecode::addByte(unsigned char b){
	bc.push_back(b);
	counter++;
}

void Bytecode::addInt(int b){
	bc.push_back((b >> 24) & 0xFF);
	bc.push_back((b >> 16) & 0xFF);
	bc.push_back((b >> 8) & 0xFF);
	bc.push_back(b & 0xFF);
	counter += 4;
	
}

void Bytecode::changeIntByte(int pos, int b){
	bc[pos] = (unsigned char)((b >> 24) & 0xFF);
	bc[pos+1] = (unsigned char)((b >> 16) & 0xFF);
	bc[pos+2] = (unsigned char)((b >> 8) & 0xFF);
	bc[pos+3] = (unsigned char)(b & 0xFF);
}

void Bytecode::writeToFile(std::ofstream &file){
	for(unsigned int i = 0; i < bc.size(); i+=1)
		file << bc[i];
	cout<<endl;
}

#include "ClassPool.H"
#include <iostream>
#include <functional>
#include <cctype>
#include <algorithm>
using namespace std;

static inline string& rtrim(string& s) {
  while(s.length() > 0 && isspace(s[s.length()-1])) {
    s.erase(s.length()-1,1);
  }
  //s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int,int>(isspace))));
  return s;
}

Class * ClassPool::getClass(const std::string &name){
  string nname = name;
  rtrim(nname);
	std::map<std::string, Class *>::iterator it = members.find(nname);
	cout << "Getting class >" << nname << "<" << endl;
	if(it == members.end()){
	   cout <<"no class" <<endl;
		throw std::runtime_error("Unable to find class " + nname);
	}
	cout << "class" <<endl;
	return it->second;	
}

void ClassPool::addClass(Class * c){
  string nname = c->getName();
  rtrim(nname);
	std::map<std::string, Class *>::iterator it = members.find(nname);
	if(it != members.end()){
		throw std::runtime_error("Class already exists " + c->getName());
	}
	members[nname] = c;
	cout << "Added " << ">" << nname << "<" << endl;
}
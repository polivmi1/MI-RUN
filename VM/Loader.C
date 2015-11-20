#include "Loader.H"

using namespace std;

int Loader::getInt(ifstream & file){

	char buf[4];
	file.read(buf, sizeof(buf) / sizeof(*buf));


	int t, ret = 0;
	t = buf[0];
	t = t<<24;
	ret = ret | t;
	t = buf[1];
	t = t<<16;
	ret = ret | t;
	t = buf[2];
	t = t<<8;
	ret = ret | t;
	t = buf[3];
	ret = ret | t;
	
	return ret;
}

void Loader::load(const std::string &name){
  ifstream fileC;
  ifstream file;
  char buf[1];
  DEB("OPENING FILE: " + name);
  file.open(name.c_str(), std::ios::in | std::ios::binary);
  fileC.open((name + "C").c_str());
  
  char c;
  int n_classes;
  int n_functions, n_members;
  int c_name, c_parent, f_name, n_param, m_name;
  
  //constant pool
  string str;
  int c_pool_size;
  int b;
  DEB("READING C_POOL");
  
  fileC >> c_pool_size;
  
  for(int i = 0; i < c_pool_size; i++){
	getline(fileC, str);//\n
	getline(fileC, str);
	fileC >> b; 
	constantPool->addConstant(b, str);
  }

  DEB("READING REST");
  Class * my_class;
  //classes
  n_classes = getInt(file);
  DEB("Size: ");
  DEB(n_classes);
  
  //add class "Base"
  classPool->addClass(new Class("Base", NULL));
  
  for(int i = 0; i < n_classes; i++){
	DEB("Class: ");
	DEB(i);
	file.read(buf, sizeof(buf) / sizeof(*buf));//begin class
	c_name = getInt(file);
	c_parent = getInt(file);
	
	my_class = new Class(constantPool->getConstant(c_name), classPool->getClass(constantPool->getConstant(c_parent)));
	n_members = getInt(file);
	for(int j = 0; j < n_members; j++){
		m_name = getInt(file);
		my_class->addMember(constantPool->getConstant(m_name));
		DEB("Member name: " + constantPool->getConstant(m_name));
	}
	
	n_functions = getInt(file);
	for(int j = 0; j < n_functions; j++){
	  
		DEB("Function: ");
		DEB(j);
	    //begin fun
		f_name = getInt(file);
		DEB("Name: " + constantPool->getConstant(f_name));
		n_param = getInt(file);
		DEB(n_param);
		vector<char> bc;
		while(file.read(buf, sizeof(buf) / sizeof(*buf)) && buf[0] != 0x21){//till end fun
			bc.push_back(buf[0]);
		}
	    my_class->addFunction(new Function(constantPool->getConstant(f_name), n_param, bc));
	  }
	file.read(buf, sizeof(buf) / sizeof(*buf));//end class
	classPool->addClass(my_class);
  } 
}

void Loader::print(){
	cout<<"PRINTING..TODO" << endl;
}


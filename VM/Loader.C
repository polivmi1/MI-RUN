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
  cout << "OPENING FILE: " << name << endl;
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
  cout << "READING C_POOL" << endl;
  
  fileC >> c_pool_size;
  
  for(int i = 0; i < c_pool_size; i++){
	getline(fileC, str);//\n
	getline(fileC, str);
	fileC >> b; 
	constantPool->addConstant(b, str);
  }

  cout << "READING REST" << endl;
  Class * my_class;
  //classes
  n_classes = getInt(file);
  cout << "Size: " << n_classes << endl;
  
  //add class "Base"
  classPool->addClass(new Class("Base", NULL));
  
  for(int i = 0; i < n_classes; i++){
	cout << "Class: " << i << endl;
	file.read(buf, sizeof(buf) / sizeof(*buf));//begin class
	c_name = getInt(file);
	c_parent = getInt(file);
	
	my_class = new Class(constantPool->getConstant(c_name), classPool->getClass(constantPool->getConstant(c_parent)));
	n_members = getInt(file);
	for(int j = 0; j < n_members; j++){
		m_name = getInt(file);
		my_class->addMember(constantPool->getConstant(m_name));
		cout << "Member name: " << constantPool->getConstant(m_name) << endl;
	}
	
	n_functions = getInt(file);
	for(int j = 0; j < n_functions; j++){
	  
		cout << "Function: " << j << endl;
	    //begin fun
		f_name = getInt(file);
		cout << "Name: " << constantPool->getConstant(f_name) << endl;
		n_param = getInt(file);
		cout << "n. of Parameters: " << n_param << endl;
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


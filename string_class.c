//*************************************************************
//*
//* Copyright (c) 2016 : wang liang
//* License : Distributed under the GNU General Public License
//* created on : 4/10/2016,  by wang liang (wliked@outlook.com)
//* 
//*************************************************************

//define a string class that includes: 
//constructor function, copy construct function, copy operator=, and destructor function
class my_string
{
public:
  my_string();
  my_string(const char* str);
  my_string(const my_string& rhs);
  my_string& operator=(const my_string& rhs);
  ~my_string();
provate:
  char* pstr_;
}

my_string::my_string() //defaul constructor with no input parameter; then "my_string str;" is ok 
{
	pstr_=NULL;
}

my_string::my_string(const char* str)  //common construtor with input parameter
{
	if(NULL == str)
	{
	   pstr_ = NULL;	
	}
    else
	{
	   pstr_ = new char[strlen(str)+1];
	   assert(NULL != pstr_);
	   strcpy(pstr_,str);
	}	
}

my_string::my_string(const my_string& rhs)  //copy constructor; input parameter must be const &;
{    
    if(NULL == rhs.pstr_)
	{
	   pstr_= NULL;
	}
	else
	{
	   pstr_= new char[strlen(rhs.pstr_)+1];
	   assert(NULL !=pstr_);
	   strcpy(pstr_,rhs.pstr_);
	}
}


//why return a reference of my_string:
// 1. allow linked copy operation : e.g. a=b=c
// 2. why not return a my_string:
//       (a) if return a my_string instance, the compiler will gen a temporary instance, 
//           and call copy constructor function at end of this operator; then call destructor of 
//           the temporary instance; if no deep copy constructor function defined by user, 
//           copy constructor will be shallow copy; so the temporary instance will affect the
//           memory of (*this);
//       (b) also the temporary instance will affect the memory of return instance my_string.           
my_string& my_string::operator=(const my_string& rhs) //copy operator
{
	if(this== &rhs)  //check if self copy
    {
	   return *this;
	}	
	
	delete []pstr_;
	
	if(NULL == rhs.pstr_)
	{
	   pstr_= NULL;
	}
	else
	{
	   pstr_= new char[strlen(rhs.pstr_)+1];
	   assert(NULL != pstr_);
	   strcpy(pstr_,rhs.pstr_);
	}
	return *this;
}

my_string::~my_string()  //destructor function
{
	delete []pstr_;
}




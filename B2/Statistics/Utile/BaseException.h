#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
#include <iostream>

class BaseException {
	protected:
		char* msg;
		
	public:
	//Constructeurs
		BaseException(const char*);
		BaseException(const BaseException&);
		virtual ~BaseException();
		
	//Setters
		void setMsg(const char*);
		
	//Getters
		virtual const char* getMsg() const { return msg; };
};
#endif

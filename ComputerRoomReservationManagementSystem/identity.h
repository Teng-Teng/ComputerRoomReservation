#pragma once
#include <iostream>
using namespace std;

// Identity abstract base class
class Identity {
public:
	// Operation menu, pure virtual function
	virtual void operMenu() = 0;

	// username
	string m_Name;

	// password
	string m_Pwd;

};
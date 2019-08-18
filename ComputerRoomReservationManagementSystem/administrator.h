#pragma once
#include "identity.h"

// Administrator class
class Administrator :public Identity {
public:
	// Default constructor
	Administrator();

	// Parameterized constructor, parameter: name and password
	Administrator(string name, string pwd);

	// Menu interface
	virtual void operMenu();

	// Add account
	void addPerson();

	// View account
	void showPerson();

	// View computer room information
	void showComputer();

	// Clear reservation record
	void clearFile();

};
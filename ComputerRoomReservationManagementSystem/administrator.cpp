#include "administrator.h"

// Default constructor
Administrator::Administrator() {

}

// Parameterized constructor, parameter: name and password
Administrator::Administrator(string name, string pwd) {
	// Initialize administrator information
	this->m_Name = name;
	this->m_Pwd = pwd;
}

// Menu interface
void Administrator::operMenu() {
	cout << "Welcome administrator: " << this->m_Name << " login!" << endl;
	cout << "\t\t ------------------------------------------\n" << endl;
	cout << "\t\t|                                          |\n" << endl;
	cout << "\t\t|       1. Add account                     |\n" << endl;
	cout << "\t\t|                                          |\n" << endl;
	cout << "\t\t|       2. View account                    |\n" << endl;
	cout << "\t\t|                                          |\n" << endl;
	cout << "\t\t|       3. View computer room              |\n" << endl;
	cout << "\t\t|                                          |\n" << endl;
	cout << "\t\t|       4. Clear reservation record        |\n" << endl;
	cout << "\t\t|                                          |\n" << endl;
	cout << "\t\t|       0. Logout                          |\n" << endl;
	cout << "\t\t|                                          |\n" << endl;
	cout << "\t\t ------------------------------------------\n" << endl;
	cout << "Please choose your operation: " << endl;
}

// Add account
void Administrator::addPerson() {

}

// View account
void Administrator::showPerson() {

}

// View computer room information
void Administrator::showComputer() {

}

// Clear reservation record
void Administrator::clearFile() {

}



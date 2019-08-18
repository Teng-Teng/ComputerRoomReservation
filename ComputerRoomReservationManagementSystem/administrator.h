#pragma once
#include "identity.h"
#include <fstream>
#include "globalFile.h"
#include <vector>
#include <algorithm>
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"

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

	// Initialize container
	void initVector();

	// Duplicate detection, parameter 1: check student or teacher ID, parameter 2: identity type
	bool checkRepeat(int id, int type);

	// Student container
	vector<Student> vStu;

	// Teacher container
	vector<Teacher> vTea;

	// Computer room container
	vector<ComputerRoom> vCom;
};
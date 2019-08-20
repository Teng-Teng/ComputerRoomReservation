#pragma once
#include <vector>
#include "identity.h"
#include "reservationFile.h"

// Teacher class
class Teacher :public Identity {
public:
	// Default constructor
	Teacher();

	// Parameterized constructor, parameter: teacher ID, name and password
	Teacher(int empId, string name, string pwd);

	// Menu interface
	virtual void operMenu();

	// View all reservation
	void showAllReservation();

	// Review reservation
	void reviewReservation();

	// Employee number
	int m_EmpId;
};
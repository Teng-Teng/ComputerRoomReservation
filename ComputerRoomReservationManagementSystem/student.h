#pragma once
#include "identity.h"

// Student class
class Student :public Identity {
public:
	// Default constructor
	Student();

	// Parameterized constructor, parameter: student ID, name and password
	Student(int id, string name, string pwd);

	// Menu interface
	virtual void operMenu();

	// Apply for a reservation
	void applyReservation();

	// View your own reservation
	void showMyReservation();

	// View all reservation
	void showAllReservation();

	// Cancel reservation
	void cancelReservation();

	// Student ID
	int m_Id;

};
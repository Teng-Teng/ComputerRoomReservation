#pragma once
#include <vector>
#include <fstream>
#include "identity.h"
#include "computerRoom.h"
#include "globalFile.h"
#include "reservationFile.h"

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

	// computer room container
	vector<ComputerRoom> vCom;
};
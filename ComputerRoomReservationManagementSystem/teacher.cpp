#include "teacher.h"

// Default constructor
Teacher::Teacher() {

}

// Parameterized constructor, parameter: teacher ID, name and password
Teacher::Teacher(int empId, string name, string pwd) {
	// property initialization
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

// Menu interface
void Teacher::operMenu() {
	cout << "Welcome teacher: " << this->m_Name << " login!" << endl;
	cout << "\t\t ------------------------------------------\n" << endl;
	cout << "\t\t|                                          |\n" << endl;
	cout << "\t\t|         1. View all reservation          |\n" << endl;
	cout << "\t\t|                                          |\n" << endl;
	cout << "\t\t|         2. Review reservation            |\n" << endl;
	cout << "\t\t|                                          |\n" << endl;
	cout << "\t\t|         0. Logout                        |\n" << endl;
	cout << "\t\t|                                          |\n" << endl;
	cout << "\t\t ------------------------------------------\n" << endl;
	cout << "Please choose your operation: " << endl;
}

// View all reservation
void Teacher::showAllReservation() {
	ReservationFile resFile;

	if (resFile.m_Size == 0) {
		cout << "No reservation record!" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < resFile.m_Size; i++) {
		cout << i + 1 << ". ";
		cout << "Reservation date: " << resFile.map_reservationData[i]["date"];
		cout << ", Period: " << (resFile.map_reservationData[i]["period"] == "1" ? "Morning" : "Afternoon");
		cout << ", Student ID: " << resFile.map_reservationData[i]["stuId"];
		cout << ", Student name: " << resFile.map_reservationData[i]["stuName"];
		cout << ", Computer room number: " << resFile.map_reservationData[i]["roomId"];

		string status = ", Status: ";

		// 1--under review, 2--already reserved, -1--reserve failed, 0--cancel reservation
		if (resFile.map_reservationData[i]["status"] == "1")
			status += "under review";
		else if (resFile.map_reservationData[i]["status"] == "2")
			status += "already reserved";
		else if (resFile.map_reservationData[i]["status"] == "-1")
			status += "reserve failed, not approved";
		else
			status += "reservation canceled";

		cout << status << endl;
	}

	system("pause");
	system("cls");
}

// Review reservation
void Teacher::reviewReservation() {
	ReservationFile resFile;

	if (resFile.m_Size == 0) {
		cout << "No reservation record!" << endl;
		system("pause");
		system("cls");
		return;
	}

	vector<int> v;
	int index = 0;
	cout << "The reservation records to be reviewed are as follows: " << endl;

	for (int i = 0; i < resFile.m_Size; i++) {
		if (resFile.map_reservationData[i]["status"] == "1") {
			v.push_back(i);

			cout << ++index << ". ";
			cout << "Reservation date: " << resFile.map_reservationData[i]["date"];
			cout << ", Period: " << (resFile.map_reservationData[i]["period"] == "1" ? "Morning" : "Afternoon");
			cout << ", Student ID: " << resFile.map_reservationData[i]["stuId"];
			cout << ", Student name: " << resFile.map_reservationData[i]["stuName"];
			cout << ", Computer room number: " << resFile.map_reservationData[i]["roomId"];

			string status = ", Status: under review";
			cout << status << endl;
		}
	}

	cout << "Please enter the reservation record to review, press 0 to return: " << endl;
	int select = 0;
	int result = 0;

	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0)
				break;

			cout << "Please enter the audit result: " << endl;
			cout << "1. Approved" << endl;
			cout << "2. Not approved" << endl;

			cin >> result;
			if (result == 1)
				resFile.map_reservationData[v[select - 1]]["status"] = "2";
			else
				resFile.map_reservationData[v[select - 1]]["status"] = "-1";

			// update reservation record
			resFile.updateReservation();
			cout << "Review completed!" << endl;
			break;
		}

		cout << "Incorrect input, please re-enter: " << endl;
	}

	system("pause");
	system("cls");
}

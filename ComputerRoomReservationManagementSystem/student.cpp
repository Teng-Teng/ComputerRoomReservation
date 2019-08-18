#include "student.h"

// Default constructor
Student::Student() {

}

// Parameterized constructor, parameter: student ID, name and password
Student::Student(int id, string name, string pwd) {
	// property initialization
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	// initialize computer room information
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
		vCom.push_back(com);

	ifs.close();
}

// Menu interface
void Student::operMenu() {
	cout << "Welcome student representative: " << this->m_Name << " login!" << endl;
	cout << "\t\t ------------------------------------------\n" << endl;
	cout << "\t\t|                                          |\n" << endl;
	cout << "\t\t|        1. Apply Reservation              |\n" << endl;
	cout << "\t\t|                                          |\n" << endl;
	cout << "\t\t|        2. View Your Reservation          |\n" << endl;
	cout << "\t\t|                                          |\n" << endl;
	cout << "\t\t|        3. View All Reservation           |\n" << endl;
	cout << "\t\t|                                          |\n" << endl;
	cout << "\t\t|        4. Cancel Reservation             |\n" << endl;
	cout << "\t\t|                                          |\n" << endl;
	cout << "\t\t|        0. Logout                         |\n" << endl;
	cout << "\t\t|                                          |\n" << endl;
	cout << "\t\t ------------------------------------------\n" << endl;
	cout << "Please choose your operation: " << endl;
}

// Apply for a reservation
void Student::applyReservation() {
	cout << "The computer room is open from Monday to Friday!" << endl;
	cout << "Please enter the time to apply for a reservation: " << endl;
	cout << "1. Monday" << endl;
	cout << "2. Tuesday" << endl;
	cout << "3. Wednesday" << endl;
	cout << "4. Thursday" << endl;
	cout << "5. Friday" << endl;

	int date = 0;
	// morning or afternoon
	int period = 0;
	// computer room number
	int room = 0;

	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5)
			break;
		cout << "Incorrect input, please re-enter" << endl;
	}

	cout << "Please enter the time period to applying for a reservation: " << endl;
	cout << "1. Morning" << endl;
	cout << "2. Afternoon" << endl;

	while (true) {
		cin >> period;
		if (period >= 1 && period <= 2)
			break;
		cout << "Incorrect input, please re-enter" << endl;
	}

	cout << "Please choose the computer room: " << endl;
	for (int i = 0; i < vCom.size(); i++)
		cout << "Computer room " << vCom[i].m_ComId << " capacity: " << vCom[i].m_MaxNum << endl;

	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3)
			break;
		cout << "Incorrect input, please re-enter" << endl;
	}

	cout << "Your reservation is successfully applied and is under review by teachers!" << endl;

	ofstream ofs;
	ofs.open(RESERVATION_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << "period:" << period << " ";
	ofs << "studentId:" << this->m_Id << " ";
	ofs << "studentName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();
	system("pause");
	system("cls");
}

// View your own reservation
void Student::showMyReservation() {

}

// View all reservation
void Student::showAllReservation() {

}

// Cancel reservation
void Student::cancelReservation() {

}

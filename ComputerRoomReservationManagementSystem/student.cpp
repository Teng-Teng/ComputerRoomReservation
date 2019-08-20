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
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();
	system("pause");
	system("cls");
}

// View your own reservation
void Student::showMyReservation() {
	ReservationFile resFile;

	if (resFile.m_Size == 0) {
		cout << "No reservation record!" << endl;
		system("pause");
		system("cls");
		return;
	}

	// find your own reservation
	for (int i = 0; i < resFile.m_Size; i++) {
		if (this->m_Id == atoi(resFile.map_reservationData[i]["stuId"].c_str())) {
			cout << "Reservation date: " << resFile.map_reservationData[i]["date"];
			cout << ", Period: " << (resFile.map_reservationData[i]["period"] == "1" ? "Morning" : "Afternoon");
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
	}

	system("pause");
	system("cls");
}

// View all reservation
void Student::showAllReservation() {
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

// Cancel reservation
void Student::cancelReservation() {
	ReservationFile resFile;

	if (resFile.m_Size == 0) {
		cout << "No reservation record!" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "Records under review or successfully reserved can be canceled" << endl;

	vector<int> v;
	int index = 1;
	for (int i = 0; i < resFile.m_Size; i++) {
		if (this->m_Id == atoi(resFile.map_reservationData[i]["stuId"].c_str())) {
			if (resFile.map_reservationData[i]["status"] == "1" || resFile.map_reservationData[i]["status"] == "2") {
				v.push_back(i);

				cout << index++ << ". ";
				cout << "Reservation date: " << resFile.map_reservationData[i]["date"];
				cout << ", Period: " << (resFile.map_reservationData[i]["period"] == "1" ? "Morning" : "Afternoon");
				cout << ", Computer room number: " << resFile.map_reservationData[i]["roomId"];

				string status = ", Status: ";

				// 1--under review, 2--already reserved
				if (resFile.map_reservationData[i]["status"] == "1")
					status += "under review";
				else if (resFile.map_reservationData[i]["status"] == "2")
					status += "already reserved";

				cout << status << endl;
			}
		}
	}

	cout << "Please enter the record number to cancel(press 0 to return):" << endl;

	int select = 0;
	while (true) {
		cin >> select;

		if (select >= 0 && select <= v.size()) {
			if (select == 0)
				break;
			else {
				resFile.map_reservationData[v[select - 1]]["status"] = "0";
				resFile.updateReservation();
				cout << "Reservation has been cancelled!" << endl;
				break;
			}
		}

		cout << "Incorrect input, please re-enter: " << endl;
	}

	system("pause");
	system("cls");
}

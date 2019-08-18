#include "administrator.h"

// Default constructor
Administrator::Administrator() {

}

// Parameterized constructor, parameter: name and password
Administrator::Administrator(string name, string pwd) {
	// Initialize administrator information
	this->m_Name = name;
	this->m_Pwd = pwd;

	// Initialize container, get student and teacher information in all files
	this->initVector();

	// Initialize computer room information
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) 
		vCom.push_back(com);

	ifs.close();
	cout << "The number of computer room is: " << vCom.size() << endl;
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
	cout << "Please enter the add account type" << endl;
	cout << "1. Add stuent" << endl;
	cout << "2. Add teacher" << endl;

	string fileName;
	string prompt;
	// Repeat error message
	string errorPrompt;

	// ofstream object
	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1) {
		fileName = STUDENT_FILE;
		prompt = "Please enter student ID: ";
		errorPrompt = "Duplicate student ID, please re-enter: ";
	}
	else {
		fileName = TEACHER_FILE;
		prompt = "Please enter teacher ID: ";
		errorPrompt = "Duplicate teacher ID, please re-enter: ";
	}

	// Write file in an append manner
	ofs.open(fileName, ios::out | ios::app);

	int id;
	string name;
	string pwd;

	cout << prompt << endl;

	while (true) {
		cin >> id;

		bool ret = checkRepeat(id, select);

		if (ret)
			cout << errorPrompt << endl;
		else
			break;
	}

	cout << "Please enter username: " << endl;
	cin >> name;

	cout << "Please enter password: " << endl;
	cin >> pwd;

	// Add data to file
	ofs << id << " " << name << " " << pwd << " " << endl;

	cout << "Account successfully created!" << endl;

	system("pause");
	system("cls");

	ofs.close();

	// Initialize container, get student and teacher information in all files
	this->initVector();
}

void printStudent(Student& stu) {
	cout << "Student ID: " << stu.m_Id << " Name: " << stu.m_Name << " Password: " << stu.m_Pwd << endl;
}

void printTeacher(Teacher& tea) {
	cout << "Teacher ID: " << tea.m_EmpId << " Name: " << tea.m_Name << " Password: " << tea.m_Pwd << endl;
}

// View account
void Administrator::showPerson() {
	cout << "Please select the content to display: " << endl;
	cout << "1. View all students" << endl;
	cout << "2. View all teachers" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		// view all students
		cout << "All student information is as follows: " << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else {
		// view all teachers
		cout << "All teacher information is as follows: " << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");
}

// View computer room information
void Administrator::showComputer() {
	cout << "The computer room information is as follows: " << endl;

	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
		cout << "Computer room ID: " << it->m_ComId << " Maximum capacity: " << it->m_MaxNum << endl;
	
	system("pause");
	system("cls");
}

// Clear reservation record
void Administrator::clearFile() {
	ofstream ofs(RESERVATION_FILE, ios::trunc);
	ofs.close();

	cout << "Reservation record successfully cleared!" << endl;
	system("pause");
	system("cls");
}

// Initialize container
void Administrator::initVector() {
	// Make sure container is empty
	vStu.clear();
	vTea.clear();

	// Read student information
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "File reading failed!" << endl;
		return;
	}

	Student stu;
	while (ifs >> stu.m_Id && ifs >> stu.m_Name && ifs >> stu.m_Pwd) 
		vStu.push_back(stu);

	cout << "The current number of students is: " << vStu.size() << endl;
	ifs.close();

	// Read teacher information
	ifs.open(TEACHER_FILE, ios::in);

	Teacher tea;
	while (ifs >> tea.m_EmpId && ifs >> tea.m_Name && ifs >> tea.m_Pwd)
		vTea.push_back(tea);

	cout << "The current number of teacher is: " << vTea.size() << endl;
	ifs.close();

}

// Duplicate detection, parameter 1: check student or teacher ID, parameter 2: identity type
bool Administrator::checkRepeat(int id, int type) {
	if (type == 1) {
		// check student account
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (id == it->m_Id)
				return true;
		}
	}
	else {
		// check teacher account
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			if (id == it->m_EmpId)
				return true;
		}
	}

	return false;
}



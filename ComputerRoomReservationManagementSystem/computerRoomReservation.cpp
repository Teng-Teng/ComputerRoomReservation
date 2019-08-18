#include <fstream>
#include <string>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "administrator.h"

// Go to the administrator submenu page
void administratorMenu(Identity* &administrator) {
	while (true) {
		// Call the administrator submenu
		administrator->operMenu();

		// Casting base class pointer to derived class pointer
		Administrator* admin = (Administrator*)administrator;

		int select = 0;
		cin >> select;

		if (select == 1) {
			// Add account
			cout << "Add account" << endl;
			admin->addPerson();
		}
		else if (select == 2) {
			// View account
			cout << "View account" << endl;
			admin->showPerson();
		} 
		else if (select == 3) {
			// View computer room information
			cout << "View computer room information" << endl;
			admin->showComputer();
		}
		else if (select == 4) {
			// Clear reservation record
			cout << "Clear reservation record" << endl;
			admin->clearFile();
		}
		else {
			// Logout

			// Destroys the specified heap object
			delete administrator;
			cout << "Logout successfully!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

// Login function, parameter 1: file name, parameter 2: identity type
void login(string fileName, int type) {
	// base class pointer pointing to derived object
	Identity* person = NULL;

	// read file
	ifstream ifs;
	ifs.open(fileName, ios::in);

	// determine if the file exists
	if (!ifs.is_open()) {
		cout << "File doesn't exist!" << endl;
		ifs.close();
		return;
	}

	// prepare to accept user information
	int id = 0;
	string name;
	string pwd;

	// determine identity
	if (type == 1) {
		// student identity
		cout << "Please enter your student ID: " << endl;
		cin >> id;
	}
	else if (type == 2) {
		// teacher identity
		cout << "Please enter your teacher ID: " << endl;
		cin >> id;
	}

	cout << "Please enter username: " << endl;
	cin >> name;

	cout << "Please enter password: " << endl;
	cin >> pwd;

	// ID read from the file
	int fId;

	// name read from the file
	string fName;

	// password read from the file
	string fPwd;

	if (type == 1) {
		// verify student identity
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			// comparison with user input
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "Student login verification success!" << endl;
				system("pause");
				system("cls");

				person = new Student(id, name, pwd);

				// enter student submenu page

				return;
			}
		}
	}
	else if (type == 2) {
		// verify teacher identity
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			// comparison with user input
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "Teacher login verification success!" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);

				// enter teacher submenu page

				return;
			}
		}
	}
	else if (type == 3) {
		// verify administrator identity
		while (ifs >> fName && ifs >> fPwd) {
			// comparison with user input
			if (fName == name && fPwd == pwd) {
				cout << "Administrator login verification success!" << endl;
				system("pause");
				system("cls");

				person = new Administrator(name, pwd);

				// enter administrator submenu page
				administratorMenu(person);

				return;
			}
		}
	}

	cout << "Login verification failed!" << endl;
	system("pause");
	system("cls");

	return;
}

int main() {
	int select = 0;

	while (true) {
		cout << "========  Welcome to the computer room reservation system!  ========" << endl;
		cout << endl << "Please enter your identity" << endl;
		cout << "\t\t -------------------------------------\n" << endl;
		cout << "\t\t|                                     |\n" << endl;
		cout << "\t\t|      1. Student Representative      |\n" << endl;
		cout << "\t\t|                                     |\n" << endl;
		cout << "\t\t|      2. Teacher                     |\n" << endl;
		cout << "\t\t|                                     |\n" << endl;
		cout << "\t\t|      3. Administrator               |\n" << endl;
		cout << "\t\t|                                     |\n" << endl;
		cout << "\t\t|      0. Quit System                 |\n" << endl;
		cout << "\t\t|                                     |\n" << endl;
		cout << "\t\t -------------------------------------\n" << endl;
		cout << "Please enter your choice: " << endl;

		cin >> select;

		// according to the user choice, implement different interface
		switch (select) {
			case 1:
				// student representative 
				login(STUDENT_FILE, 1);
				break;
			case 2:
				// teacher 
				login(TEACHER_FILE, 2);
				break;
			case 3:
				// administrator 
				login(ADMIN_FILE, 3);
				break;
			case 0:
				// quit system
				cout << "Hope to see you again!" << endl;
				system("pause");
				return 0;
				break;
			default:
				cout << "Incorrect input, please re-select!" << endl;
				system("pause");
				system("cls");
				break;
		}
	}

	

	system("pause");
	return 0;
}
#include <iostream>
using namespace std;

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

				break;
			case 2:
				// teacher 

				break;
			case 3:
				// administrator 

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
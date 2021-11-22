#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//********************************************************************************
//                                 ACCOUNT INFO
//********************************************************************************

const int PASSWORD = 1234;
int balance = 10000000;

//********************************************************************************
//                               SUPPORT FUNCTIONS
//********************************************************************************

bool IsNumber(string str) {
	// detect enter
	if (str.length() == 0) {
		return false;
	}

	for (int i = 0; i < str.length(); i++) {
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

// when using cin to stream something like "1h" to an int variable, it implicitly casts it to the
// value of 1 without any fail prompt. Thus, We have to check if every character is digit (IsNumber)
int GetNumber() {
	string userInput;
	getline(cin, userInput);

	if (IsNumber(userInput)) {
		return stoi(userInput);
	}
	// Since there won't be any option with negative index, we can use -1 to represent format error
	return -1;
}

bool IsAvailable(const int options[], int choice, const int numOptions) {
	for (int i = 0; i < numOptions; i++) {
		if (choice == options[i]) {
			return true;
		}
	}
	return false;
}

//********************************************************************************
//                                   INTERFACE
//********************************************************************************

// 1: menu, 2: withdraw, 3: deposit, 4: balance
bool ValidInput(int choice, int interface, const int options[], const int numOptions) {
	string interfaceNameToPrint;
	switch (interface) {
	case 1:
		interfaceNameToPrint = "*             Menu              *";
		break;
	case 2:
		interfaceNameToPrint = "*           Withdraw            *";
		break;
	case 3:
		interfaceNameToPrint = "*            Deposit            *";
		break;
	case 4:
		interfaceNameToPrint = "*            Balance            *";
		break;
	default:
		interfaceNameToPrint = "*                               *";
		break;

	}
	if (choice == -1) {
		system("cls");

		cout << "*********************************" << endl;
		cout << "*              ATM              *" << endl;
		cout << "*********************************" << endl;
		cout << interfaceNameToPrint << endl;
		cout << "*                               *" << endl;
		cout << "*                               *" << endl;
		cout << "*      Enter a number only      *" << endl;
		cout << "*       Please type again       *" << endl;
		cout << "*                               *" << endl;
		cout << "*                               *" << endl;
		cout << "*********************************" << endl;
		cout << endl;

		system("pause");

		return false;
	}
	else {
		if (IsAvailable(options, choice, numOptions)) {
			return true;
		}

		system("cls");

		cout << "*********************************" << endl;
		cout << "*              ATM              *" << endl;
		cout << "*********************************" << endl;
		cout << interfaceNameToPrint << endl;
		cout << "*                               *" << endl;
		cout << "*                               *" << endl;
		cout << "*    There is no such option    *" << endl;
		cout << "*       Please type again       *" << endl;
		cout << "*                               *" << endl;
		cout << "*                               *" << endl;
		cout << "*********************************" << endl;
		cout << endl;

		system("pause");

		return false;
	}
}

bool Login() {
	cout << "*********************************" << endl;
	cout << "*              ATM              *" << endl;
	cout << "*********************************" << endl;
	cout << "*             Login             *" << endl;
	cout << "*                               *" << endl;
	cout << "*                               *" << endl;
	cout << "* Password: ___________________ *" << endl;
	cout << "*                               *" << endl;
	cout << "*                               *" << endl;
	cout << "*                               *" << endl;
	cout << "*********************************" << endl;
	cout << endl;
	cout << " Input : ";

	int inputPassword = GetNumber();

	if (inputPassword == PASSWORD) {
		return true;
	}
	else {
		system("cls");

		if (inputPassword == -1) {
			cout << "*********************************" << endl;
			cout << "*              ATM              *" << endl;
			cout << "*********************************" << endl;
			cout << "*             Login             *" << endl;
			cout << "*                               *" << endl;
			cout << "*                               *" << endl;
			cout << "*   Incorrect password format   *" << endl;
			cout << "*                               *" << endl;
			cout << "*                               *" << endl;
			cout << "*                               *" << endl;
			cout << "*********************************" << endl;
			cout << endl;

			return false;
		}
		else {
			cout << "*********************************" << endl;
			cout << "*              ATM              *" << endl;
			cout << "*********************************" << endl;
			cout << "*             Login             *" << endl;
			cout << "*                               *" << endl;
			cout << "*                               *" << endl;
			cout << "*       Incorrect pasword       *" << endl;
			cout << "*                               *" << endl;
			cout << "*                               *" << endl;
			cout << "*                               *" << endl;
			cout << "*********************************" << endl;
			cout << endl;
			
			return false;
		}
	}
}

int MainMenu() {
	const int MENU_OPTIONS[10] = { 1,2,3,4 };
	const int MENU_NUM_OPTIONS = 4;

	while (true) {
		int userChoice;

		system("cls");

		cout << "*********************************" << endl;
		cout << "*              ATM              *" << endl;
		cout << "*********************************" << endl;
		cout << "*             Menu              *" << endl;
		cout << "*                               *" << endl;
		cout << "* 1. Withdraw                   *" << endl;
		cout << "* 2. Deposit                    *" << endl;
		cout << "* 3. Balance                    *" << endl;
		cout << "* 4. Quit                       *" << endl;
		cout << "*                               *" << endl;
		cout << "*********************************" << endl;
		cout << endl;
		cout << " Input : ";
		userChoice = GetNumber();

		if (ValidInput(userChoice, 1, MENU_OPTIONS, MENU_NUM_OPTIONS)) {
			return userChoice;
		}

		system("pause");
	}
}

int WithdrawAfterMenu() {
	const int WITHDRAW_AFTER_OPTIONS[10] = { 1,2 };
	const int WITHDRAW_AFTER_NUM_OPTIONS = 2;
	
	while (true) {
		int userChoice;

		system("cls");

		cout << "*********************************" << endl;
		cout << "*              ATM              *" << endl;
		cout << "*********************************" << endl;
		cout << "*           Withdraw            *" << endl;
		cout << "*                               *" << endl;
		cout << "* 1. New withdrawal             *" << endl;
		cout << "* 2. Back to menu               *" << endl;
		cout << "*                               *" << endl;
		cout << "*                               *" << endl;
		cout << "*                               *" << endl;
		cout << "*********************************" << endl;
		cout << endl;
		cout << "Input: ";
		userChoice = GetNumber();

		if (ValidInput(userChoice, 2, WITHDRAW_AFTER_OPTIONS, WITHDRAW_AFTER_NUM_OPTIONS)) {
			if (userChoice == 1) {
				return 1;
			}

			// room for more options in the future
			else if (userChoice == 2) {
				return 2;
			}
		}
	}
}

void WithdrawMenu() {
	while (true) {
		system("cls");

		int moneyWithdraw, userChoice;

		cout << "*********************************" << endl;
		cout << "*              ATM              *" << endl;
		cout << "*********************************" << endl;
		cout << "*           Withdraw            *" << endl;
		cout << "*                               *" << endl;
		cout << "*   Enter the amount of money:  *" << endl;
		cout << "*     (multiple of 10,000)      *" << endl;
		cout << "*                               *" << endl;
		cout << "*     ---------------------     *" << endl;
		cout << "*                               *" << endl;
		cout << "*********************************" << endl;
		cout << endl;
		cout << "Input: ";
		moneyWithdraw = GetNumber();

		system("cls");

		if (moneyWithdraw == -1) {
			cout << "*********************************" << endl;
			cout << "*              ATM              *" << endl;
			cout << "*********************************" << endl;
			cout << "*           Withdraw            *" << endl;
			cout << "*                               *" << endl;
			cout << "*                               *" << endl;
			cout << "*     Invalid number format     *" << endl;
			cout << "*                               *" << endl;
			cout << "*                               *" << endl;
			cout << "*                               *" << endl;
			cout << "*********************************" << endl;
			cout << endl;

		}
		else {
			if (moneyWithdraw % 10000 == 0) {
				int tempBalance = balance - moneyWithdraw;

				if (tempBalance > 50000) {
					balance = tempBalance;

					cout << "*********************************" << endl;
					cout << "*              ATM              *" << endl;
					cout << "*********************************" << endl;
					cout << "*           Withdraw            *" << endl;
					cout << "*                               *" << endl;
					cout << "*                               *" << endl;
					cout << "*           Succesful           *" << endl;
					cout << "*                               *" << endl;
					cout << "*                               *" << endl;
					cout << "*                               *" << endl;
					cout << "*********************************" << endl;
					cout << endl;
					cout << "Money received:" << endl;

					int temp = moneyWithdraw;
					int cash[6][2] = { {0,500000}, {0, 200000}, {0, 100000}, {0, 50000}, {0, 20000}, {0, 10000} };

					for (int i = 0; i < 6; i++) {
						cash[i][0] = temp / cash[i][1];
						if (cash[i][0] != 0) {
							temp %= cash[i][1];
							cout << cash[i][0] << " x " << cash[i][1] << endl;
						}
					}
				}
				else {
					cout << "*********************************" << endl;
					cout << "*              ATM              *" << endl;
					cout << "*********************************" << endl;
					cout << "*           Withdraw            *" << endl;
					cout << "*                               *" << endl;
					cout << "*                               *" << endl;
					cout << "*       Insufficent funds       *" << endl;
					cout << "*                               *" << endl;
					cout << "*                               *" << endl;
					cout << "*                               *" << endl;
					cout << "*********************************" << endl;
					cout << endl;
				}
			}
			else {
				cout << "*********************************" << endl;
				cout << "*              ATM              *" << endl;
				cout << "*********************************" << endl;
				cout << "*           Withdraw            *" << endl;
				cout << "*                               *" << endl;
				cout << "*                               *" << endl;
				cout << "*    Invalid amount of money    *" << endl;
				cout << "*                               *" << endl;
				cout << "*                               *" << endl;
				cout << "*                               *" << endl;
				cout << "*********************************" << endl;
				cout << endl;
			}
		}

		system("pause");

		userChoice = WithdrawAfterMenu();

		if (userChoice == 1) {
			continue;
		}
		else if (userChoice == 2) {
			break;
		}
	}
}

int DepositAfterMenu() {
	const int DEPOSIT_AFTER_OPTIONS[10] = { 1,2 };
	const int DEPOSIT_AFTER_NUM_OPTIONS = 2;

	while (true) {
		int userChoice;

		system("cls");

		cout << "*********************************" << endl;
		cout << "*              ATM              *" << endl;
		cout << "*********************************" << endl;
		cout << "*            Deposit            *" << endl;
		cout << "*                               *" << endl;
		cout << "* 1. New Deposit                *" << endl;
		cout << "* 2. Back to menu               *" << endl;
		cout << "*                               *" << endl;
		cout << "*                               *" << endl;
		cout << "*                               *" << endl;
		cout << "*********************************" << endl;
		cout << endl;
		cout << "Input: ";
		userChoice = GetNumber();

		if (ValidInput(userChoice, 3, DEPOSIT_AFTER_OPTIONS, DEPOSIT_AFTER_NUM_OPTIONS)) {
			if (userChoice == 1) {
				return 1;
			}

			// room for more options in the future
			else if (userChoice == 2) {
				return 2;
			}
		}
	}
}

void DepositMenu() {
	while (true) {
		system("cls");

		int moneyDeposit, userChoice;

		cout << "*********************************" << endl;
		cout << "*              ATM              *" << endl;
		cout << "*********************************" << endl;
		cout << "*            Deposit            *" << endl;
		cout << "*                               *" << endl;
		cout << "*   Enter the amount of money:  *" << endl;
		cout << "*                               *" << endl;
		cout << "*     ---------------------     *" << endl;
		cout << "*                               *" << endl;
		cout << "*                               *" << endl;
		cout << "*********************************" << endl;
		cout << endl;
		cout << "Input: ";
		moneyDeposit = GetNumber();

		system("cls");

		if (moneyDeposit == -1) {
			cout << "*********************************" << endl;
			cout << "*              ATM              *" << endl;
			cout << "*********************************" << endl;
			cout << "*            Deposit            *" << endl;
			cout << "*                               *" << endl;
			cout << "*                               *" << endl;
			cout << "*     Invalid number format     *" << endl;
			cout << "*                               *" << endl;
			cout << "*                               *" << endl;
			cout << "*                               *" << endl;
			cout << "*********************************" << endl;
			cout << endl;
		}
		else if (moneyDeposit == 0) {
			cout << "*********************************" << endl;
			cout << "*              ATM              *" << endl;
			cout << "*********************************" << endl;
			cout << "*            Deposit            *" << endl;
			cout << "*                               *" << endl;
			cout << "*                               *" << endl;
			cout << "*       Nothing to deposit      *" << endl;
			cout << "*                               *" << endl;
			cout << "*                               *" << endl;
			cout << "*                               *" << endl;
			cout << "*********************************" << endl;
			cout << endl;
		}
		else {
			balance += moneyDeposit;

			cout << "*********************************" << endl;
			cout << "*              ATM              *" << endl;
			cout << "*********************************" << endl;
			cout << "*            Deposit            *" << endl;
			cout << "*                               *" << endl;
			cout << "*                               *" << endl;
			cout << "*           Succesful           *" << endl;
			cout << "*                               *" << endl;
			cout << "*                               *" << endl;
			cout << "*                               *" << endl;
			cout << "*********************************" << endl;
			cout << endl;
		}

		system("pause");

		userChoice = DepositAfterMenu();

		if (userChoice == 1) {
			continue;
		}
		else if (userChoice == 2) {
			break;
		}
	}
}

void BalanceMenu(){
	while (true) {
		const int BALANCE_OPTIONS[10] = { 1 };
		const int BALANCE_NUM_OPTIONS = 1;

		system("cls");

		int userChoice;

		cout << "*********************************" << endl;
		cout << "*              ATM              *" << endl;
		cout << "*********************************" << endl;
		cout << "*            Balance            *" << endl;
		cout << "*                               *" << endl;
		cout << "* Your balance: " << setw(16) << left << balance << "*" << endl;
		cout << "*                               *" << endl;
		cout << "* 1. Back to menu               *" << endl;
		cout << "*                               *" << endl;
		cout << "*                               *" << endl;
		cout << "*********************************" << endl;
		cout << endl;
		cout << "Input: ";
		userChoice = GetNumber();

		if (ValidInput(userChoice, 4, BALANCE_OPTIONS, BALANCE_NUM_OPTIONS)) {
			if (userChoice == 1) {
				break;
			}
		}
	}
}

bool isRunning = true;

void QuitScreen() {
	system("cls");

	cout << "*********************************" << endl;
	cout << "*              ATM              *" << endl;
	cout << "*********************************" << endl;
	cout << "*                               *" << endl;
	cout << "*                               *" << endl;
	cout << "*                               *" << endl;
	cout << "*            Goodbye            *" << endl;
	cout << "*                               *" << endl;
	cout << "*                               *" << endl;
	cout << "*                               *" << endl;
	cout << "*********************************" << endl;
	cout << endl;

	isRunning = false;
}


//********************************************************************************
//                                  MAIN PROGRAM
//********************************************************************************

int main() {
	if (Login()) {
		while (isRunning) {
			switch (MainMenu()) {
			case 1:
				WithdrawMenu();
				break;
			case 2:
				DepositMenu();
				break;
			case 3:
				BalanceMenu();
				break;
			case 4:
				QuitScreen();
				break;
			default:
				break;
			}
		}
	}

	system("pause");

	return 0;
}
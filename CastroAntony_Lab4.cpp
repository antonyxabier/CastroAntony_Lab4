// CastroAntony_Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CheckingAccount.h"
#include "CreditAccount.h"
#include "SavingsAccount.h"
#include <fstream>

//Display balance method to show accounts balances 
void displayBalance(CheckingAccount* checking, SavingsAccount* savings, CreditAccount* credit) {

	std::cout << "\nAccount balance: \n";
	std::cout << "Checking account balance: $" << checking->GetBalance() << "\n";
	std::cout << "Savings account balance: $" << savings->GetBalance() << "\n";
	std::cout << "Credit account balance: $" << credit->GetBalance() << "\n";

}

void withdraw(BaseAccount* account, float amount) {
	account->Withdraw(amount);
}

void deposit(BaseAccount* account, float amount) {
	account->Deposit(amount);
	
}

void BinaryOut(CheckingAccount* checkingAccount, SavingsAccount* savingsAccount, CreditAccount* creditAccount) {
	//Write the balances to the file
	std::ofstream binout; 
	binout.open("balances.bin", std::ios_base::binary);

	if (binout.is_open()) {

		//Write checking account balance to the file
		float checkingBalance = checkingAccount->GetBalance();
		binout.write(reinterpret_cast<const char*>(&checkingBalance), sizeof(float));

		//Write savings account balance to the file
		float savingsBalance = savingsAccount->GetBalance();
		binout.write(reinterpret_cast<const char*>(&savingsBalance), sizeof(float));

		//Write credit account balance to the file
		float creditBalance = creditAccount->GetBalance();
		binout.write(reinterpret_cast<const char*>(&creditBalance), sizeof(float));

		binout.close();

		std::cout << "\nBalances has been written.\n";
	}
	else {
		std::cout << "File could not be opened.\n";
	}
}

void BinaryIn(CheckingAccount* checkingAccount, SavingsAccount* savingsAccount, CreditAccount* creditAccount) {
	std::ifstream bin;

	bin.open("balances.bin", std::ios_base::binary);

	if (bin.is_open()) {
		bin.seekg(0, std::ios_base::end);
		int fileSize = static_cast<int>(bin.tellg());

		if (fileSize == 3 * sizeof(float)) {
			bin.seekg(0, std::ios_base::beg);

			//Read checking account balance to the file
			float checkingBalance;
			bin.read(reinterpret_cast<char*>(&checkingBalance), sizeof(float));

			//Read savings account balance to the file
			float savingsBalance;
			bin.read(reinterpret_cast<char*>(&savingsBalance), sizeof(float));

			//Read credit account balance to the file
			float creditBalance;
			bin.read(reinterpret_cast<char*>(&creditBalance), sizeof(float));

			bin.close();

			checkingAccount->Deposit(checkingBalance);
			savingsAccount->Deposit(savingsBalance);
			creditAccount->Deposit(checkingBalance);

			std::cout << "Balances read from file.\n";
		}
		else {
			std::cout << "Invalid file size.\n";
		}

	}
	else {
		std::cout << "File could not be opened.\n";
	}
}
int main()
{
	//Memory leak detection code
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(-1); 
	_CrtDumpMemoryLeaks();

	//New instance of each CheckingAccount, SavingsAccount, and CreditAccount
	CheckingAccount* checkingAccount = new CheckingAccount();
	SavingsAccount* savingsAccount = new SavingsAccount();
	CreditAccount* creditAccount = new CreditAccount();

	//Read balances from file
	BinaryIn(checkingAccount, savingsAccount, creditAccount);

	//Initialize new instances with the amount I want
	checkingAccount->Deposit(2500.0f);
	savingsAccount->Deposit(1300.0f);
	creditAccount->Deposit(2300.0f);

	//Clear screen
	std::cout << "\x1B[2J\x1B[H";

	//int variable for menu choice
	int choice;

	//int variable for account choice
	int accountChoice;

	//float variable for amount
	float amount;

	//bool variable for exit menu
	bool exitMenu = false;

	//while loop for the menu 
	while (!exitMenu) {
		
		
		std::cout << "\nWelcome to your banking app!\n";
		displayBalance(checkingAccount, savingsAccount, creditAccount);

		std::cout << "\nMenu:\n";
		std::cout << "1. Withdraw.\n";
		std::cout << "2. Deposit.\n";
		std::cout << "3. Exit.\n";

		//while loop to validate input 
		while (true) {
			std::cout << "\nPlease enter the number for the operation you want to perform: ";
			std::cin >> choice;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				std::cout << "Invalid input. Please enter a number.\n";
			}
			else if (choice < 1 || choice > 3) {
				std::cout << "Invalid choice. Please enter a number between 1 and 3.\n";
			}
			else {
				break;
			}
		}
		//switch statement for the menu choice
		switch (choice) {
			//case 1: select the account for withdrawal
		case 1:
			std::cout << "\nPlease select the account for withdrawal.\n";
			std::cout << "1. Checking account.\n";
			std::cout << "2. Savings account.\n";
			std::cout << "3. Credit account.\n";

			//while loop to validate account input
			while (true) {
				std::cout << "\nPlease enter the number for the account: ";
				std::cin >> accountChoice;

				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(INT_MAX, '\n');
					std::cout << "Invalid input. Please enter a number.\n";
				}
				else if (accountChoice < 1 || accountChoice > 3) {
					std::cout << "Invalid account choice. Please enter a number between 1 and 3.\n";
				}
				else {
					break;
				}
			}

			std::cout << "\nPlease enter the amount you want to withdraw: $";
			std::cin >> amount;

			//Switch statement for the account choice, calling the withdraw method
			switch (accountChoice) {
				//case 1: if the user selects 1, withdraw from checking account 
			case 1: 
				withdraw(checkingAccount, amount);
				break;
				//case 2: if user selects 2, withdraw from savings account
			case 2:
				withdraw(savingsAccount, amount);
				break;
				//Case 3: if user selects 3, withdraw from credit account
			case 3:
				withdraw(creditAccount, amount);
				break;
				
			default:
				std::cout << "\nInvalid account choice.\n";
				break;
			}
			
			break;
          
	   //Case 2: select the account for deposit 
		case 2:
			std::cout << "\nPlease select the account for deposit.\n";
			std::cout << "1. Checking account.\n";
			std::cout << "2. Savings account.\n";
			std::cout << "3. Credit account.\n";

			//While loop to validate account input 
			while (true) {
				std::cout << "\nPlease enter the number for the account: ";
				std::cin >> accountChoice;

				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(INT_MAX, '\n');
					std::cout << "Invalid input. Please enter a number.\n";
				}
				else if (accountChoice < 1 || accountChoice > 3) {
					std::cout << "Invalid account choice. Please enter a number between 1 and 3.\n";
				}
				else {
					break;
				}
			}

			std::cout << "\nPlease enter the amount you want to deposit: $";
			std::cin >> amount;

			//Switch statement for the account choice, calling the withdraw method
			switch (accountChoice) {

				//case 1: if the user selects 1, deposit to checking account
			case 1:
				deposit(checkingAccount, amount);
				break;

				//case 2: if user selects 2, deposit to savings account
			case 2:
				deposit(savingsAccount, amount);
				break;

				//Case 3: if user selects 3, deposit to credit account
			case 3:
				deposit(creditAccount, amount);
				break;

			default:
				std::cout << "\nInvalid account choice.\n";
				break;
			}
			break;
		//Case 3: if the user selects 3, exit	
		case 3:
			std::cout << "\nThank you for using your safest banking app!\n";

			BinaryOut(checkingAccount, savingsAccount, creditAccount);

			//Set exitMenu to true
			exitMenu = true;
			break;

		default:
			std::cout << "\nInvalid option! Please enter a valid option.\n";
			break;
		}
		//Display the accounts balances
		displayBalance(checkingAccount, savingsAccount, creditAccount);

		//Clean up memory
		delete checkingAccount;
		delete savingsAccount;
		delete creditAccount;
	}

	//return 0
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include "CheckingAccount.h"
#include <iostream>

//Constructor
CheckingAccount::CheckingAccount()
{
}

//destructor
CheckingAccount::~CheckingAccount()
{
}

//override withdraw function from BaseAccount 
void CheckingAccount::Withdraw(float amount)
{
	//If more than 10 withdrawals are made
	if (numWithdrawals > 10) {

		//Checking account charges a $5 fee
		BaseAccount::Withdraw(amount + 5.0f);

		std::cout << "Withdrawal fee of $5 applied.\n";
	}
	//Otherwise just call the withdraw function from BaseAccount without adding any fees
	else {
		BaseAccount::Withdraw(amount);

		std::cout << "$" << amount << " withdrawn from Checking Account.\n";
		
	}
}

//Override the deposit method from BaseAccount
void CheckingAccount::Deposit(float amount)
{
	BaseAccount::Deposit(amount);
	std::cout << "$" << amount << " deposited to Checking Account.\n";
}


#include "SavingsAccount.h"
#include <iostream>


//Constructor
SavingsAccount::SavingsAccount()
{
}

//Destructor
SavingsAccount::~SavingsAccount()
{
}

//Override the withdraw function from BaseAccount
void SavingsAccount::Withdraw(float amount)
{
	//Do not allow more than 3 withdrawals 
	if (numWithdrawals >= 3) {

		std::cout << "Withdrawal limit reached for this account.\n";
	}
	//Otherwise call the withdraw from BaseAccount without any restrictions
	else {
		BaseAccount::Withdraw(amount);

		std::cout << "$" << amount << " withdrawn from Savings Account.\n";
	}
}

//Override the deposit method from BaseAccount
void SavingsAccount::Deposit(float amount)
{
	BaseAccount::Deposit(amount);
	std::cout << "$" << amount << " deposited to Savings Account.\n";
}

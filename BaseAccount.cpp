#include "BaseAccount.h"
#include <iostream>

//Constructor
BaseAccount::BaseAccount() : balance(0.0f), numWithdrawals(0)
{
}

//Destructor
BaseAccount::~BaseAccount()
{
}

//Withdraw method 
void BaseAccount::Withdraw(float amount)
{
	//decreases balance by amount
	balance -= amount;

	//adds 1 to number of withdrawals
	numWithdrawals++;
	
}

//Deposit method
void BaseAccount::Deposit(float amount)
{
	//increases balance by amount
	balance += amount;
	
}

//Get balance method
float BaseAccount::GetBalance() const
{
	//returns the balance
	return balance;
}



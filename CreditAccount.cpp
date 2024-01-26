#include "CreditAccount.h"
#include <iostream>


//Constructor
CreditAccount::CreditAccount() : amountSpent(0)
{
}

//Destructor
CreditAccount::~CreditAccount()
{
}

//Override withdraw function from BaseAccount
void CreditAccount::Withdraw(float amount)
{
	//The amount spent has a limit of $40 
	if ((amountSpent + amount) > 40.0f) {

		//charge a $5000 fee if you go over that spending limit
		BaseAccount::Withdraw(amount + 5000.0f);

		std::cout << "Exceeded spending limit. $5000 fee applied.\n";
	}
	//Otherwise just call the withdraw method from BaseAcount withou any extra fees
	else {
		BaseAccount::Withdraw(amount);
		
		amountSpent += amount;

		std::cout << "$" << amount << " withdrawn from Credit Account.\n";
	}
}

//Override the deposit method from BaseAccount
void CreditAccount::Deposit(float amount)
{
	BaseAccount::Deposit(amount);
	std::cout << "$" << amount << " deposited to Credit Account.\n";
}

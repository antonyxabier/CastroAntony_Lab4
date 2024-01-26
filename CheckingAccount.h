#pragma once
#include "BaseAccount.h"
class CheckingAccount : public BaseAccount
{
public:
	//Constructor
	CheckingAccount();

	//Destructor
	~CheckingAccount();

	//Override the withdraw function from BaseAccount
	void Withdraw(float amount) override;

	//Override the deposit function from BaseAccount
	virtual void Deposit(float amount) override;
};


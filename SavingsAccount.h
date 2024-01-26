#pragma once
#include "BaseAccount.h"
class SavingsAccount : public BaseAccount
{
public:

	//Constructor
	SavingsAccount();

	//Destructor
	~SavingsAccount();

	//Override withdraw function from BaseAccount
	void Withdraw(float amount) override;

	//Override the deposit function from BaseAccount
	virtual void Deposit(float amount) override;
};


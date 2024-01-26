#pragma once
#include "BaseAccount.h"
class CreditAccount : public BaseAccount
{
private:
	//int for the amount spent
	int amountSpent;

public:
	//Constructor
	CreditAccount();

	//Destructor
	~CreditAccount();

	//Override withdraw function from BaseAccount
	void Withdraw(float amount) override;

	//Override the deposit function from BaseAccount
	virtual void Deposit(float amount) override;
};


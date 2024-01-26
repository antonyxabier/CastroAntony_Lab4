#pragma once
class BaseAccount
{
protected:
	//float data member for account balance initialized to zero
	float balance = 0.0f;

	//int for the number of withdrawals initialized to zero
	int numWithdrawals = 0;

public:
	//Constructor
	BaseAccount();

	//Destructor
	virtual ~BaseAccount();

	//virtual void to withdraw 
	virtual void Withdraw(float amount);

	//virtual void to deposit
	virtual void Deposit(float amount);

	//float to get the balace
	float GetBalance() const;
};


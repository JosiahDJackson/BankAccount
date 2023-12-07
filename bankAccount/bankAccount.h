#pragma once
class BankAccount
{
private:
	double balance, deposit, withdraw, interestRate;
public:
	void dep();
	void wdraw();
	void getInterest();
	void updateBalance();
	void print();
	void getAccountNumber();
	void getAccountHolderName();
	void getAccountType();
	void getBalance();
	void getInterestRate();
};
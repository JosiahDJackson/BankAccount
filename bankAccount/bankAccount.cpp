#include <iostream>
#include <string>
#include <map>

class bankAccount {
private:
	std::string actName;
	int actNum;
	std::string actType;
	double bal;
	double intRate;

public:
	static int nextActNum;

	bankAccount() {
		actNum = nextActNum++;
		std::cout << "Enter Account Holders Name: \n"; 
		std::getline(std::cin >> std::ws, actName);
		std::cout << "Enter Account Type: " << std::endl;
		std::cin >> actType;
		std::cout << "Enter Account Balance: " << std::endl;
		std::cin >> bal;
		std::cout << "Enter Interest Rate: " << std::endl;
		std::cin >> intRate;
	}

	
	int deposit();
	int withdraw();
	void getInt();
	void updateBal();
	void print();
	int getActNum();
	void getActName();
	void getActType();
	void getBal();
	void getIntRate();
};

int main() {
	int size;
	std::cout << "Enter Number of Accounts: " << std::endl;
	std::cin >> size;

	std::map<int, bankAccount> accounts;

	for (int n = 0; n < size; n++) {

		int i = bankAccount::nextActNum;
		accounts.emplace(i, bankAccount{});

		if (accounts.find(i) != accounts.end()) {
			bankAccount instance = accounts[i];
			std::cout << "Congratulations, New Account Number: " << instance.getActNum() << "\n\n\n";
		}

		system("PAUSE");
	}

	{
	m:
		int choice;


		std::cout << "Main Menu\n";
		std::cout << "1) Deposit\n";
		std::cout << "2) Withdraw\n";
		std::cout << "3) Display Interest\n";
		std::cout << "4) Add Interest to Account\n";
		std::cout << "5) Print\n";
		std::cout << "6) Get Account Name\n";
		std::cout << "7) Get Account Type\n";
		std::cout << "8) Current Balance\n";
		std::cout << "9) Interest Rate\n";
		std::cout << "10)Exit\n";

		std::cin >> choice;



		switch (choice) {
		case 1: {
			int userAct;
			std::cout << "Enter Account Number: " << std::endl;
			std::cin >> userAct;

			auto it = accounts.find(userAct);
			if (it != accounts.end()) {
				bankAccount& instance = it->second;
				instance.deposit();
			}
			else {
				std::cout << "Account not found." << std::endl;
			}
			break;
		}

		case 2:
		{
			int userAct;
			std::cout << "Enter Account Number: " << std::endl;
			std::cin >> userAct;

			auto it = accounts.find(userAct);
			if (it != accounts.end()) {
				bankAccount& instance = it->second;
				instance.withdraw();
			}
			else {
				std::cout << "Account not found." << std::endl;
			}
			break;
		}

		case 3:
		{
			int userAct;
			std::cout << "Enter Account Number: " << std::endl;
			std::cin >> userAct;

			auto it = accounts.find(userAct);
			if (it != accounts.end()) {
				bankAccount& instance = it->second;
				instance.getInt();
			}
			else {
				std::cout << "Account not found." << std::endl;
			}
			break;
		}
		case 4:
		{
			int userAct;
			std::cout << "Enter Account Number: " << std::endl;
			std::cin >> userAct;

			auto it = accounts.find(userAct);
			if (it != accounts.end()) {
				bankAccount& instance = it->second;
				instance.updateBal();
			}
			else {
				std::cout << "Account not found." << std::endl;
			}
			break;
		}
		case 5:
		{
			int userAct;
			std::cout << "Enter Account Number: " << std::endl;
			std::cin >> userAct;

			auto it = accounts.find(userAct);
			if (it != accounts.end()) {
				bankAccount& instance = it->second;
				instance.print();
			}
			else {
				std::cout << "Account not found." << std::endl;
			}
			break;
		}
		case 6:
		{
			int userAct;
			std::cout << "Enter Account Number: " << std::endl;
			std::cin >> userAct;

			auto it = accounts.find(userAct);
			if (it != accounts.end()) {
				bankAccount& instance = it->second;
				instance.getActName();
			}
			else {
				std::cout << "Account not found." << std::endl;
			}
			break;
		}
		case 7:
		{
			int userAct;
			std::cout << "Enter Account Number: " << std::endl;
			std::cin >> userAct;

			auto it = accounts.find(userAct);
			if (it != accounts.end()) {
				bankAccount& instance = it->second;
				instance.getBal();
			}
			else {
				std::cout << "Account not found." << std::endl;
			}
			break;
		}
		case 8:
		{
			int userAct;
			std::cout << "Enter Account Number: " << std::endl;
			std::cin >> userAct;

			auto it = accounts.find(userAct);
			if (it != accounts.end()) {
				bankAccount& instance = it->second;
				instance.getBal();
			}
			else {
				std::cout << "Account not found." << std::endl;
			}
			break;
		}
		case 9:
		{
			int userAct;
			std::cout << "Enter Account Number: " << std::endl;
			std::cin >> userAct;

			auto it = accounts.find(userAct);
			if (it != accounts.end()) {
				bankAccount& instance = it->second;
				instance.getIntRate();
			}
			else {
				std::cout << "Account not found." << std::endl;
			}
			break;
		}
		case 10:
		{
			exit(0);
		}
		default: {
			std::cout << "Please select from the given options\n";
		}
		}
		goto m;

		return 0;
	}
}

int bankAccount::nextActNum = 1000;

int bankAccount::deposit()
{
	int amt = 0;
	std::cout << "Enter Deposit Amount : " << std::endl;
	std::cin >> amt;
	bal = amt + bal;
	return 0;
}

int bankAccount::withdraw()
{
	int amt = 0;
	std::cout << "Enter Withdrawal Amount : " << std::endl;
	std::cin >> amt;

	if (amt < bal) {
		bal = bal - amt;
	}
	else
	{
		std::cout << "You too broke for that ma boi" << std::endl;
	}
	return 0;
}

void bankAccount::getInt()
{
	double intOwed;
	intOwed = bal * (intRate / 100);
	std::cout << "Interest owed: " << intOwed << std::endl;
}

void bankAccount::updateBal()
{
	double intOwed;
	intOwed = bal * (intRate / 100);
	bal = intOwed + bal;
	std::cout << "New balance: " << bal << std::endl;
}

void bankAccount::print()
{
	std::cout << "\nAccount Holder Name: " << actName << std::endl;
	std::cout << "Account Type: " << actType << std::endl;
	std::cout << "Current Balance: " << bal << std::endl;
	std::cout << "Current Interest Rate: " << intRate << "%\n" << std::endl;
	
}

int bankAccount::getActNum()
{
	return actNum;
}

void bankAccount::getActName()
{
	std::cout << "Account Holder Name: " << actName << std::endl;
}

void bankAccount::getActType()
{
	std::cout << "Account Type: " << actType << std::endl;
}

void bankAccount::getBal()
{
	std::cout << "Current Balance: " << bal << std::endl; 
}

void bankAccount::getIntRate()
{
	std::cout << "Current Interest Rate: " << intRate << "%" << std::endl;
}

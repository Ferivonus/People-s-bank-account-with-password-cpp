#pragma once

class People
{
private:
	string name, surname, fullName;
	int money = 0, age = 0;
	int Account = 0;
	void Creating_BankAccount();
	Bank Personal_Bank_Account;

public:
	People(string, string, int, int);
	~People();
	void Manage_BankAccount(int);
	bool BankAccountCheck();
};

People::People(string name, string surname, int money, int age)
{
	this->name = name;
	this->surname = surname;
	fullName = name + " " + surname;
	this->age = age;
	this->money = money;
	if (age >= 18)
	{
		Creating_BankAccount();
	}
} 
void People::Creating_BankAccount()
{
	
	cout << "Would " << fullName << " wants to create an bank Account:" << endl
		<< "Type 1 for creating," << endl
		<< "Type 0 for not creating: ";
	cin >> Account;
	if (Account == 1)
	{
		int ToBank = 0;
		cout << "How much money would want to deposit " << fullName << ": ";
		cin >> ToBank;
		if (ToBank <= money)
		{
			Personal_Bank_Account.Set_Bank(fullName, ToBank);
			money -= ToBank;
		}
		else
		{
			ToBank = 0;
			cout << "You don't have enough money, but we create 0$ bank acoount" << endl;
			Personal_Bank_Account.Set_Bank(fullName, ToBank);
		}
		
	}
	else if (Account == 0)
	{
		cout << fullName << " Didn't want to create a bank account." << endl;
	}
	else {
		cout << "You made an error when you creating your account." << endl << "So, we are not creating a account for you." << endl;
	}
}
void People::Manage_BankAccount(int MoneyFromBucket)
{
	if (Account)
	{
		Personal_Bank_Account.Access(MoneyFromBucket);
		money += Personal_Bank_Account.take_Your_Money();
	}
	else
	{
		cout << fullName << " don't have a bank account!!" << endl;
	}

}

People::~People()
{
}

bool People::BankAccountCheck() {
	if (Account == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
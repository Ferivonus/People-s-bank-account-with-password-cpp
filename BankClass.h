#pragma once

class Bank
{
private:
	static int id;
	int my_id = 0, bank_Money = 0, money_will_taken = 0, money;
	string name = "", password = "";
	void Deposit(int, int);
	void Withdraw(int);
	void MyBankMoney() { cout << "user of " << my_id << " have " << bank_Money << "$ on The bank."; }
public:
	Bank(){}
	void Set_Bank(string, int);
	void Access(int);
	int take_Your_Money();
	~Bank(){}


};

int Bank::id = 0;



void Bank::Set_Bank(string name, int money)
{
	bank_Money = money;
	id++;
	my_id = id;
	cin.ignore();
	cout << "Type your new password: ";
	getline(cin, password);
}

void Bank::Deposit(int To_Bank, int MoneyFromBucket)
{
	if (MoneyFromBucket >= To_Bank)
	{
		bank_Money += To_Bank;
		MyBankMoney();
		money_will_taken -= To_Bank;
	}
	else
	{
		cout << "You cannot deposit " << To_Bank << "$ to your bank account, because you just have " << MoneyFromBucket << "$";
	}
}

void Bank::Withdraw(int From_Bank)
{
	if (bank_Money >= From_Bank)
	{
		bank_Money -= From_Bank;
		money_will_taken = From_Bank;
		cout << "You withdraw " << money_will_taken << "$"<<endl;
		MyBankMoney();
	}
	else
	{
		cout << "You cannot take money more thank you have in your bank Account!!" << endl
			 << "In your bank account, you have only " << bank_Money << "$ which you can use!"<< endl;
		money_will_taken = 0;
		MyBankMoney();
	}
}

void Bank::Access(int MoneyFromBucket) {
	string check = "  ";
	cout << "Type your password for accessing your account: ";
	getline(cin, check);
	if (check == password)
	{
		int want=3;
		MyBankMoney();
		cout << endl << "what will you want to do?" << endl
			<< "For depozit, type 1," << endl
			<< "For Withdraw, type 2:";
		cin >> want;
		if (want ==1)
		{
			cout << "how many money would you want to depozit: ";
			cin >> want;
			Deposit(want, MoneyFromBucket);
		}
		else if (want ==2)
		{
			cout << "how many money would you want to Withdraw: ";
			cin >> want;
			Withdraw(want);
		}
		
	}
	else
	{
		cout << "You accessed your Bank account, but you miss wrote what would you want with your bank account!!" << endl;
	}
}
int Bank::take_Your_Money()
{
	int Money = money_will_taken;
	money_will_taken = 0;
	return Money;
}
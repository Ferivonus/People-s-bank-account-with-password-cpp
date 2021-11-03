// 
// BankAccount with password 
//

#include <iostream>
#include <string>
using namespace std;
#include "BankClass.h"
#include "PeopleClass.h"

int main()
{
    string name = "fahrettin", surname = "basturk";
    int money = 5000, age = 22;
    People Fahrettin(name, surname, money, age);
    if (Fahrettin.BankAccountCheck())
    {
        Fahrettin.Manage_BankAccount(money);
    }
    return 0;
}


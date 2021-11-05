// 
// codded by Fahrettin Baştürk.
// BankAccount with password
// version: 2.0.0
//

#include <iostream>
#include <string>
using namespace std;
#include "BankClass.h"
#include "PeopleClass.h"
int PeopleCounterFunc();


int main()
{
    string name = "", surname = "";
    int money = 0, age = 0, HowManyPeople;
    HowManyPeople = PeopleCounterFunc();
    People* MyPeople[5] = { 0 };
    for (int i = 0; i < HowManyPeople; i++)
    {
        i++;
        cout << "Type " << i << " Person's name and surname: ";
        i--;
        cin >> name >> surname;
        cout << "type " << name + " " + surname << "'s money and age: ";
        cin >> money >> age;
        MyPeople[i] = new People(name, surname, money, age);
    }
    return 0;
}


int PeopleCounterFunc()
{
    int returner;
    cout << "How many people do we have: ";
    cin >> returner;
    return returner;
}


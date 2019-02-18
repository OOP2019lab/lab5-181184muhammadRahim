#include<iostream>
#include"Header.h"
using namespace std;
#include<string>

int main()
{
	cout << "do you want to make a new account? if yes press 1 and then enter" << endl;
	int n = 0;
	cin >> n;
	string m;
	int num;
	if (n == 1)
	{
		cout << "please enter name?" << endl;
		cin >> m;
		cout << "please enter account no." << endl;
		cin >> num;
	}
	bankaccount b1(m, num);
	b1.print();
	b1.withdraw(2000);
	b1.deposit(250000);
	b1.deposit(50000);
	b1.print();
	for (int i = 0; i < 12; i++)
	{
		b1.deposit(1000);
		b1.print();
	}
	system("pause");
}
#include<iostream>
#include"Header.h"
using namespace std;
#include<string>
bool flag = false;
bankaccount::bankaccount(string n, int num)//constructor
{
	cout << "constructor is invoked" << endl;
	name = n;
	accno = num;
	ballimit = 200000;
	balance = -1;
	trans = new float[10];
	for (int i = 0; i < 10; i++)
	{
		trans[i] = 0;
	}
	transcount = 0;

}
void bankaccount::print() const//print user information
{
	cout << "account holders name:" << name << endl;
	cout << "account number:" << accno << endl;
	cout << "balance limit:" << ballimit<<endl;
	if (balance == -1)
	{
		cout << "no deposits made" << endl;
	}
	else
		cout << "account balance:" << balance << endl;
	if (transcount == 0)
	{
		cout << "no transaction history" << endl;
	}
	else if(transcount>0)
	{
		for (int i = 1; i <= transcount; i++)
		{
			if (trans[i-1] > 0)
			{
				cout << "deposit" << i << "=" << trans[i]<<endl;
			}
			else if (trans[i-1] < 0)
			{
				cout << "withdrawl" << i << "=" << trans[i]<<endl;
			}
		}
	}

}
void bankaccount::transcapacity()//increase array capacity
{
	cout << "transaction capacity is invoked" << endl;
	float *temp = new float[transcount * 2];
	for (int i = 1; i <= transcount; i++)
	{
		temp[i - 1] = trans[i - 1];
	}
	delete[] trans;
	trans = new float[transcount * 2];
	for (int i = 1; i <= transcount; i++)
	{
		trans[i - 1] = temp[i - 1];
	}
	delete[] temp;
	temp = NULL;
}
void bankaccount::deposit(int num)//deposit money and make changes
{
	if (transcount > 7 && flag==false)
	{
		flag = true;
		transcapacity();
	}
	if (num > ballimit)
	{
		cout << "deposit amount exceeds balance limit" << endl;
	}
	else if (num <= ballimit)
	{
		transcount++;
		trans[transcount] = num;
		if (balance == -1)
		{
			balance = num;
		}
		else if (balance != -1)
		{
			balance = balance + num;
		}
		cout << "transaction succesful" << endl;
	}
}
void bankaccount::withdraw(int num)//withdraw money and make changes
{
	if (transcount > 7 && flag == false)
	{
		flag = true;
		transcapacity();
	}
	if (num <= balance && num>0)
	{
		balance = balance - num;
		transcount++;
		trans[transcount] = (-1)*num;
	}
	else if (num > balance)
	{
		cout << "error: withdrawl amount exceeds total balance" << endl;
	}
}
bankaccount::~bankaccount()//destructor
{
	cout << "****destructor is invoked***" << endl;
	delete[] trans;

}
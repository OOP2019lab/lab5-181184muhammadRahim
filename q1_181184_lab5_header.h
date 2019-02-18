#include<iostream>
using namespace std;
#include<string>
class bankaccount
{
public:
       bankaccount(string n, int num);//initializer(constructor)
	   void print() const;//print all information about user
	   void deposit(int num);//deposit money
	   void withdraw(int num);//withdrawal money
	   ~bankaccount();//destructor
	

private:
	string name;
	int accno;
	float balance;
	float ballimit;
	float *trans;
	int transcount;
	void transcapacity()//increase capacity;

};


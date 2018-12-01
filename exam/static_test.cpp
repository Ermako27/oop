#include <iostream>

// статическая переменная в классе будет иметь одно и тоже значение для всех экземпляров этого класса

class StatClass
{
public:
	int common = 0;
	// static int stat = 0; // error: ISO C++ forbids in-class initialization of non-const static member ‘StatClass::stat’
	const static int constStat = 0;

};


class ConstClass
{
public:
	ConstClass(){}
	const int i = 0;
	// const int j; // так нельзя
	const int j = 9;
	int k = 0; /// инициализация неконстантного члена класса
	int l;
};

int main()
{
	ConstClass cc;
	std::cout << "cc.i: " <<cc.i << "\n";
	// cc.j = 9; // так нельзя 
	std::cout << "cc.j: " <<cc.j << "\n";

	//////////////////////////////////////////////////
	ConstClass cc2;
	std::cout << "cc2.k: " << cc2.k << "\n";
	cc2.k = 9;
	std::cout <<  "cc2.k: " <<cc2.k << "\n";


	ConstClass cc3;
	std::cout << "cc3.l: " <<cc3.l << "\n";
	cc3.l = 9;
	std::cout << "cc3.l: " <<cc3.l << "\n";
	return 0;
}
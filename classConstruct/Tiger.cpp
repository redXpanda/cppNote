#include <iostream>
#include "Tiger.h"
using namespace std;


Tiger::Tiger()
{
	cout << "Tiger construct." << endl;

	m_damege = 0;
}

Tiger::Tiger(int damege)
{
	cout << "Tiger damege construct." << endl;

	m_damege = damege;
}


Tiger::~Tiger()
{
	cout << "Tiger destruct." << endl;
}

#include <iostream>
#include "Animal.h"
using namespace std;


Animal::Animal()
{
	cout << "Animal construct." << endl;
}


Animal::~Animal()
{
	cout << "Animal destruct." << endl;
}
#include <iostream>

#include <map>
#include <string>
using namespace std;



struct Maid
{
	unsigned int id;
	string name;
};


class GameTable
{
public:
protected:
private:
};

int main()
{
	
	map<int, string> _strmap;
	map<int, Maid*> _maids;
	map<int, GameTable*> _tables;

	bool ret = true;

	ret |= false;


	auto one = _maids[648];


	//auto ret2 = 0x2 & 0x2;2
	//优先级错误
	bool ret2 = 0x2 & 0x2 == 2;

	bool ret3 = 0x2 & 0x2 == 2;
	return 0;
}
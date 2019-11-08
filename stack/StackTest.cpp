// cppNote.cpp: 定义应用程序的入口点。
//
#include <iostream>

#include <stack>

using namespace std;

int main()
{
	cout << "Hello CMake。" << endl;

	stack<int> stackInt;
	stackInt.push(1);
	stackInt.push(2);
	stackInt.push(3);

	auto con = stackInt._Get_container();

	return 0;
}

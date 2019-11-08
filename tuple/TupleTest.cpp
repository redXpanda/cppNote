#include <iostream>
#include <tuple>

using  result = std::tuple<int, char, double>;


result getResult()
{
	return {5,'a',5.5};
}



int main()
{
	auto k = getResult();

	

	int a = 0;
	std::cin >> a;



	return 0;
}
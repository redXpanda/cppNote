// CMakeProject2.cpp: 定义应用程序的入口点。
//

#include "CMakeProject2.h"

#include <vector>
using namespace std;

std::vector<int> getRandomUnrepeatVec(int low, int high, int len)
{
	vector<int> out;
	if (high > low && low >= 0)
	{
		if (len <= high - low + 1)	//0-5,6个数字
		{
			do
			{
				int n = (rand() % (high - low + 1)) + low;
				if (find(out.begin(), out.end(), n) == out.end())
				{
					out.push_back(n);
				}
			} while (out.size() < len);

		}
	}



	return out;
}




int main()
{
	cout << "Hello CMake。" << endl;

	auto ret = getRandomUnrepeatVec(1, 8, 10);



	return 0;
}

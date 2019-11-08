// cppNote.cpp: 定义应用程序的入口点。
//
#include <iostream>

#include <vector>

#include <chrono>

#include <thread>

#include <ctime>

#include <iomanip>

using namespace std;
using namespace chrono;

int main()
{

	auto p1 = chrono::system_clock::now();

	//this_thread::sleep_for(chrono::seconds(5));

	auto p2 = chrono::system_clock::now();

	auto d = p2 - p1;

	auto ds = chrono::duration_cast<chrono::milliseconds>(d).count();

	system_clock::time_point now = system_clock::now();
	
	std::time_t last = system_clock::to_time_t(now - std::chrono::hours(24));
	std::time_t next = system_clock::to_time_t(now + std::chrono::hours(24));
	std::cout << "One day ago, the time was " << put_time(std::localtime(&last), "%F %T") << '\n';
	std::cout << "Next day, the time was " << put_time(std::localtime(&next), "%F %T") << '\n';

	//localtime_s warning
	cout << std::put_time(std::localtime(&last), "%Y-%m-%d %X") << endl;	
	cout << std::put_time(std::localtime(&last), "%Y-%m-%d %H.%M.%S") << endl;


	return 0;
}

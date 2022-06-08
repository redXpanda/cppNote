//虚函数表相关，包含函数指针，typedef相关知识点
#include <iostream>

int add(int a, int b) {
	return a + b;
};

int sub(int a, int b) {
	return a - b;
}

//定义一个函数指针的名字
typedef int (*intByIntFunc)(int, int);

//执行一个传入的函数
int ope(int a, int b, int (*ptr)(int, int)) {
	return ptr(a, b);
}

//使用typedef的定义方法,没找到这种正确写法
//int ope2(int a, int b, intByIntFunc) {
//	return intByIntFunc(a, b);
//}

using namespace std;

class Base
{
public:
	Base() { cout << "Base construct" << endl; }
	virtual void f() { cout << "Base::f()" << endl; }
	virtual void g() { cout << "Base::g()" << endl; }
	virtual void h() { cout << "Base::h()" << endl; }
	virtual ~Base() {}

};


int main()
{
	//intByIntFunc ptr = add;
	//int out = ptr(5, 6);
	//ptr = sub;
	//out = ptr(out, 1);
	//out = ope(out, 1, ptr);
	//printf("最终结果: %d", out);


	typedef void (*Fun)();  //定义一个函数指针类型变量类型 Fun  
	Base* b = new Base();
	//虚函数表存储在对象最开始的位置  
	//将对象的首地址输出  
	cout << "首地址：" << *(int*)(&b) << endl;

	Fun funf = (Fun)(*(int*)*(int*)b);
	Fun fung = (Fun)(*((int*)*(int*)b + 1));//地址内的值 即为函数指针的地址，将函数指针的地址存储在了虚函数表中了  
	Fun funh = (Fun)(*((int*)*(int*)b + 2));

	funf();
	fung();
	funh();

	cout << (Fun)(*((int*)*(int*)b + 4)) << endl; //最后一个位置为0 表明虚函数表结束 +4是因为定义了一个 虚析构函数  

	delete b;



	return 0;
}
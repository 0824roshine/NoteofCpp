/*
			构造函数		析构函数
返回值				  void
函数名		类名			~类名
参数		可以有			无
重载		可以发生		不
调用方式	构造(销毁)自动调用，且只调用一次

*/
#include<iostream>
using namespace std;
class Person {
public:
	int m_age;
	Person() {		cout << "person无参构造" << endl;		}
	Person(int a) {
		m_age = a; cout << "person有参构造" << endl; 
	}
	Person(const Person& p) {
		m_age = p.m_age; cout << "person拷贝构造" << endl;
	}
	~Person(){
		cout << "person析构" << endl;
	}
};
void test001() {
	cout << "test001,用已经创建完毕的对象来初始化新对象" << endl;
	Person p1(21);
	Person p2(p1);
}
//_________________________
void work(Person p) {

}
void tess002() {
	cout << "test002值传递的方式给函数参数传值" << endl;
	Person pp1;
	work(pp1);
}
//___________________________
Person work2() {
	Person ppp1;  
	cout << (int*)&ppp1 << endl;   //先创造ppp1再拷贝到pp1，再析构ppp1
	return ppp1;//return的时候会调用拷贝构造函数
}
void tess003() {
	cout << "test003值的方式返回局部对象" << endl;
	Person pp1;
	work(pp1);
	cout << (int*)&pp1 << endl;
}
int main() {
	test001();
	tess002();
	tess003();
	return 0;
}
/*
			���캯��		��������
����ֵ				  void
������		����			~����
����		������			��
����		���Է���		��
���÷�ʽ	����(����)�Զ����ã���ֻ����һ��

*/
#include<iostream>
using namespace std;
class Person {
public:
	int m_age;
	Person() {		cout << "person�޲ι���" << endl;		}
	Person(int a) {
		m_age = a; cout << "person�вι���" << endl; 
	}
	Person(const Person& p) {
		m_age = p.m_age; cout << "person��������" << endl;
	}
	~Person(){
		cout << "person����" << endl;
	}
};
void test001() {
	cout << "test001,���Ѿ�������ϵĶ�������ʼ���¶���" << endl;
	Person p1(21);
	Person p2(p1);
}
//_________________________
void work(Person p) {

}
void tess002() {
	cout << "test002ֵ���ݵķ�ʽ������������ֵ" << endl;
	Person pp1;
	work(pp1);
}
//___________________________
Person work2() {
	Person ppp1;  
	cout << (int*)&ppp1 << endl;   //�ȴ���ppp1�ٿ�����pp1��������ppp1
	return ppp1;//return��ʱ�����ÿ������캯��
}
void tess003() {
	cout << "test003ֵ�ķ�ʽ���ؾֲ�����" << endl;
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
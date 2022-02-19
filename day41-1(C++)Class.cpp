/*
封装：将属性和行为作为一个整体，表现事物 属性行为权限
	  ；；；；；；加以权限控制，
				类内		类外
public			可以		不可
protected		可以		不
private			可以		不

1.Class和Struct区别：
	class默认权限为私有，struct默认权限为 共有

2.成员属性设为私有的好处
	权限是可以自己设置的
	对于写可以检测数据的有效性
*/

#include<iostream>
#include<string>
using namespace std;
const float PI = 3.1416;
class Circle			//class 代表设计一个类，类后面是类名称
{
public:					//访问权限，公共 
	//默认权限是private，不说就是private
//属性；成员变量
	float m_Radius;
	float m_posx;
	float m_posy;
	//行为：成员函数
	void setSize(float r) {
		m_Radius = r;
	}
	void setPos(float x, float y) {
		m_posx = x;
		m_posy = y;
	}
	float C_equal_PaiD() {
		return 2 * PI * m_Radius;
	}
	float S_equal_PaiRSquare() {
		return PI * m_Radius * m_Radius;
	}
	float position(int x, int y) {
		float dist = (x - m_posx) * (x - m_posx) + (y - m_posy) * (y - m_posy);
		return dist - m_Radius* m_Radius;
	}
};
class Person {
public:
	void setName(string name) {
		m_name = name;
	}
	string getName() {
		return m_name;
	}
	int getAge() {
		m_age = 114;
		return m_age;
	}
	void setLover(string name) {
		m_lover = name;
	}
private:
	string m_name;  //可读可写
	int m_age;		//只读
	string m_lover;	//只写
};
class Cube {
public:
	void setCube(int x,int y,int z) {
		m_a = x; m_b = y; m_c = z;
	}
	int getVolume() {
		return m_c * m_b * m_a;
	}
	int getSurface() {
		return (m_a * m_b + m_a * m_c + m_b * m_c) * 2;
	}
	bool judgeIfTwoCubeEqual(Cube& c2) {
		int a1 = m_c + m_b + m_a;
		int a2 = c2.m_c + c2.m_b + c2.m_a;
		int v1 = getVolume();
		int v2 = c2.getVolume();
		int s1 = getSurface();
		int s2 = c2.getSurface();
		if (a1 == a2 && v1 == v2 && s1 == s2)
			return true;
		return false;
	}
private:
	int m_a;
	int m_b;
	int m_c;
};
int main() {
	{Circle c1;
	c1.setSize(4);
	c1.setPos(4, 1);
	cout << "周长面积分别为" << c1.C_equal_PaiD() << " ," << c1.S_equal_PaiRSquare() << endl;
	int d = c1.position(0, 1);
	if (d > 0)
		cout << "outofcircle" << endl;
	else if (d < 0)
		cout << "inthecircle" << endl;
	else
		cout << "ontheedge" << endl;
	}
	{//只读只写，可读可写是可以自己设置的
		Person p1;
		p1.setName("roshine");
		p1.setLover("Raiden");
		cout << p1.getName() <<"今年" <<p1.getAge() <<"岁，情人无可奉告"<<endl;
	}
	{//判断立方体相等
		Cube C1; Cube C2; Cube C3;
		C1.setCube(3, 4, 5); C2.setCube(4, 1, 3); C3.setCube(4, 5, 3);
		if (C1.judgeIfTwoCubeEqual(C2))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
		if (C1.judgeIfTwoCubeEqual(C3))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	system("pause");
	return 0;
}
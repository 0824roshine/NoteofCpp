/*
��װ�������Ժ���Ϊ��Ϊһ�����壬�������� ������ΪȨ��
	  ����������������Ȩ�޿��ƣ�
				����		����
public			����		����
protected		����		��
private			����		��

1.Class��Struct����
	classĬ��Ȩ��Ϊ˽�У�structĬ��Ȩ��Ϊ ����

2.��Ա������Ϊ˽�еĺô�
	Ȩ���ǿ����Լ����õ�
	����д���Լ�����ݵ���Ч��
*/

#include<iostream>
#include<string>
using namespace std;
const float PI = 3.1416;
class Circle			//class �������һ���࣬�������������
{
public:					//����Ȩ�ޣ����� 
	//Ĭ��Ȩ����private����˵����private
//���ԣ���Ա����
	float m_Radius;
	float m_posx;
	float m_posy;
	//��Ϊ����Ա����
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
	string m_name;  //�ɶ���д
	int m_age;		//ֻ��
	string m_lover;	//ֻд
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
	cout << "�ܳ�����ֱ�Ϊ" << c1.C_equal_PaiD() << " ," << c1.S_equal_PaiRSquare() << endl;
	int d = c1.position(0, 1);
	if (d > 0)
		cout << "outofcircle" << endl;
	else if (d < 0)
		cout << "inthecircle" << endl;
	else
		cout << "ontheedge" << endl;
	}
	{//ֻ��ֻд���ɶ���д�ǿ����Լ����õ�
		Person p1;
		p1.setName("roshine");
		p1.setLover("Raiden");
		cout << p1.getName() <<"����" <<p1.getAge() <<"�꣬�����޿ɷ��"<<endl;
	}
	{//�ж����������
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
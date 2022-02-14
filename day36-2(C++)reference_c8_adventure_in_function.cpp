#include<iostream>
using namespace std;
int cube1(int a)
{
	a *= a * a;
	return a;
}
int cube2(int& ra)
{
	ra *= ra * ra;
	return ra;
}
int main()
{
	int x = 3;
	int y = 0;
	y = cube1(x);
	cout << x<<"^3 = " << y << endl;
	y = cube2(x);
	cout << x << "^3 = " << y << endl;
	return 0;
}
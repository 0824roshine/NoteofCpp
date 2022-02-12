#include<iostream>
using namespace std;
void how2use_new()
{
	int* p1 = new int(10);
	cout << *p1 << endl;
	delete p1;
	int* arr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i * i;
		cout << arr[i]<<" ";
	}
	cout << endl;
	delete arr;
}
int main()
{
	how2use_new();
	return 0;
}
#include <iostream>
using namespace std;

class parent
{
	public:
	parent()
	{
		cout << "Inside parent"<<endl;
	}
	parent(int x)
	{
		cout << "Param of parent"<<x<<endl;
	}
	static int price;
	static int getprice()
	{
		return price;
	}
};
int parent::price = 20;
class child:public parent
{
	public:
	child()
	{
		cout << "Inside child"<<endl;
	}
	child(int x)
	{
		cout << "Param of child"<<x<<endl;
	}
	child(int x, int y):parent(x)
	{
		cout << "Param2 of child"<<y<<endl;
	}
};
int main()
{
	child d(10,20);
	cout<< parent::getprice();
	parent p;
	cout<< p.getprice()<<endl;
	cout<<"static member printing.."<<endl;
	cout<< parent::price <<endl;
	return 0;
}
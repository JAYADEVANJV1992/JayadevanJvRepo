#include<iostream>
using namespace std;

class parent
{
	private:
		int a;
		int b;
	public:
		parent();
		~parent();
		parent(int x,int y)
		{
			set(x,y);
		}
		parent(parent &t)
		{
			a = t.a;
			b = t.b;
		}
		void set(int p, int q)
		{
			a = p;
			b = q;
		}
		int add()
		{
			return a+b;
		}
		int sub(int a, int b);
	
};
	parent::parent()
	{
		a = 1;
		b = 2;
	}
	parent::~parent()
	{
		cout << "Class destructed" << endl;
	}
	int parent::sub(int a, int b)
	{
		return a-b;
	}

int main()
{
	parent g;
	//g.set(4,5);
	parent go(5,7);
	parent si(go);
	parent v;
	cout << g.add() <<endl;
	cout << go.add() <<endl;
	cout << si.add() <<endl;
	cout << v.sub(9,1) <<endl;
	
	return 0;
}
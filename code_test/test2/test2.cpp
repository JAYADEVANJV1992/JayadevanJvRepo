#include<iostream>
#include<vector>
#include <limits> 
using namespace std;

class parent
{
	int a;
	public:
	  int addwithtwo(int a);
};

class child :private parent
{
	int c;
	public:
	
	int twotimes(int b)
	{
		return (addwithtwo(b) * 2);
	}
};
int parent :: addwithtwo (int a)
{
	return a+2;
}
int main()
{
#ifdef vec
	vector<int> v={2,5,2,6};
	v.push_back(45);
	v.push_back (78);	
	v.pop_back();
	for(int x:v)
	cout<<x<<endl;
vector<int> :: iterator itr;
for(itr=v.begin();itr!=v.end();itr++)
cout<<*itr<<endl;



parent m;
child n;
cout<< m.addwithtwo(5)<< endl;
cout<< n.twotimes(5)<< endl;
#endif

int size=0;
char str[30];
cout << "Enter the size = " << endl;
cin >> size;
cout << "Size = " << size << endl;
int *p = new int[size];
int *q= new int;
*q=size;
p[1] = 5;
cout << "p[1]=" << p[1] <<endl;
delete []p;
p=nullptr;
cout << "*q=" << *q <<endl;
delete q;
q=nullptr;
//cout << "*q=" << *q <<endl;
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "Enter the string"<< endl;
cin.get(str,30);
cout << str << endl;
}
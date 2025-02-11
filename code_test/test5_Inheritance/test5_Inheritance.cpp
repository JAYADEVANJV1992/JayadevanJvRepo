#include <iostream>
#include <memory>
#include <cstdarg>

#define msg(x) #x
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
int sum(int n,...)
{
	va_list list;
	va_start(list,n);
	int x;
	int s=0;
	for(int i=0;i<n;i++)
	{
		x=va_arg(list,int);
		s+=x;
	}
	va_end(list);
	return s;
}

template<class T, class R>
auto maximum(T a, R b)
{
	// if( a>b)
		// cout << "Maximunm ="<<a<<endl;
	// else
	// cout << "Maximunm ="<<b<<endl;
   return ((a > b) ? a : b); 
}
template <typename T>
void fun(T p) 
{
	p();
}
int main()
{
	int a,b,c,n,m;
	cout<<sum(3,2,3,4)<<endl;
	
	cout<< msg(jayadevan)<<endl;
	[](){cout<<"hello"<<endl;}();
	[](int x,int y){cout<<"sum="<<x+y<<endl;}(10,30);
	cout<<([](int x,int y){return x+y;}(10,30))<<endl;	
	int t = [](int x,int y){return x+y;}(10,50);
	cout << t<<endl;
    int k = [](int x,int y)->int{return x+y;}(10,50);
    cout << k<<endl;	
	int l=10;
	[l](){cout << l<< endl;}();
	auto f = [&l](){cout << l++<< endl;};
	f();
	l++;
	f();
	fun(f);
	unique_ptr<parent> ptr(new parent(5));	
	unique_ptr<parent> ptr2;
	ptr2=move(ptr);
	cout << ptr2->getprice()<<endl;
	cout << ptr->getprice()<<endl;
	
	shared_ptr<parent> ptr3(new parent(5));	
	cout << ptr3->getprice()<<endl;
	shared_ptr<parent> ptr4;
	ptr4=ptr3;
	cout << ptr4->getprice()<<endl;
	cout << ptr3.use_count()<<endl;
	
	
	
	
	#ifdef jay
	child d(10,20);
	cout<< parent::getprice();
	parent p;
	cout<< p.getprice()<<endl;
	cout<<"static member printing.."<<endl;
	cout<< parent::price <<endl;
	cout << "Enter values of a and b" << endl;
	cin >>a;
	cin >> b;
	cout << "Enter the numbers for finding the maximum"<<endl;
	cin >> n;
	cin >> m;
	//maximum(n,m);
	cout << maximum(n,m)<<endl;
	
	try
	{
		if(a==0 || b==0)
			throw 1;
			c=a/b;
			cout << "C= "<< c<< endl;
	}

	
	catch(int e)
	{
		cout << "Entered value contains 0"<< endl;

	}
	#endif

	return 0;
}
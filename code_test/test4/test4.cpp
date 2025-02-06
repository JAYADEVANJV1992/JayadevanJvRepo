#include<iostream>
#include<string>
using namespace std;

class student
{
	private:
		int rollNo;
		string Name;
		int marks[2];
	public:
		void EnterrollNo(int val);
		void EnterName(string val);
		void EnterMarks(int sub,int val);
		int getrollNo();
		string getName();
		int* getMarks();
		int total();
		char grade();
		
};
void student::EnterrollNo(int val)
{
	rollNo = val;
}	
void student::EnterName(string val)
{
	Name = val;
}	
void student::EnterMarks(int sub,int val)
{
	marks[sub] = val;
}	
int student::getrollNo()
{
	return rollNo;
}
string student::getName()
{
	return Name;
}
int* student::getMarks()
{
	return marks;
}
int student::total()
{
	return (marks[0]+marks[1]);
}
char student::grade()
{
	float perc = 0;
	char ret;
	perc = ((static_cast<float>(total())/200)*100);
	cout << total() <<endl;
	cout << perc <<endl;
	if(perc <40)
		ret = 'C';
	else if(perc >= 40 && perc <60)
		ret = 'B';
	else if(perc >=60)
		ret = 'A';
		
	return ret;
	#ifdef gr
	float perc = 0;
    char ret;
    perc = (static_cast<float>(total()) / 200) * 100;  // Cast total() to float for correct percentage
    cout << "Total Marks: " << total() << endl;
    cout << "Percentage: " << perc << "%" << endl;
    
    if (perc < 40)
        ret = 'C';
    else if (perc >= 40 && perc < 60)
        ret = 'B';
    else if (perc >= 60)
        ret = 'A';
        
    return ret;
	#endif
}
int main()
{
	int num = 0;
	int data=0;
	int check;
	int checkBranch;
	char v;
	char v2;
	string str;
	cout << "Enter the number of students" << endl;
	cin >> num;
	student stds[num];
	// cout << "Enter the details of the student " << num-(num-1) << endl;
	// cin >> data;
	// stds[num-num].EnterrollNo(data);
	// cin.ignore();
	// getline(cin,str);
	// stds[num-num].EnterName(str);
	// cin >> data;
	// stds[num-num].EnterMarks(num-num, data);
	// cout << stds[num-num].getrollNo() << endl;
	// cout << stds[num-num].getName() << endl;
	// int* marks = stds[num-num].getMarks();
	// cout << marks[0] << endl;
	for(int i=0;i<num;i++)
	{
		cout << "Enter the details of the student " << i+1 << endl;
		cin >> data;
		stds[i].EnterrollNo(data);
		cin.ignore();
		getline(cin,str);
		stds[i].EnterName(str);
		cin >> data;
		stds[i].EnterMarks(0, data);
		cin >> data;
		stds[i].EnterMarks(1, data);
	}
	for(int i=0;i<num;i++)
	{
		cout << "Entered details of the student " << i+1 << endl;
		cout << stds[i].getrollNo() << endl;
		cout << stds[i].getName() << endl;
		int* marks = stds[i].getMarks();
		cout << marks[0] << endl;
		cout << marks[1] << endl;
	}
	for(int j=1;j<=num;j++)
	{
		cout << "Grade of Student " << j << endl;
		cout << stds[j-1].grade() << endl;
		
    }
	return 0;
}
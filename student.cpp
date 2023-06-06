#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Student
{
	int rollNumber;
	string name;
	string division;
	string address;
};

void addstudent()
{
	ofstream file("info.txt",ios::app);
	
	Student student;
	
	cout<<"enter roll number :";
	cin>>student.rollNumber;
	cout<<"enter name :";
	cin.ignore();
	getline(cin,student.name);
	cout<<"enter division :";
	getline(cin,student.division);
	cout<<"enter address :";
	getline(cin,student.address);
	
	file<<student.rollNumber<<" "<<student.name<<" "<<student.division<<" "<<student.address<<endl;
	file.close();
	
	cout<<"information added successfully"<<endl;
}

void deletestudent()
{
	
	ifstream inputfile("info.txt");
	ofstream tempfile("temp.txt");
	
	int rollNumber;
	cout<<"enter roll number";
	cin>>rollNumber;
	
	bool found=false;
	Student student;
	
	while(inputfile>>student.rollNumber>>student.name>>student.division>>student.address)
	{
		if(student.rollNumber!=rollNumber)
		{
			tempfile<<student.rollNumber<<" "<<student.name<<" "<<student.division<<" "<<student.address<<endl;
		}
		else
		{
			found=true;
		}
	}
	inputfile.close();
	tempfile.close();
	
	if(found)
	{
		remove("info.txt");
		rename("temp.txt","info.txt");
		cout<<"information deleted successfully";
	}
	else
	{
		remove("temp.txt");
		cout<<"information not found";
	}
}

void displaystudent()
{
	ifstream file("info.txt");
	
	int rollNumber;
	cout<<"enter roll number of student to display";
	cin>>rollNumber;
	
	bool found=false;
	Student student;
	
	while(file>>student.rollNumber>>student.name>>student.division>>student.address)
	{
		if(student.rollNumber==rollNumber)
		{
			found=true;
			cout<<"rollnumber :"<<student.rollNumber<<endl;
			cout<<"name :"<<student.name<<endl;
			cout<<"division :"<<student.division<<endl;
			cout<<"address :"<<student.address<<endl;
			break;
		}
	}
	file.close();
	
	if(!found)
	{
		cout<<"information not found"<<endl;
	}
}

int main()
{
	int choice;
	while(true)
	{
		cout<<"-------------------student information menu-----------------------"<<endl;
		cout<<"1.add student "<<endl;	
		cout<<"2.delete student"<<endl;
		cout<<"3.display student "<<endl;
		cout<<"4.exit"<<endl;
		cout<<"enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				addstudent();
				break;
			case 2:
				deletestudent();
				break;
			case 3:
				displaystudent();
				break;
			case 4:
				cout<<"end";
				break;
			default:
				cout<<"entered wrong choice";
				break;
		}
		cout<<endl;
	}
	return 0;
}	
	

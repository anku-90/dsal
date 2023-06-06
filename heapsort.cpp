#include<iostream>
using namespace std;
class heap1
{
	public:
	void max_heapify(int a[],int i,int n)
	{
		int l,r,largest,loc;
		l=2*i+1;
		r=2*i+2;
		largest=i;
		if((l<n)&&a[l]>a[largest])
			largest=l;
		if((r<n)&&a[r]>a[largest])
			largest=r;
			
		if(largest!=i)
		{
			loc=a[i];
			a[i]=a[largest];
			a[largest]=loc;
			max_heapify(a,largest,n);
		}
	}
	void built_heap_sort(int a[],int n)
	{
		for(int k=n/2-1;k>=0;k--)
		{
			max_heapify(a,k,n);
		}
	}
	void heapsort(int a[],int n)
	{
		built_heap_sort(a,n);
		int i,temp;
		for(int i=n-1;i>=0;i--)
		{
			temp=a[i];
			a[i]=a[0];
			a[0]=temp;
			max_heapify(a,0,i);
		}
	}
	void accept()
	{
		int n;
		cout<<"enter the number of student"<<endl;
		cin>>n;
		int a[n];
		cout<<"enter the marks of students"<<endl;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		heapsort(a,n);
		display(a,n);
	}
	void display(int a[],int n)
	{
		cout<<"::::::::::::SORTED MARKS::::::::::::::"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<endl;
		}
	cout<<"\nminimum marks obtained\n"<<a[0];
	cout<<"\nmaximum marks obtained\n"<<a[n-1];
	}
};

int main()
{
	heap1 h;
	h.accept();
	return 0;
}	

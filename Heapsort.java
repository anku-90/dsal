public class Heapsort<T extends Comparable<T>>
{
	private T data[];
	private int length;

	Heapsort(T data[])
	{
		this.data=data;
		this.length=this.data.length;
	}
	
	public T[] buildmaxheap(T[] tempdata)
	{
		for(int i=(int)Math.floor(length/2);i>-0;i--)
		{
			tempdata=heapify(tempdata,i);
		}
		return tempdata;
	}
	
	public T[] heapify(T[] tempdata,int node)
	{
		int leftnode=node*2+1;
		int rightnode=node*2+2;
		
		int maxnode=node;
	
		if(leftnode<length)
		{
			if(tempdata[leftnode].compareTo(tempdata[maxnode])>0)
			{
				maxnode=leftnode;
			}
		}
		
		if(rightnode<length)
		{
			if(tempdata[rightnode].compareTo(tempdata[maxnode])>0)
			{
				maxnode=rightnode;
			}
		}
		
		if(maxnode!=node)
		{
			T temp=tempdata[node];
			tempdata[node]=tempdata[maxnode];
			tempdata[maxnode]=temp;
			tempdata=heapify(tempdata,maxnode);
		}
		return tempdata;
	}
	
	public void sort()
	{
		this.data=buildmaxheap(this.data);
		while(length>0)
		{
			length--;
			
			T temp=this.data[0];
			this.data[0]=this.data[length];
			this.data[length]=temp;
			this.data=heapify(this.data,0);
		}
	}
	
	public void printdata()
	{
		for(T i:this.data)
		{
			System.out.print(i + " ");
		}
		System.out.println();
	}
	
	public static void main(String[] args)
	{
		//sorting integer data using heap sort
		//integer[] datatobesorted={2,4,3,1,6};
		//Heapsort heapsort=new Heapsort<integer>(datatobesorted);
		
		//sorting double data using heap sort
		//double[] datatobesorted={2.1,4.2,6.1,3.4};
		//Heapsort heapsort=new Heapsort<double>(datatobesorted);
		
		//sorting character data using heap sort
		//character[] datatobesorted={'a','h','m','b'};
		//Heapsort heapsort=new Heapsort<character>(datatobesorted);
		
		//sorting string data using heap sort;
		String[] datatobesorted={"ankita","divya","maya","radha","dad"};
		Heapsort heapsort=new Heapsort<String>(datatobesorted);
		
		
		System.out.println("given data -");
		heapsort.printdata();
		
		heapsort.sort();
		
		System.out.println("Sorted data-");
		heapsort.printdata();
	}
}

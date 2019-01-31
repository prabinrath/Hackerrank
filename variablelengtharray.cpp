#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector< vector< int > > arr;
 	int n,q;
	cin>>n>>q;
	
	for(int i=0;i<n;i++)
	{
		vector< int > temp;
		int len;
		cin>>len;
		for(int j=0;j<len;j++)
		{
			int data;
			cin>>data;
			temp.push_back(data);
		}
		arr.push_back(temp);
	}
	
	for(int i=0;i<q;i++)
	{
		int index,pos;
		cin>>index>>pos;
		cout<<arr[index][pos]<<endl;
	}
}

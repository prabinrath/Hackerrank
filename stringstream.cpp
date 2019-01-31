#include<iostream>
#include<sstream>
#include<string>
using namespace std;
//string stream class is usually used for argument parsing
int main()
{
	stringstream ss("23,4,56");
	string temp;
	for(int i=0;i<3;i++)
	{
		getline(ss,temp,','); //extract characters word by word separeted by a delimater
		int data;
		stringstream(temp)>>data; //convert the type of the extracted data to integer
		cout<<data<<endl;
	}
}

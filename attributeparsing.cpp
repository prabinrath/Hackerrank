#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

struct attribute
{
	string name,val;
};

class hrml
{
	private:
		vector< attribute > attr;
	public:
		bool hasparent;
		string tag;
		vector< int > siblingindex;
		string getAttribute(string);
		void setAttribute(attribute);
};

void hrml::setAttribute(attribute temp)
{
	attr.push_back(temp);
}
string hrml::getAttribute(string name)
{
	string value="";
	for(int i=0;i<attr.size();i++)
	{
		if(attr[i].name==name)
			value=attr[i].val;
	}
	return value;
}

vector< int > parentindex;
vector< hrml > pgm;

hrml setAttributes(string temp)
{
	hrml nw;
	if(parentindex.size()!=0){nw.hasparent=true;}else{nw.hasparent=false;}
	temp.pop_back();
	stringstream ss; ss<<temp;
	string token="",tp;
	
	getline(ss,token,' ');
	//if(token==""){token=temp;}
	tp="";
	for(int i=1;i<token.size();i++)
		{tp.push_back(token[i]);}
	nw.tag=tp;
	
	attribute at;
	while(getline(ss,token,' '))
	{
		if(token!="=")
		{
			if(token[0]!='"')
				{at.name=token;}
			else
			{
				tp="";
				for(int i=1;i<token.size()-1;i++)
					{tp.push_back(token[i]);}
				at.val=tp;
				nw.setAttribute(at);
			}
		}
	}
	return nw;
}

int main()
{
	int lne,qry;
	cin>>lne>>qry;
	//cout<<"program\n";
	cin.ignore();
	while(lne>0)
	{
		string temp;
		getline(cin,temp);
		if(temp[1]!='/')
		{
			pgm.push_back(setAttributes(temp));
			if(parentindex.size()>0)
				{pgm[parentindex.back()].siblingindex.push_back(pgm.size()-1);}
			parentindex.push_back(pgm.size()-1);
		}
		else
		{parentindex.pop_back();}
		lne--;
	}

	//cout<<"query\n";
	while(qry>0)
	{
		string temp,child;
		getline(cin,temp);
		stringstream ln,cls; ln<<temp;
		getline(ln,temp,'~');
		cls<<temp;
		
		bool relation=true;
		getline(cls,temp,'.');
		for(int i=0;i<pgm.size();i++)
		{
			if(pgm[i].tag==temp)
				{
					if(pgm[i].hasparent==true) relation=false;
				}
		}
			while(getline(cls,child,'.') && relation==true)
			{
				relation=false;
				for(int i=0;i<pgm.size();i++)
				{
					if(pgm[i].tag==temp)
					{
						for(int j=0;j<pgm[i].siblingindex.size();j++)
						{
							if(pgm[pgm[i].siblingindex[j]].tag==child)
								{relation=true;}
						}
					
					}
				}
				temp=child;
			}
		
		if(relation==false){cout<<"Not Found!\n";}
		else
		{
			relation=false;
			for(int i=0;i<pgm.size();i++)
			{
				if(pgm[i].tag==temp)
				{
					getline(ln,temp,'~');
					temp=pgm[i].getAttribute(temp);
					if(temp==""){cout<<"Not Found!\n";}
					else
					cout<<temp<<endl;
					relation=true;
					break;
				}
			}
			if(relation==false){cout<<"Not Found!\n";}
		}
		qry--;
	}
	return 0;
}

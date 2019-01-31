#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map< string, int > stu;
    int qry;
    cin>>qry;
    while(qry>0)
    {
        int typ;
        string name;
        cin>>typ;
        if(typ==1)
        {
            int mrk;
            cin>>name>>mrk;
            if(stu.find(name)!=stu.end())
            {
                mrk+=stu.find(name)->second;
                stu.erase(name);
            }
            stu.insert(pair< string, int > (name,mrk));
        }
        else if(typ==2)
        {
            cin>>name;
            stu.erase(name);
        }
        else if(typ==3)
        {
        	cin>>name;
            if(stu.find(name)==stu.end())
            {
                cout<<0<<endl;
            }
            else
            {
                cout<<stu.find(name)->second<<endl;
            }
        }
        qry--;
    }
    return 0;
}

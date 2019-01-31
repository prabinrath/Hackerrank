#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() 
{
    int data;
    
    int t,n,k;
    cin>>t;
    while(t--)
    {
        map<int,int> num;
        cin>>n>>k;
        while(n--)
        {
            cin>>data;
            if(num.find(data)!=num.end())
            {
                num[data]+=1;
            }
            else
            {
                num[data]=1;
            }
            
            vector<vector<int>> prt(101);
            for(map<int,int>::iterator it=num.begin();it!=num.end();it++)
            {
                prt[it->second].push_back(it->first);
            }
            int count=0;
            for(int i=100;i>0;i--)
            {
                if(count==k)
                    break;
                if(!prt[i].empty())
                {
                    for(vector<int>::iterator it=prt[i].begin();it!=prt[i].end();it++)
                    {
                        if(count==k)
                            break;
                        cout<<*it<<" ";count++;
                    }
                }
            }
        }
        cout<<endl;
    }
	return 0;
}

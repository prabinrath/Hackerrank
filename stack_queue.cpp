#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<stack>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ll test_cases,val;
    scanf("%lli",&test_cases);
    int type;
    stack<ll> s1,s2;
    
    while(test_cases--)
    {
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%lli",&val);
        }
        
        if(type==1)
        {
            s1.push(val);
        }
        else if(type==2 || type==3)
        {
            ll sz=s1.size()-1;
            for(ll i=0;i<sz;i++)
            {
                s2.push(s1.top());
                s1.pop();
            }
            
            if(type==2)
            {
                s1.pop();
            }
            else
            {
                printf("%lli\n",s1.top());
            }
            
            for(ll i=0;i<sz;i++)
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    return 0;
}

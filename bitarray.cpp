#include <cmath>
#include <cstdio>
#include <unordered_set>
#include<cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

ll rusPsnt(ll a,ll b)
{
    ll res=0,ina=abs(a),inb=abs(b);
    while(inb>0)
    {
        if(inb&1)
        {
            res+=ina;
        }
        ina=ina<<1;
        inb=inb>>1;
    }
    if((a<0 && b>0) || (a>0 && b<0))
        return (-1)*res;
    else
        return res;
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ll cst=1;
    for(int i=0;i<31;i++)
    {
        cst*=2;
    }
    unordered_set<ll> ans;
    ll N,S,P,Q,prev,curr;
    cin>>N>>S>>P>>Q;
    prev=S%cst;
    ans.insert(prev);
    for(int i=1;i<N;i++)
    {
        curr=rusPsnt(prev,P)+Q%cst;
        prev=curr;
        ans.insert(curr);
    }
    cout<<ans.size();
    return 0;
}

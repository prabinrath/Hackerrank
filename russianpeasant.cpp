#include <bits/stdc++.h>
#include <cstdlib>
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

// Complete the solve function below.
vector<ll> solve(int a, int b, long k, int m) 
{
    ll rel=1,img=1,tempa=a,tempb=b,handle;
    bool flag=true;
    
    while(k>0)
    {
        if(k&1)
        {
            if(flag==true)
            {
                rel=tempa;img=tempb;flag=false;
            }
            else
            {
                handle=rel;
                rel=( rusPsnt(rel,tempa)%m - rusPsnt(img,tempb)%m + m ) % m;
                img=( rusPsnt(handle,tempb)%m + rusPsnt(img,tempa)%m + m ) % m;
            }
        }
        handle=tempa;
        tempa=( rusPsnt(tempa,tempa)%m - rusPsnt(tempb,tempb)%m + m ) % m;
        tempb=( rusPsnt(handle,tempb)%m + rusPsnt(handle,tempb)%m + m ) % m;
        k >>= 1;
    }
    vector<ll> ans;
    ans. push_back(rel);
    ans. push_back(img);
    return ans;
}

int main()
{
    ll t;
    cin>>t;
	ll a,b,k,m;
	
	while(t--)
	{
        vector<ll> vec;
		cin>>a>>b>>k>>m;
        vec = solve(a,b,k,m);
        cout<<vec[0]<<" "<<vec[1]<<endl;
    }

    return 0;
}

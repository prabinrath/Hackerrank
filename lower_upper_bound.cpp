#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int size,data;
    vector< int > vec;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>data;
        vec.push_back(data);
    }
    cin>>size;
    while(size>0)
    {
        cin>>data;
        vector< int >::iterator lb,ub;
        lb=lower_bound(vec.begin(),vec.end(),data);
        if(lb==vec.end() || *lb!=data)
        {
        	cout<<"No "<<(lb-vec.begin()+1)<<endl;
        }
        else
        {
        	cout<<"Yes "<<(lb-vec.begin()+1)<<endl;
        }
        size--;
    }
    return 0;
}

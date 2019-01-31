#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

class Node
{
    public:
    vector<long> rnga,rngb;
    pair<long,long> min_pair;
    long min_val;
    
    Node(long a,long b,long c,long d)
    {
        for(int i=a;i<=b;i++)
        {
            rnga.push_back(i);
        }
        for(int i=c;i<=d;i++)
        {
            rngb.push_back(i);
        }
        min_pair=getMinPair();
    }
    
    pair<long,long> getMinPair()
    {
        long posa=0,posb=0;
        min_val=LONG_MAX;
        for(long i=0;i<rnga.size();i++)
        {
            for(long j=0;j<rngb.size();j++)
            {
                long temp=abs(rnga[i]-rngb[j]);
                if(temp<min_val)
                {
                    min_val=temp;
                    posa=i;posb=j;
                }
            }
        }
        return pair<long,long> (posa,posb);
    }
    
    long getMinValue(long targ,bool select)
    {
        long min=LONG_MAX;
        if(select==false)
        {
            for(int i=0;i<rnga.size();i++)
            {
                long temp=abs(targ-rnga[i]);
                if(temp<min)
                {
                    min=temp;
                }
            }
        }
        return min;
    }
};

// Complete the minimumSum function below.
long minimumSum(vector<int> l, vector<int> r)
{
    // Return the minimum sum among all arrays that satisfy the condition.
    vector<Node> arr;
    vector<long> min_values;
    for(int i=1;i<l.size();i++)
    {
        Node temp(l[i-1],r[i-1],l[i],r[i]);
        arr.push_back(temp);
    }
    
    for(int i=0;i<arr.size();i++)
    {
        long min_sum=0;
        min_sum+=arr[i].min_val;
        for(int j=i-1;j>=0;j--)
        {
            min_sum+=arr[j].
        }
    }
    
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string l_temp_temp;
    getline(cin, l_temp_temp);

    vector<string> l_temp = split_string(l_temp_temp);

    vector<int> l(n);

    for (int i = 0; i < n; i++) {
        int l_item = stoi(l_temp[i]);

        l[i] = l_item;
    }

    string r_temp_temp;
    getline(cin, r_temp_temp);

    vector<string> r_temp = split_string(r_temp_temp);

    vector<int> r(n);

    for (int i = 0; i < n; i++) {
        int r_item = stoi(r_temp[i]);

        r[i] = r_item;
    }

    long result = minimumSum(l, r);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}


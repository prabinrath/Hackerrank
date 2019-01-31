#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) 
{
    stack<char> arr;
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        if(arr.empty()  && (ch=='}' || ch==')' || ch==']'))
            {cout<<'1'<<endl;return "NO";}
        if(ch=='{' || ch=='(' || ch=='[')
            arr.push(ch);
        else
        {
            if(arr.top()=='{')
            {
                if(ch!='}')
                    {cout<<'2'<<endl;return "NO";}
                else
            	{
                	arr.pop();
            	}
            }
            else if(arr.top()=='(')
            {
                if(ch!=')')
                    {cout<<'3'<<endl;return "NO";}
                else
            	{
                	arr.pop();
            	}
            }
            else if(arr.top()=='[')
            {
                if(ch!=']')
                    {cout<<'4'<<endl;return "NO";}
                else
            	{
                	arr.pop();
            	}
            }
        }
    }
    if(arr.empty())
        return "YES";
    else
        {cout<<'5'<<endl;return "NO";}
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        cout << result << "\n";
    }

    return 0;
}

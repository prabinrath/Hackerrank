#include <bits/stdc++.h>

using namespace std;

class Matrix
{
    vector<vector<vector<int>>> mast;
    public:
    Matrix()
    {
        vector<vector<int>> temp;
        temp = {{8,3,4},{1,5,9},{6,7,2}};
        mast.push_back(temp);
        temp.clear();
        temp = {{8,1,6},{3,5,7},{4,9,2}};
        mast.push_back(temp);
        temp.clear();
        temp = {{4,3,8},{9,5,1},{2,7,6}};
        mast.push_back(temp);
        temp.clear();
        temp = {{4,9,2},{3,5,7},{8,1,6}};
        mast.push_back(temp);
        temp.clear();
        temp = {{2,7,6},{9,5,1},{4,3,8}};
        mast.push_back(temp);
        temp.clear();
        temp = {{2,9,4},{7,5,3},{6,1,8}};
        mast.push_back(temp);
        temp.clear();
        temp = {{6,7,2},{1,5,9},{8,3,4}};
        mast.push_back(temp);
        temp.clear();
        temp = {{6,1,8},{7,5,3},{2,9,4}};
        mast.push_back(temp);
    }
    
    int sub(vector<vector<int>> a,vector<vector<int>> b)
    {
        int sum = 0;
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a[i].size();j++)
            {
                sum += abs(b[i][j]-a[i][j]);
            }
        }
        return sum;
    }
    
    int min_diff(vector<vector<int>> s)
    {
        vector<int> sol;
        for(int i=0;i<mast.size();i++)
        {
            sol.push_back(sub(s,mast[i]));
        }
        return *min_element(sol.begin(),sol.end());
    }
};

Matrix m;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s)
{
    return m.min_diff(s);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}


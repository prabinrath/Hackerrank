#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    list<int> lst;
    Node(int a,int b)
    {
        lst.push_back(a);lst.push_back(b);
    }
    
    bool operator==(Node ptr)
    {
        return lst==ptr.lst;
    }
};

list<Node> trk;

list<Node>::iterator search_list(int val)
{
    for(list<Node>::iterator it=trk.begin(); it!=trk.end(); it++)
        if(find(it->lst.begin(),it->lst.end(),val)!=it->lst.end())
               return it;
    return trk.end();
}
           
void modifyTrack(int a,int b)
{
    list<Node>::iterator p1,p2;
        p1 = search_list(a);
        p2 = search_list(b);
        if(p1==trk.end() && p2==trk.end())
        {
            Node temp(a,b);
            trk.push_back(temp);
        }
        else if(p1!=trk.end() && p2==trk.end())
        {
            p1->lst.push_back(b);
        }
        else if(p1==trk.end() && p2!=trk.end())
        {
            p2->lst.push_back(a);
        }
        else if(p1!=trk.end() && p2!=trk.end())
        {
            if(p1!=p2)
            {
                if(p1->lst.size()>p2->lst.size())
                {
                    p1->lst.merge(p2->lst);
                    trk.erase(p2);
                }
                else
                {
                    p2->lst.merge(p1->lst);
                    trk.erase(p1);
                }
            }
        }
}

vector<int> componentsInGraph(vector<vector<int>> gb) 
{
    for(int i=0;i<gb.size();i++)
    {
        modifyTrack(gb[i][0],gb[i][1]);
    }
    vector<int> ans;
    int min=INT_MAX,max=0;
    for(list<Node>::iterator it=trk.begin(); it!=trk.end(); it++)
    {
        
        if(it->lst.size()<min)
            min=it->lst.size();
        if(it->lst.size()>max)
            max=it->lst.size();
    }
    ans.push_back(min);ans.push_back(max);
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> gb(n);
    for (int gb_row_itr = 0; gb_row_itr < n; gb_row_itr++) {
        gb[gb_row_itr].resize(2);

        for (int gb_column_itr = 0; gb_column_itr < 2; gb_column_itr++) {
            cin >> gb[gb_row_itr][gb_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> SPACE = componentsInGraph(gb);

    for (int SPACE_itr = 0; SPACE_itr < SPACE.size(); SPACE_itr++) {
        cout << SPACE[SPACE_itr];

        if (SPACE_itr != SPACE.size() - 1) {
            cout << " ";
        }
    }

    cout << "\n";

    return 0;
}
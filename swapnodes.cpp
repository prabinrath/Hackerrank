struct Node
{
    int data;
    Node *left,*right;
    Node(int val):data(val){left=NULL;right=NULL;}
};

class BinTree
{
    public:
    Node *root;
    vector<vector<int>> vec;
    vector<int> out;
    int ind;
    
    BinTree(vector<vector<int>> data)
    {
        root = new Node(1);
        vec=data;
        ind=0;
        int target_depth=0;
        while(ind<vec.size())
        {
            buildBinTree(root,target_depth,0);
            target_depth++;
        }
        //inOrder(root);
    }
    
    void inOrder(Node *rt)
    {
        if(rt->left!=NULL)
            inOrder(rt->left);
        out.push_back(rt->data);
        //cout<<rt->data;
        if(rt->right!=NULL)
            inOrder(rt->right);
    }
    
    void buildBinTree(Node *rt,int targd,int currd)
    {
        if(ind<vec.size() && currd==targd)
        {
            Node *ptr;
            if(vec[ind][0]!=-1)
            {
                ptr=new Node(vec[ind][0]);
                rt->left=ptr;
            }
            
            if(vec[ind][1]!=-1)
            {
                ptr=new Node(vec[ind][1]);
                rt->right=ptr;
            }
            ind++;
        }
        
        if(rt->left!=NULL)
            buildBinTree(rt->left,targd,currd+1);
        if(rt->right!=NULL)
            buildBinTree(rt->right,targd,currd+1);
    }
    
    void modifyTree(Node *rt,int k,int depth)
    {
        if((depth+1)%k==0)
        {
            Node *ptr=rt->left;
            rt->left=rt->right;
            rt->right=ptr;
        }
        if(rt->left!=NULL)
            modifyTree(rt->left,k,depth+1);
        if(rt->right!=NULL)
            modifyTree(rt->right,k,depth+1);
    }
};

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) 
{
    vector<vector<int>> ans;
    BinTree *obj = new BinTree(indexes);
    for(int i=0;i<queries.size();i++)
    {
        obj->out.erase(obj->out.begin(),obj->out.end());
        obj->modifyTree(obj->root,queries[i],0);
        obj->inOrder(obj->root);
        ans.push_back(obj->out);
    }
    return ans;
}

map< int, vector<pair<int,int> > > mp;
    void genMap(Node *r,int key,int depth)
    {
        if(r->left!=NULL)
        {
            genMap(r->left,key-1,depth+1);
        }
        if(mp.find(key)==mp.end())
        {
            vector< pair<int,int> > temp;
            temp.push_back(pair<int,int> (r->data,depth));
            mp.insert( pair< int, vector< pair<int,int> > > (key,temp) );
        }
        else
        {
            (mp.find(key)->second).push_back(pair<int,int> (r->data,depth));
        }
        if(r->right!=NULL)
        {
            genMap(r->right,key+1,depth+1);
        }
    }

    void topView(Node * root) 
    {
        genMap(root,0,0);    
        vector<int> ans;

        for(map<int,vector<pair<int,int>>>::iterator it=mp.begin();it!=mp.end();it++)
        {
            int top=INT_MAX,val;
            for(int i=0;i<(it->second).size();i++)
            {
                if((it->second)[i].second<top)
                {
                    top=(it->second)[i].second;
                    val=(it->second)[i].first;
                }
            }
            ans.push_back(val);
        }
        
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

//AVL Tree with depth
#include<iostream>
using namespace std;

typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node;

long ht=0;
void setNodeHeight(node *rt,int depth)
{
    if(depth>ht)
        ht=depth;
    if(rt->left!=NULL)
        setNodeHeight(rt->left,depth+1);
    if(rt->right!=NULL)
        setNodeHeight(rt->right,depth+1);
}
int height(node* root)
{
    ht=0;
    setNodeHeight(root,0);
    return ht;
}
void setMaxHeight(node *rt)
{
    rt->ht=height(rt);
    if(rt->left!=NULL)
        setMaxHeight(rt->left);
    if(rt->right!=NULL)
        setMaxHeight(rt->right);
}

node* LL(node *b1,node *b2,node *b3)
{
    b3->left=b1->right;
    b1->right=b3;
    return b1;
}

node* RR(node *b1,node *b2,node *b3)
{
    b3->right=b1->left;
    b1->left=b3;
    return b1;
}

node* LR(node *b1,node *b2,node *b3)
{
    b1->right=b2->left;
    b2->left=b1;
    b3->left=b2;
    return LL(b2,b1,b3);
}

node* RL(node *b1,node *b2,node *b3)
{
    b1->left=b2->right;
    b2->right=b1;
    b3->right=b2;
    return RR(b2,b1,b3);
}

node * insert(node * root,int dat)
{
    if(root==NULL)
    {
        root=new node();
        root->val=dat;
        root->ht=0;
        root->left=NULL;
        root->right=NULL;
        setMaxHeight(root);
        return root;
    }
    
    node *tmp=root,*b0=NULL,*b1=NULL,*b2=NULL,*ptr=NULL,*kjl=NULL;
    while(true)
    {
        if(dat>tmp->val && tmp->right!=NULL)
        {
            b0=b1;
            b1=b2;
            b2=tmp;
            tmp=tmp->right;
        }
        else if(dat<tmp->val && tmp->left!=NULL)
        {
            b0=b1;
            b1=b2;
            b2=tmp;
            tmp=tmp->left;
        }
        else
        {
            ptr=new node();
            ptr->val=dat;
            ptr->left=NULL;
            ptr->right=NULL;
            ptr->ht=0;
            if(dat>tmp->val)
                tmp->right=ptr;
            else
                tmp->left=ptr;
            break;
        }
    }
    
        if(b2==NULL)
        {
            setMaxHeight(tmp);
            return tmp;
        }

        if(b2->left==NULL && tmp->left==NULL)
        {
            kjl = RR(tmp,ptr,b2);
        }
        else if(b2->left==NULL && tmp->right==NULL)
        {
            kjl = RL(tmp,ptr,b2);
        }
        else if(b2->right==NULL && tmp->left==NULL)
        {
            kjl = LR(tmp,ptr,b2);
        }
        else if(b2->right==NULL && tmp->right==NULL)
        {
            kjl = LL(tmp,ptr,b2);
        }

    if(kjl!=NULL)
        if(b1==NULL)
        {
            setMaxHeight(kjl);
            return kjl;
        }
        else
        {
            if(b1->right==b2)
                b1->right=kjl;
            else
                b1->left=kjl;
        }
        
    if(b1!=NULL && kjl==NULL)
    {   
        if(b1->left==b2 && b2->right==tmp && b1->right->left==NULL && b1->right->right==NULL) //LR
        {
            kjl = LR(b2,tmp,b1);
        }
        else if(b1->right==b2 && b2->left==tmp && b1->left->right==NULL && b1->left->left==NULL) //RL
        {
            kjl = RL(b2,tmp,b1);
        }
        else if(b1->left==b2 && b2->left==tmp && b1->right->left==NULL && b1->right->right==NULL) //LL
        {
            kjl = LL(b2,tmp,b1);
        }
        else if(b1->right==b2 && b2->right==tmp && b1->left->right==NULL && b1->left->left==NULL) //RR
        {
            kjl = RR(b2,tmp,b1);
        }

        if(kjl!=NULL)
            if(b0==NULL)
            {
                setMaxHeight(kjl);
                return kjl;
            }
            else
            {
                if(b0->right==b1)
                    b0->right=kjl;
                else
                    b0->left=kjl;
            }
    }

    setMaxHeight(root);
    return root;
}

void inOrder(node *rt)
{
	if(rt->left!=NULL)
		cout<<"Left: "<<rt->left->val<<"  "<<rt->left->ht<<"          ";
    else
        cout<<"                    ";

    cout<<"Centre: "<<rt->val<<"  "<<rt->ht<<"          ";

	if(rt->right!=NULL)
		cout<<"Right: "<<rt->right->val<<"  "<<rt->right->ht<<"          ";
    else
        cout<<"          ";

	cout<<endl;
	
	if(rt->left!=NULL)
		inOrder(rt->left);
	if(rt->right!=NULL)
		inOrder(rt->right);
}

int main()
{
	node *root=NULL;
	while(true)
	{
		int data;
		cin>>data;
		root = insert(root,data);
        cout<<"Address: "<<root<<endl;
		inOrder(root);
		cout<<"----------------------\n";
	}	
}
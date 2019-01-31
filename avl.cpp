//AVL Tree with depth track
#include<iostream>
using namespace std;

typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node;

void changeHeight(node *rt, int k)
{
    rt->ht=rt->ht+k;
    if(rt->left!=NULL)
        changeHeight(rt->left,k);
    if(rt->right!=NULL)
        changeHeight(rt->right,k);
}

node* LL(node *b1,node *b2,node *b3)
{
    b3->left=b1->right;
    b1->right=b3;
    b3->ht++;
    if(b3->right!=NULL)
        changeHeight(b3->right,1);
    b1->ht--;
    b2->ht--;
    if(b2->left!=NULL)
        changeHeight(b2->left,-1);
    if(b2->right!=NULL)
        changeHeight(b2->right,-1);
    return b1;
}

node* RR(node *b1,node *b2,node *b3)
{
    b3->right=b1->left;
    b1->left=b3;
    b3->ht++;
    if(b3->left!=NULL)
        changeHeight(b3->left,1);
    b1->ht--;
    b2->ht--;
    if(b2->right!=NULL)
        changeHeight(b2->right,-1);
    if(b2->left!=NULL)
        changeHeight(b2->left,-1);
    return b1;
}

node* LR(node *b1,node *b2,node *b3)
{
    b1->right=b2->left;
    b2->left=b1;
    b3->left=b2;
    b1->ht++;
    if(b1->left!=NULL)
        changeHeight(b1->left,1);
    b2->ht--;
    if(b2->right!=NULL)
        changeHeight(b2->right,-1);
    return LL(b2,b1,b3);
}

node* RL(node *b1,node *b2,node *b3)
{
    b1->left=b2->right;
    b2->right=b1;
    b3->right=b2;
    b1->ht++;
    if(b1->right!=NULL)
        changeHeight(b1->right,1);
    b2->ht--;
    if(b2->left!=NULL)
        changeHeight(b2->left,-1);
    return RR(b2,b1,b3);
}

node * insert(node * root,int dat)
{
    if(root==NULL)
    {
        root=new node();
        root->val=dat;
        root->ht=1;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    
    node *tmp=root,*b0=NULL,*b1=NULL,*b2=NULL,*ptr=NULL,*kjl=NULL;
    long count = 0;
    while(true)
    {
        count++;
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
            ptr->ht=count+1;
            if(dat>tmp->val)
                tmp->right=ptr;
            else
                tmp->left=ptr;
            break;
        }
    }
    
        if(b2==NULL)
        {
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
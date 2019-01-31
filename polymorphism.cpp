#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache: public Cache
{
    public:
    
    LRUCache(int capacity)
    {
    	cp=capacity;
    }
    
    void set(int key,int val)
    {
        if(mp.size()==cp && mp.find(key)==mp.end())
        {
        	mp.erase(head->key);
        	Node *ptr=head;
        	head=head->next;
        	delete ptr;
        }
        if(mp.find(key)!=mp.end())
        {
            Node *ptr=mp.find(key)->second;
            Node *previous=ptr->prev,*after=ptr->next;
         	delete ptr;
         	if(previous!=NULL)
         		{previous->next=after;}
         	if(after!=NULL)
         		{after->prev=previous;}
            mp.erase(key);
        }
        Node *ptr;
        if(mp.size()==0)
            {ptr=new Node(key,val);head=ptr;tail=ptr;}
        else
        {
            ptr=new Node(tail,NULL,key,val);tail=ptr;
        }
        mp.insert(pair <int, Node*> (key, ptr)); 
    }
    
    int get(int key)
    {
    	if(mp.find(key)==mp.end())
    		{return -1;}
    	else
    		{return mp.find(key)->second->value;}
    }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}


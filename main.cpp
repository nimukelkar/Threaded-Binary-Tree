#include <iostream>

using namespace std;

class node{
private:
    char data;
    bool rflag;
    bool lflag;
    node* left;
    node* right;
public:
    friend class tree;
    node()
    {
        lflag=0;
        rflag=0;
    }


};
class tree
{
    node* root;
public:
    tree()
    {

       root=NULL;

    }
    void create();
    void inorder();
    void preorder();
    void adelete(node*,node*,char x);
    void dummydel(char x)
    {

        adelete(root,root,x);
        return;
    }

};

void tree::create()
{
    bool flag=0;
    node* r;
    node* p=new node;
    node* q=new node;
    cout<<"Enter the data of the node to be inserted"<<endl;
    cin>>p->data;
    p->left=NULL;
    p->right=NULL;

    if(root==NULL)
        root=p;
    else{
            q=root;
    do
    {

        if(p->data<q->data)
        {
           if(q->left==NULL)
           {
                r=q;
                p->rflag=1;
                p->right=q;
                r->left=p;
                flag=1;
           }
           else if(q->lflag==1)
           {
            r=q;
            p->lflag=1;
            p->left=q->left;
            p->rflag=1;
            p->right=q;
            r->left=p;
            r->lflag=0;
            flag=1;
           }
           else
            q=q->left;
        }
        else
        {
            if(q->right==NULL)
            {
                r=q;
                p->lflag=1;
                p->left=q;
                r->right=p;
                flag=1;
            }
            else if(q->rflag==1){
            r=q;
            p->rflag=1;
            p->right=q->right;
            p->lflag=1;
            p->left=q;
            r->right=p;
            r->rflag=0;
            flag=1;
            }
            else
                q=q->right;
        }
    }while(flag==0);
    }
}
void tree::inorder()
{
    node* q=new node;
    q=root;
    while(q!=NULL)
    {
        while(q->left!=NULL && q->lflag!=1)
        {
            q=q->left;
        }
        cout<<q->data<<" ";
        while(q->rflag==1){
            q=q->right;
        cout<<q->data<<" ";
        }
        q=q->right;
    }

}
void tree::preorder()
{
    node* q=new node;
    q=root;
    while(q!=NULL){
    while(q->left!=NULL &&q->lflag!=1)
    {
        cout<<q->data<<" ";
        q=q->left;
    }
    cout<<q->data<<" ";
    while(q->rflag==1)
    {
        q=q->right;
    }
        q=q->right;

    }

}
void tree::adelete(node* q,node* par,char x)
{

    node* r;
    if(q==NULL){
        cout<<"No such node exists, cannot be deleted"<<endl;
        return;
    }
        if(x<q->data){
            adelete(q->left,q,x);
        }
        else if(x>q->data){
            adelete(q->right,q,x);
        }
        else{
           // cout<<"Element to be deleted is found"<<endl;


    if((q->left==NULL && q->rflag==1)||(q->right==NULL &&q->lflag==1))
    {
        if(par->left==q)
        {
            par->left=NULL;
        }
        else
        {
            par->right=NULL;
        }
        q=NULL;
        delete q;
        return;
    }


    else if((q->rflag==1) &&(q->lflag==1))
    {
        if(q==par->left)
        {
            par->lflag=1;
            par->left=q->left;
        }
        else
        {
            par->rflag=1;
            par->right=q->right;

        }
        q=NULL;
        delete q;
        return;
    }
    else if(q->rflag==1 || q->right==NULL)
    {
       r=q->left;
       while(r->rflag!=1)
       {
           r=r->right;
       }
       q->data=r->data;
       adelete(q->left,q,r->data);
       return;
    }
    else
    {
        r=q->right;
        while(r->lflag!=1)
        {
            r=r->left;

        }
        q->data=r->data;
        adelete(q->right,q,r->data);
        return;
    }
}
}









int main()
{
    tree t;
    char x;
    int choice;
    char ch='y';

    while(ch=='y'){
   cout<<"Enter\n1.To create a TBT\n2.To print inorder\n3.To print preorder\n4.To delete a node from TBT."<<endl;
   cin>>choice;
   switch(choice)
   {
   case 1:
        t.create();
        break;
   case 2:
       cout<<"The inorder of the threaded binary tree is"<<endl;
        t.inorder();
        cout<<endl;
        break;
   case 3:
       cout<<"The preorder of threaded binary tree is"<<endl;
        t.preorder();
        cout<<endl;
        break;
   case 4:
        cout<<"Enter the data of the node to be deleted"<<endl;
        cin>>x;
        t.dummydel(x);
        cout<<"Deleted successfully!"<<endl;
        t.inorder();
        cout<<endl;
   }
   cout<<"Do you want to continue enter y or n?"<<endl;
   cin>>ch;

    }








}
/*
Enter
1.To create a TBT
2.To print inorder
3.To print preorder
4.To delete a node from TBT.
1
Enter the data of the node to be inserted
q
Do you want to continue enter y or n?
y
Enter
1.To create a TBT
2.To print inorder
3.To print preorder
4.To delete a node from TBT.
1
Enter the data of the node to be inserted
w
Do you want to continue enter y or n?
y
Enter
1.To create a TBT
2.To print inorder
3.To print preorder
4.To delete a node from TBT.
1
Enter the data of the node to be inserted
e
Do you want to continue enter y or n?
y
Enter
1.To create a TBT
2.To print inorder
3.To print preorder
4.To delete a node from TBT.
1
Enter the data of the node to be inserted
r
Do you want to continue enter y or n?
y
Enter
1.To create a TBT
2.To print inorder
3.To print preorder
4.To delete a node from TBT.
1
Enter the data of the node to be inserted
t
Do you want to continue enter y or n?
y
Enter
1.To create a TBT
2.To print inorder
3.To print preorder
4.To delete a node from TBT.
1
Enter the data of the node to be inserted
y
Do you want to continue enter y or n?
y
Enter
1.To create a TBT
2.To print inorder
3.To print preorder
4.To delete a node from TBT.
2
The inorder of the threaded binary tree is
e q r t w y
Do you want to continue enter y or n?
y
Enter
1.To create a TBT
2.To print inorder
3.To print preorder
4.To delete a node from TBT.
3
The preorder of threaded binary tree is
q e w r t y
Do you want to continue enter y or n?
y
Enter
1.To create a TBT
2.To print inorder
3.To print preorder
4.To delete a node from TBT.
4
Enter the data of the node to be deleted
w
Deleted successfully!
e q r t y
Do you want to continue enter y or n?
n

Process returned 0 (0x0)   execution time : 48.829 s
Press any key to continue.

*/

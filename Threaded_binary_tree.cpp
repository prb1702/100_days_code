#include <iostream>

using namespace std;

class tbt
{
    int data;
    tbt *left,*right;
    bool rthread,lthread;
public:
    tbt* create(int);
    tbt* insertnode(tbt*,tbt*);
    void inorder(tbt*,tbt*);
    tbt* leftmostnode(tbt*,tbt*);
    void preorder(tbt*,tbt*);
};

tbt* tbt :: create(int item)
{
    tbt* newnode=new tbt;
    newnode->data=item;
    newnode->left=newnode;
    newnode->right=newnode;
    newnode->lthread=true;
    newnode->rthread=true;
    return newnode;
}

tbt* tbt :: insertnode(tbt* root,tbt* head)
{
    int key;
    cout << "Enter the element you want to insert : ";
    cin >> key;

    tbt* newnode;
    newnode=create(key);

    if(root==NULL)
    {
        head->left=newnode;
        root=newnode;
        root->left=root->right=head;
        head->lthread=false;
        return root;
    }
    else
    {
        tbt* curr=root;
        while(1)
        {
            if(curr->data==key)
            {
                cout << "Duplicate element !"<<endl;
                break;
            }
            if(key<curr->data)
            {
                if(curr->lthread)
                {
                    newnode->left=curr->left;
                    curr->left=newnode;
                    newnode->right=curr;
                    curr->lthread=false;
                    break;
                }
                else
                {
                    curr=curr->left;
                }
            }
            else
            {
                if(curr->rthread)
                {
                    newnode->left=curr;
                    newnode->right=curr->right;
                    curr->right=newnode;
                    curr->rthread=false;
                    break;
                }
                else
                {
                    curr=curr->right;
                }

            }
        }
        return root;
    }
}

tbt* tbt :: leftmostnode(tbt* root,tbt* head)
{
    tbt* curr=root;
    if(curr==NULL)
        return NULL;
    while(curr->left!=head)
    {
        if(!curr->lthread)
            curr=curr->left;
        else
        {
            return curr;
        }
    }
    return curr;
}

void tbt :: inorder(tbt* root,tbt* head)
{
    tbt* temp;
    tbt* curr=leftmostnode(root,head);

    if(curr==NULL)
        return;
    while(curr->right!=head)
    {
        cout << curr->data <<"\t";
        if(curr->rthread)
        {
            curr=curr->right;
        }
        else if(!(curr->rthread))
        {
            curr=leftmostnode(curr->right,head);
        }
    }
    cout << curr->data;
}

void tbt :: preorder(tbt* root,tbt* head)
{
    tbt* curr;
    curr=root;
    if(curr==NULL)
        return;
    while(1)
    {
        cout << curr->data << "\t";
        if(curr->lthread==false)
            curr=curr->left;
        else if(curr->rthread==false)
            curr=curr->right;
        else
        {
            while(curr->right!=head && curr->rthread==true)
            {
                curr=curr->right;
            }
            if(curr->right!=head)
            {
                curr=curr->right;
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    tbt t,*head,*root;
    root=NULL;
    head=t.create(999);

    int choice;


    int i=1;
    while(i)
    {
        cout << "\n1 for insert \n2 for inorder \n3 for preorder \n4 for exit"<<endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            root=t.insertnode(root,head);
            cout <<endl;
            break;
        case 2:
            t.inorder(root,head);
            break;
        case 3:
            t.preorder(root,head);
            break;
        case 4:
            i=0;
            break;
        default:
            cout << "invalid choice";
        }
    }

    return 0;
}

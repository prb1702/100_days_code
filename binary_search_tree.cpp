#include <iostream>

using namespace std;

class tree
{
public:
    tree *left;
    tree *right;
    int data;
    tree* create(int);
    tree* Insert(tree*);
    tree* Search(tree*,int);
    void inorder(tree*);
    void preorder(tree*);
    void del(tree*);
};

tree* tree :: create(int item)
{
    tree* newnode=new tree;
    newnode->data=item;
    newnode->right=NULL;
    newnode->left=NULL;
    return newnode;
}

tree* tree :: Insert(tree* root)
{
    int key;
    cout << "Enter the element you want to insert : ";
    cin >> key;
    tree* curr;
    tree* newnode=create(key);

    if(root==NULL)
    {
        root=newnode;
    }
    else
    {
        curr=root;
        while(1)
        {
            if(key==curr->data)
                return NULL;
            else if(key < curr->data && curr->left==NULL)
            {
                curr->left=newnode;
                return root;
            }
            else if(key < curr->data)
            {
                curr=curr->left;
            }
            else if(key > curr->data && curr->right==NULL)
            {
                curr->right=newnode;
                return root;
            }
            else
            {
                curr=curr->right;
            }
        }
    }
    return root;
}

tree* tree :: Search(tree* root,int key)
{
    /*int key;
    cout << "Enter the element you want to search : ";
    cin >> key;*/

    tree* curr;
    curr=root;

    while(1)
    {
        if(curr==NULL)
            return 0;
        while(curr!=NULL)

        {
            if(key==curr->data)
            {
                return curr;
            }
            else if(key < curr->data)
            {
                curr=curr->left;
            }
            else if(key > curr->data)
            {
                curr=curr->right;
            }
        }
    }
    return curr;
}

void tree :: del(tree* root)
{
    tree* curr=root;
    tree* prev;
    int key;
    cout << "Enter the element you want to delete : ";
    cin >> key;

    if(curr==NULL)
        return;
    while(curr!=NULL && key!=curr->data)
    {
        prev=curr;
        if(key<curr->data)
            curr=curr->left;
        else
            curr=curr->right;
    }
    cout << curr->data << endl;
    if(curr->right==NULL && curr->left==NULL)
    {
        if(curr==prev->right)
        {
            prev->right=NULL;
        }
        else if(curr==prev->left)
        {
            prev->left=NULL;
        }
    }
    else if(curr->left==NULL)
    {
        if(curr->right->data < prev->data)
        {
            prev->left=curr->right;
        }
        else
        {
            prev->right = curr->right;
        }
    }
    else if(curr->left != NULL && curr->right == NULL)
    {
        if(curr->left->data < prev->data)
        {
            prev->left=curr->left;
        }
        else
        {
            prev->right = curr->left;
        }
    }
    else if(curr->left!=NULL && curr->right!=NULL)
    {
        tree* rmin=curr->right;
        while(rmin->left!=NULL)
        {
            rmin=rmin->left;
        }
        curr->data=rmin->data;
        if(rmin=curr->right)
        {
            curr->right=NULL;
        }
        delete rmin;
    }

}

void tree :: inorder(tree* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data<<"\t";
    inorder(root->right);
}

void tree :: preorder(tree* root)
{
    if(root==NULL)
        return;
    cout << root->data<<"\t";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    tree t;
    tree* root=NULL;
    tree* srch;

    int i=1,choice;
    while(i)
    {
        cout << "\n1 for insert \n2 for inorder \n3 for preorder \n4 for search \n5 for
             delete \n6 for exit" <<endl;
             cout << "Enter your choice : ";
    cin >> choice;
    switch(choice)
        {
        case 1:
            root=t.Insert(root);
            break;
        case 2:
            t.inorder(root);
            break;
        case 3:
            t.preorder(root);
            break;
        case 4:
            int key;
            cout << "Enter the element you want to search : ";
            cin >> key;
            srch=t.Search(root,key);
            if(srch==NULL)
            {
                cout << "Element not found !" << endl;
            }
            else
            {
                cout << "Element found !" << endl;
            }
            break;
        case 5:
            t.del(root);
            break;
        case 6:
            i=0;
            break;
        default:
            cout << "Invalid choice !" <<endl;
        }
    }

    return 0;
}

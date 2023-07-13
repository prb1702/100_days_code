#include <iostream>

using namespace std;

class tree
{
public:
    tree* left;
    tree* right;
    int data;
    tree * create(int);
    tree* Insert(tree*);
    tree * Search(tree*, int);
    tree* inorder(tree*);
    tree* preorder(tree*);
    tree* minValueNode(tree*);
    tree* deleteNode(tree*,int);
};


tree* tree :: create(int item)
{
    tree* newnode = new tree;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = item;

    return newnode;
}

tree* tree :: Insert(tree* root)
{
    int key;
    cout << "Enter the data you want to insert : ";
    cin >> key;

    tree* newnode;
    tree* curr;

    newnode = create(key);

    if(root == NULL)
    {
        root=newnode;
    }
    else
    {
        curr = root;
        while(1)
        {
            if(key == curr->data)
            {
                cout << "Element already exists !";
                return root;
            }
            else if(key < curr->data && curr->left == NULL)
            {
                curr->left = newnode;
                return root;
            }
            else if(key < curr->data)
            {
                curr=curr->left;
            }
            else if(key > curr->data && curr->right == NULL)
            {
                curr->right = newnode;
                return root;
            }
            else if(key > curr->data)
            {
                curr = curr->right;
            }
        }
    }
    return root;
}

tree* tree :: Search(tree* root, int key)
{
    tree* curr = root;
    while(1)
    {
        if(curr==NULL)
        {
            return 0;
        }
        while(curr!=NULL)
        {
            if(key == curr->data)
            {
                return curr;
            }
            else if(key < curr->data)
            {
                curr = curr->left;
            }
            else if(key > curr->data)
            {
                curr=curr->right;
            }
        }
    }
    return curr;
}


tree* tree :: inorder(tree* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    inorder(root->left);
    cout << root->data << "\t";
    inorder(root->right);
}

tree* tree :: preorder(tree* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    cout << root->data << "\t";
    preorder(root->left);
    preorder(root->right);
}

tree* tree :: minValueNode(tree* node)
{
    tree* curr = node;
    while(curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}

tree* tree :: deleteNode(tree* root,int key)
{
    tree* temp;
    if(root==NULL)
    {
        return NULL;
    }
    else if(key < root->data)
    {
        root->left = deleteNode(root->left,key);
    }
    else if(key > root->data)
    {
        root->right = deleteNode(root->right,key);
    }
    else
    {
        /*node with only one child or no child*/
        if(root->left == NULL)
        {
            temp =root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            temp=root->left;
            delete root;
            return temp;
        }

        /*node with two children*/

        else
        {
            temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
        return root;
    }
}

int main()
{

    tree t;

    tree* root = NULL;
    tree* s;

    int i=1;
    int ch;
    int key;

    while(i)
    {
        cout << "\n1 for insert\n2 for search\n3 for inorder\n4 for preorder\n5 for delete";
        cout << "\nEnter your choice : ";
        cin >> ch;

        switch(ch)
        {
        case 1:
            root = t.Insert(root);
            break;
        case 2:
            int key;
            cout << "Enter the key you want to search : " << endl;
            cin >> key;
            s = t.Search(root,key);
            if(s==NULL)
            {
                cout << "Element not found!" << endl;
            }
            else{
                cout << "Element found!" << endl;
            }
            break;
        case 3:
            t.inorder(root);
            break;
        case 4:
            t.preorder(root);
            break;
        case 5:
            cout << "Enter the element you want to delete : ";
            cin >> key;
            root = t.deleteNode(root,key);
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }



    return 0;
}

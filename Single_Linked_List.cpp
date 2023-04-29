#include <iostream>

using namespace std;

class node
{
    int data;
    node *next;
public:
    node()
    {
        next=NULL;
    }

    void insertAtTail(node* &head,int data);
    void insertAtHead(node* &head,int data);
    void insertAfter(node* &head,int val,int after);
    void deletenode(node* &head,int val);
    void updatenode(node* &head,int val,int newval);
    void display(node * head);
};

void node :: insertAtTail(node* &head,int val)
{
    node * newnode = new node;
    newnode->data = val;
    newnode->next=NULL;

    if(head==NULL)
    {
        head=newnode;
        return;
    }

    node *temp=head;

    while(temp->next!=NULL)
    {
        //cout << temp->data << endl;
        temp=temp->next;
    }
    temp->next=newnode;
}

void node :: insertAtHead(node* &head,int val)
{
    node * newnode = new node;
    newnode->data = val;

    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        return;
    }

    node *temp=head;
    newnode->next = head;
    head = newnode;
}

void node :: insertAfter(node* &head,int val,int after)
{
    node * newnode = new node;
    newnode->data = val;
    int flag=1;

    node * temp=head;
    if(head==NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    else
    {
        while(flag)
        {
            while(temp->next!=NULL)
            {
                if(temp->data==after)
                {
                    newnode->next = temp->next;
                    temp->next = newnode;
                    return;
                }
                else
                {
                    temp=temp->next;
                }
            }
            if(temp->data==after)
            {
                newnode->next = NULL;
                temp->next = newnode;
                return;
            }
            else
            {
                cout << "Element not found!" << endl;
                return;
            }
        }
    }
}

void node :: deletenode(node* &head,int val)
{
    node* temp = head;
    node* prev;

    if(temp->data==val)
    {
        head=temp->next;
        delete temp;
        return;
    }

    while(temp->data != val && temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp->data==val)
    {
        prev->next=temp->next;
        delete temp;
        return;
    }
    else
    {
        cout << "Element not found!" << endl;
    }
}

void node :: updatenode(node* &head,int val,int newval)
{
    node* temp = head;

    if(temp->data == val)
    {
        temp->data=newval;
        return;
    }
    while(temp->data!=val && temp->next!=NULL)
    {
        temp=temp->next;
    }
    if(temp->data==val)
    {
        temp->data=newval;
        return;
    }
    else{
        cout << "Element not found!" << endl;
    }
}

void node :: display(node * head)
{
    node *temp = head;

    cout << temp->data << "\t";

    while(temp->next!=NULL)
    {
        //cout << "Entered : " << endl;
        temp=temp->next;
        cout << temp->data << "\t";
    }
    cout << endl;
}



int main()
{
    node n;

    node * head = NULL;
    /*int element;

    cout << "Enter value : " << endl;
    cin >> element;

    n.insertAtTail(head,element);

    int b;

    cout << "Enter value : " << endl;
    cin >> b;*/

    //n.insertAtTail(head,10);
    //n.insertAtTail(head,20);
    /*n.insertAtTail(head,30);
    n.insertAtTail(head,40);*/

    //n.display(head);

    int choice,element,after,i=1;
    int val,newval;

    while(i)
    {
        cout << "\nEnter your choice :\n1 for insert at tail\n2 for insert at head\n3 for insertion after a given node\n4 for delete\n5 for update\n6 for display\n7 for exit" << endl;
        cin >> choice;

        switch(choice)
        {
        case 1:
            cout << "\nEnter data you want to insert into a linked list : ";
            cin >> element;
            n.insertAtTail(head,element);
            break;
        case 2:
            cout << "\nEnter data you want to insert into a linked list : ";
            cin >> element;
            n.insertAtHead(head,element);
            break;
        case 3:
            cout << "\nEnter the data after which you want to insert an element : ";
            cin >> after;

            cout << "\nEnter data you want to insert into a linked list : ";
            cin >> element;
            n.insertAfter(head,element,after);
            break;
        case 4:
            cout << "Enter the data of the node you want to delete : ";
            cin >> element;
            n.deletenode(head,element);
            break;
        case 5:
            cout << "Enter the data you want to update : ";
            cin >> val;

            cout << "Enter new value : ";
            cin >> newval;

            n.updatenode(head,val,newval);
            break;
        case 6:
            n.display(head);
            break;
        case 7:
            i=0;
            break;

        }
    }

    return 0;
}

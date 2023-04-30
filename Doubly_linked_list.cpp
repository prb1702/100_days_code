#include <iostream>

using namespace std;

class node
{
    int data;
    node *prev,*next;
public:
    node()
    {
        prev=NULL;
        next=NULL;
    }

    void insertAtTail(node* &head,int val);
    void insertAtHead(node* &head,int val);
    void insertAfter(node* &head,int val,int element);
    void deletenode(node* &head,int val);
    void display(node* head);
};

void node :: insertAtTail(node* &head,int val)
{
    node* newnode = new node;
    newnode->data = val;
    newnode->next=NULL;

    if(head==NULL)
    {
        head=newnode;
        newnode->prev=NULL;
        return;
    }

    node* temp = head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newnode;
    newnode->prev=temp;
}

void node :: insertAtHead(node* &head,int val)
{
    node* newnode = new node;
    newnode->data = val;
    newnode->prev=NULL;

    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        return;
    }

    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}

void node :: insertAfter(node* &head,int val,int element)
{
    node* newnode = new node;
    newnode->data = element;

    node* temp=head;
    node* prev;

    while(temp->data!=val && temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }

    if(temp->data==val && temp->next==NULL)
    {
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=NULL;
    }
    else if(temp->data==val)
    {
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
    }
    else{
        cout << "Element not found !" << endl;
    }

}

void node :: deletenode(node* &head,int val)
{
    node* temp = head;
    node* prev=temp;

    if(temp->data==val && temp->next!=NULL)
    {
        temp->next->prev=NULL;
        head=temp->next;
        delete temp;
        return;
    }
    else if(temp->data==val && temp->next==NULL)
    {
            head=NULL;
            delete temp;
            return;
    }

    while(temp->data!=val && temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }

    if(temp->data==val && temp->next==NULL)
    {
        prev->next=temp->next;
        delete temp;
        return;
    }
    else if(temp->data==val)
    {
        prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
        return;
    }
    else{
        cout << "Element not found !" << endl;
    }
}

void node :: display(node* head)
{
    if(head==NULL)
    {
        cout << "Linked list is empty!" << endl;
        return;
    }

    node* temp=head;
    cout << "\nThe linked list is as follows : ";

    while(temp!=NULL)
    {
        cout << temp->data << "\t";
        temp=temp->next;
    }

    cout << endl;
}

int main()
{
    node n;

    node* head = NULL;

    /*n.insertAtTail(head,10);
    n.insertAtTail(head,20);
    n.insertAtTail(head,30);
    n.insertAtTail(head,40);
    n.insertAtTail(head,50);
    n.display(head);*/

    int i=1,choice,element,after;

    while(i)
    {
        cout << "\n1 for insert at tail\n2 for insert at head\n3 for insert in the middle\n4 for delete\n5 for display\n6 for exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            cout << "Enter the data you want to insert : ";
            cin >> element;
            n.insertAtTail(head,element);
            break;
        case 2:
            cout << "Enter the data you want to insert : ";
            cin >> element;
            n.insertAtHead(head,element);
            break;
        case 3:
            cout << "Enter the data after which you wish to insert new data : ";
            cin >> after;

            cout << "Enter new data : ";
            cin >> element;

            n.insertAfter(head,after,element);

            break;
        case 4:
            cout << "Enter the data you want to delete : ";
            cin >> element;

            n.deletenode(head,element);
            break;
        case 5:
            n.display(head);
            break;
        case 6:
            i=0;
            break;
        default:
            cout << "Invalid input!" << endl;
        }
    }



    return 0;
}

#include <iostream>

using namespace std;

class Queue
{
    int data;
    Queue *next,*fr,*rear;
public:
    Queue()
    {
        next=NULL;
        fr=NULL;
        rear=NULL;
    }

    void enqueue(int);
    void dequeue();
    void display();
};

void Queue :: enqueue(int element)
{
    Queue *newnode = new Queue;
    newnode->data = element;
    newnode->next=NULL;
    if(fr==NULL && rear==NULL)
    {
        rear=newnode;
        fr=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void Queue :: dequeue()
{
    if(rear==NULL && fr==NULL)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        Queue *temp = fr;
        cout << "Dequeued element is : " << fr->data << endl;
        if(rear==fr)
        {
            rear=fr=NULL;
        }
        else
        {
            fr=fr->next;
            //cout << fr << " " << rear << endl;
            delete temp;
        }

    }
}

void Queue :: display()
{
    if(rear==NULL && fr==NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    //cout << fr << " " << rear << endl;
    Queue * temp = fr;

    cout << temp->data << "\t";

    /*if(temp->next==NULL)
    {
        cout << "NULL" << endl;
    }
    else{
        cout << "Not NULL" << endl;
    }*/

    while(temp->next!=NULL)
    {
        temp=temp->next;
        cout << temp->data << "\t";
    }
}

int main()
{

    Queue q;
    /*int n;

    cout << "Enter the number of elements : ";
    cin >> n;

    int arr[n];*/

    cout << "Enter\n1 for enqueue\n2 for dequeue\n3 for display\n4 for exit" << endl;

    int i=1,choice;

    while(i)
    {
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            int element;
            cout << "Enter an element you want to enqueue : ";
            cin >> element;
            q.enqueue(element);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            i=0;
            break;
        default:
            cout << "Invalid input!";
        }
    }

    return 0;
}

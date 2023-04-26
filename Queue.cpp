#include <iostream>

using namespace std;

class Queue
{
    int rear;
    int fr;
public:
    Queue()
    {
        rear=-1;
        fr=-1;
    }
    bool isEmpty();
    bool isFull(int [],int);
    void enqueue(int [],int,int);
    int dequeue(int []);
    void display(int []);
};

bool Queue :: isEmpty()
{
    if(rear==-1 && fr==-1)
    {
        return true;
    }
    else{
        return false;
    }
}

bool Queue :: isFull(int arr[],int n)
{
    if(rear==n-1)
    {
        return true;
    }
    else{
        return false;
    }
}

void Queue :: enqueue(int arr[],int val,int n)
{
    if(isFull(arr,n))
    {
        cout << "Queue is full";
    }
    else{
        rear++;
        arr[rear]=val;
        if(fr==-1)
        {
            fr++;
        }
    }
}

int Queue :: dequeue(int arr[])
{
    int d;
    if(isEmpty())
    {
        cout << "Queue is empty" << endl;
        return 0;
    }
    else{
        if(fr==rear)
        {
            d=arr[fr];
            fr=rear=-1;
        }
        else{
            d=arr[fr];
            fr++;
        }
        return d;
    }
}

void Queue :: display(int arr[])
{
    for(int i=fr;i<=rear;i++)
    {
        cout << arr[i] << "\t";
    }
}

int main()
{
    Queue q;
    int n;

    cout << "Enter the number of elements : ";
    cin >> n;

    int arr[n];

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
            q.enqueue(arr,element,n);
            break;
        case 2:
            {
                int d;
                d=q.dequeue(arr);
                cout << "Dequeued element is : " << d <<endl;
                break;
            }
        case 3:
            q.display(arr);
            break;
        case 4:
            i=0;
            break;
        case 5:
            {
                bool res = q.isFull(arr,n);
                cout << res << endl;
                break;
            }
        case 6:
            {
                bool emp = q.isEmpty();
                cout << emp << endl;
                break;
            }
        default:
            cout << "Invalid input!";
        }
    }
    return 0;
}

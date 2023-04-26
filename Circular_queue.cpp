#include <iostream>

using namespace std;

class Cqueue
{
    int rear;
    int fr;
public:
    Cqueue(){
        rear=-1;
        fr=-1;
    }

    bool isEmpty(int arr[]);
    bool isFull(int arr[],int n);
    void enqueue(int arr[],int element,int n);
    int dequeue(int arr[],int n);
    void display(int arr[],int n);
};

bool Cqueue :: isEmpty(int arr[])
{
    if(rear==-1 && fr==-1)
    {
        return true;
    }
    else{
        return false;
    }
}

bool Cqueue :: isFull(int arr[],int n)
{
    if((rear+1)%n==fr)
    {
        return true;
    }
    else{
        return false;
    }
}

void Cqueue :: enqueue(int arr[],int element,int n)
{
    if(isFull(arr,n))
    {
        cout << "Queue is full" << endl;
    }
    else{
        rear=(rear+1)%n;
        arr[rear] = element;
        if(fr==-1)
        {
            fr++;
        }
    }
}

int Cqueue :: dequeue(int arr[],int n)
{
    if(isEmpty(arr))
    {
        cout << "Queue is empty" << endl;
        return 0;
    }
    else
    {
        int d=arr[fr];
        if(rear==fr)
        {
            rear=-1;
            fr=-1;
        }
        else
        {
            fr=(fr+1)%n;
        }
        return d;
    }
}

void Cqueue :: display(int arr[],int n)
{
    int i=fr;
    do{
        cout << arr[i] << "\t";
        i=(i+1)%n;
    }while(i!=(rear+1)%n);
}


int main()
{
    Cqueue c;

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
            c.enqueue(arr,element,n);
            break;
        case 2:
            {
                int d;
                d=c.dequeue(arr,n);
                cout << "Dequeued element is : " << d << endl;
                break;
            }
        case 3:
            c.display(arr,n);
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

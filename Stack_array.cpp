#include <iostream>

using namespace std;

class Stack
{
    int top;
    int arr[5];
public:
    Stack()
    {
        top=-1;
        for(int i=0;i<5;i++)
        {
            arr[i]=0;
        }
    }

    bool isEmpty();
    bool isFull();
    void push(int);
    int pop();
    int Count();
    int peek(int);
    void display();
};

bool Stack :: isEmpty()
{
    if(top==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack :: isFull()
{
    if(top==4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Stack :: push(int data)
{
    if(isFull())
    {
        cout << "Stack is full! Cannot push an element" <<endl;
    }
    else{
        top++;
        arr[top]=data;
    }
}

int Stack :: pop()
{
    if(isEmpty())
    {
        cout << "stack is empty" << endl;
        return 0;
    }
    else
    {
        int popVal = arr[top];
        arr[top]=0;
        top--;
        return popVal;
    }
}

int Stack :: Count()
{
    return (top+1);
}

int Stack :: peek(int ind)
{
    if(isEmpty())
    {
        cout << "Stack underflow" << endl;
        return 0;
    }
    else{
        return arr[ind];
    }
}

void Stack :: display()
{
    for(int i=4;i>=0;i--)
    {
         cout << arr[i] << "\t";
    }
}

int main()
{
    Stack s;

    cout << "Enter\n1 for push\n2 for pop\n3 for peek\n4 for count\n5 for display\n6 for exit" << endl;

    int choice,i=1;

    while(i)
    {
        cout << "Enter your choice : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            int element;
            cout << "Enter an element to push onto stack : " ;
            cin >> element;
            s.push(element);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            {
                int pos;
                cout << "Enter the position : ";
                cin >> pos;
                pos=s.peek(pos);
                cout << "Element at the entered position : " << pos << endl;
                break;
            }
        case 4:
            {
                int cnt = s.Count();
                cout << "Count of elements in the stack : " << cnt << endl;
                break;
            }
        case 5:
            s.display();
            break;
        case 6:
            i=0;
            break;
        default:
            cout << "Invalid input" << endl;
        }
    }

    return 0;
}

#include <iostream>

using namespace std;

class Stack
{
    int data;
    Stack *next,*top;
public:
    Stack()
    {
        top=NULL;
    }
    void push(int);
    void pop();
    void display();
};

void Stack :: push(int element)
{
    Stack *newnode = new Stack;
    newnode->data = element;
    newnode->next = NULL;
    if(top==NULL)
    {
        top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
}

void Stack :: pop()
{
    if(top==NULL)
    {
        cout << "Stack is empty";
    }
    else
    {
        Stack *ptr=top;
        top=top->next;
        delete ptr;
    }
}

void Stack :: display()
{
    Stack * temp = top;
    while(temp!=NULL)
    {
        cout << temp->data;
        cout << " ";
        temp=temp->next;
    }
}

int main()
{
    Stack s;

    cout << "Enter\n1 for push\n2 for pop\n3 for display\n4 for exit" << endl;

    int i=1,choice;

    while(i)
    {
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            int element;
            cout << "Enter an element you want to push onto stack : ";
            cin >> element;
            s.push(element);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
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

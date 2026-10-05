#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class Stack
{
    Node* top;

public:

    Stack()
    {
        top = NULL;
    }

    void push(int value)
    {
        Node* newNode = new Node();

        newNode->data = value;
        newNode->next = top;

        top = newNode;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }

        Node* temp = top;

        cout << "Removed: " << temp->data << endl;

        top = top->next;

        delete temp;
    }

    void peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Top: " << top->data << endl;
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = top;

        while (temp != NULL)
        {
            cout << temp->data << " ";

            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    Stack s;

    int choice;
    int value;

    do
    {
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter value: ";
            cin >> value;

            s.push(value);
        }
        else if (choice == 2)
        {
            s.pop();
        }
        else if (choice == 3)
        {
            s.peek();
        }
        else if (choice == 4)
        {
            s.display();
        }

    } while (choice != 5);

    return 0;
}

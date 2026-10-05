#include <iostream>
using namespace std;

class Stack
{
    int stack[100];
    int top;
    int size;

public:

    Stack(int n)
    {
        top = -1;
        size = n;
    }

    void push(int value)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;

        stack[top] = value;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }

        cout << "Removed: " << stack[top] << endl;

        top--;
    }

    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Top: " << stack[top] << endl;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    int n;

    cout << "Enter stack size: ";
    cin >> n;

    Stack s(n);

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

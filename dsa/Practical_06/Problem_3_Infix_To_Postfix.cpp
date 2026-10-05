#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class Stack
{
    char arr[100];
    int top;

public:

    Stack()
    {
        top = -1;
    }

    void push(char ch)
    {
        top++;

        arr[top] = ch;
    }

    char pop()
    {
        char ch = arr[top];

        top--;

        return ch;
    }

    char peek()
    {
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};

int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }

    if (ch == '*' || ch == '/')
    {
        return 2;
    }

    if (ch == '+' || ch == '-')
    {
        return 1;
    }

    return 0;
}

int main()
{
    char infix[100];
    char postfix[100];

    cout << "Enter infix expression: ";
    cin >> infix;

    Stack s;

    int j = 0;

    for (int i = 0; i < strlen(infix); i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j] = ch;

            j++;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && s.peek() != '(')
            {
                postfix[j] = s.pop();

                j++;
            }

            if (!s.empty())
            {
                s.pop();
            }
        }
        else
        {
            while (!s.empty() &&
                   s.peek() != '(' &&
                   precedence(s.peek()) >= precedence(ch))
            {
                postfix[j] = s.pop();

                j++;
            }

            s.push(ch);
        }
    }

    while (!s.empty())
    {
        postfix[j] = s.pop();

        j++;
    }

    postfix[j] = '\0';

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}

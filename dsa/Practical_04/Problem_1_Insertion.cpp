#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insertBeginning(Node*& head, int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = head;

    head = newNode;
}

void insertEnd(Node*& head, int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertPosition(Node*& head, int value, int position)
{
    if (position < 1)
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (position == 1)
    {
        insertBeginning(head, value);
        return;
    }

    if (head == NULL)
    {
        cout << "Invalid position" << endl;
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1; i++)
    {
        if (temp->next == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }

        temp = temp->next;
    }

    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = temp->next;

    temp->next = newNode;
}

void display(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node* head = NULL;

    int choice;
    int value;
    int position;

    do
    {
        cout << "\n1. Insert at beginning";
        cout << "\n2. Insert at end";
        cout << "\n3. Insert at position";
        cout << "\n4. Display";
        cout << "\n5. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter value: ";
            cin >> value;

            insertBeginning(head, value);
            display(head);
        }
        else if (choice == 2)
        {
            cout << "Enter value: ";
            cin >> value;

            insertEnd(head, value);
            display(head);
        }
        else if (choice == 3)
        {
            cout << "Enter value: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> position;

            insertPosition(head, value, position);
            display(head);
        }
        else if (choice == 4)
        {
            display(head);
        }

    } while (choice != 5);

    return 0;
}

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

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

void deleteValue(Node*& head, int value)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    if (head->data == value)
    {
        Node* temp = head;

        head = head->next;

        delete temp;

        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data != value)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "Value not found" << endl;
        return;
    }

    Node* deleteNode = temp->next;

    temp->next = deleteNode->next;

    delete deleteNode;
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

void reversePrint(Node* head)
{
    if (head == NULL)
    {
        return;
    }

    reversePrint(head->next);

    cout << head->data << " ";
}

int main()
{
    Node* head = NULL;

    int n;
    int value;
    int deleteValueInput;

    cout << "Enter number of patients: ";
    cin >> n;

    cout << "Enter patient tokens: ";

    for (int i = 0; i < n; i++)
    {
        cin >> value;

        insertEnd(head, value);
    }

    cout << "Forward queue: ";
    display(head);

    cout << "Enter token to delete: ";
    cin >> deleteValueInput;

    deleteValue(head, deleteValueInput);

    cout << "After deletion: ";
    display(head);

    cout << "Reverse queue: ";
    reversePrint(head);

    cout << endl;

    return 0;
}

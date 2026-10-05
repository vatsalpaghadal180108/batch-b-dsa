#include <iostream>
using namespace std;

struct SNode
{
    int data;
    SNode* next;
};

struct DNode
{
    int data;
    DNode* prev;
    DNode* next;
};

void insertSinglyCircular(SNode*& head, int value)
{
    SNode* newNode = new SNode();

    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    SNode* temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

void deleteSinglyCircular(SNode*& head, int value)
{
    if (head == NULL)
    {
        return;
    }

    if (head->data == value)
    {
        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        SNode* last = head;

        while (last->next != head)
        {
            last = last->next;
        }

        SNode* temp = head;

        head = head->next;
        last->next = head;

        delete temp;

        return;
    }

    SNode* temp = head;

    while (temp->next != head && temp->next->data != value)
    {
        temp = temp->next;
    }

    if (temp->next != head)
    {
        SNode* deleteNode = temp->next;

        temp->next = deleteNode->next;

        delete deleteNode;
    }
}

void displaySinglyCircular(SNode* head)
{
    if (head == NULL)
    {
        cout << "Empty circle" << endl;
        return;
    }

    SNode* temp = head;

    do
    {
        cout << temp->data << " ";

        temp = temp->next;
    }
    while (temp != head);

    cout << endl;
}

void insertDoublyCircular(DNode*& head, int value)
{
    DNode* newNode = new DNode();

    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;

        newNode->next = head;
        newNode->prev = head;

        return;
    }

    DNode* last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = newNode;
    head->prev = newNode;
}

void deleteDoublyCircular(DNode*& head, int value)
{
    if (head == NULL)
    {
        return;
    }

    DNode* temp = head;

    do
    {
        if (temp->data == value)
        {
            break;
        }

        temp = temp->next;

    } while (temp != head);

    if (temp->data != value)
    {
        cout << "Student not found" << endl;
        return;
    }

    if (temp->next == temp)
    {
        delete temp;

        head = NULL;

        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if (temp == head)
    {
        head = temp->next;
    }

    delete temp;
}

void displayDoublyCircular(DNode* head)
{
    if (head == NULL)
    {
        cout << "Empty circle" << endl;
        return;
    }

    DNode* temp = head;

    do
    {
        cout << temp->data << " ";

        temp = temp->next;

    } while (temp != head);

    cout << endl;
}

int main()
{
    SNode* sHead = NULL;
    DNode* dHead = NULL;

    int n;
    int value;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter student numbers: ";

    for (int i = 0; i < n; i++)
    {
        cin >> value;

        insertSinglyCircular(sHead, value);
        insertDoublyCircular(dHead, value);
    }

    cout << "\nSingly Circular List: ";
    displaySinglyCircular(sHead);

    cout << "Doubly Circular List: ";
    displayDoublyCircular(dHead);

    cout << "\nEnter student to remove: ";
    cin >> value;

    deleteSinglyCircular(sHead, value);
    deleteDoublyCircular(dHead, value);

    cout << "After deletion:" << endl;

    cout << "Singly Circular List: ";
    displaySinglyCircular(sHead);

    cout << "Doubly Circular List: ";
    displayDoublyCircular(dHead);

    return 0;
}

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

void addBeginning(Node*& head, int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;
}

void addEnd(Node*& head, int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    newNode->prev = temp;
    temp->next = newNode;
}

void insertAfter(Node* head, int song, int value)
{
    Node* temp = head;

    while (temp != NULL && temp->data != song)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Song not found" << endl;
        return;
    }

    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void removeFirst(Node*& head)
{
    if (head == NULL)
    {
        cout << "Playlist is empty" << endl;
        return;
    }

    Node* temp = head;

    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    delete temp;
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

int countSongs(Node* head)
{
    int count = 0;

    Node* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

int main()
{
    Node* head = NULL;

    int choice;
    int value;
    int song;

    do
    {
        cout << "\n1. Add at beginning";
        cout << "\n2. Add at end";
        cout << "\n3. Insert after song";
        cout << "\n4. Remove first song";
        cout << "\n5. Count songs";
        cout << "\n6. Display";
        cout << "\n7. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter song number: ";
            cin >> value;

            addBeginning(head, value);
            display(head);
        }
        else if (choice == 2)
        {
            cout << "Enter song number: ";
            cin >> value;

            addEnd(head, value);
            display(head);
        }
        else if (choice == 3)
        {
            cout << "Enter existing song: ";
            cin >> song;

            cout << "Enter new song: ";
            cin >> value;

            insertAfter(head, song, value);
            display(head);
        }
        else if (choice == 4)
        {
            removeFirst(head);
            display(head);
        }
        else if (choice == 5)
        {
            cout << "Number of songs: " << countSongs(head) << endl;
        }
        else if (choice == 6)
        {
            display(head);
        }

    } while (choice != 7);

    return 0;
}

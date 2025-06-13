#include <iostream>

using namespace std;

// ? Node class
class Node
{
public:
    // * Attributes
    int value;
    Node *next;

    // * Constructor
    Node(int value) : value(value), next(NULL) {}
};

// ? Circular Linked List
class CircularLinkedList
{
    // * Attributes
    Node *head, *tail;

public:
    // * Constructor
    CircularLinkedList() : head(NULL), tail(NULL) {}

    // * Method - Insert at head
    void insert_at_head(int value)
    {
        // ? Create new node
        Node *node = new Node(value);

        // ? Create links
        if (head == NULL)
            head = tail = node;

        else
        {
            node->next = head;
            head = node;
        }
        tail->next = head;
    }

    // * Method - Insert at tail
    void insert_at_tail(int value)
    {
        // ? Create new node
        Node *node = new Node(value);

        // ? Create links
        if (head == NULL)
            head = tail = node;
        
        else
        {
            tail->next = node;
            tail = node;
        }
        tail->next = head;
    }

    // * Method - Pop from head
    void pop_from_head()
    {
        // ? Establish temp node
        Node *temp = head;

        // ? Remove links
        head = head->next;
        tail->next = head;

        // ? Remove from head
        delete temp;
    }

    // * Method - Pop from tail
    void pop_from_tail()
    {
        // ? Establish temp node
        Node *node = head, *temp = tail;

        while (node->next != tail)
            node = node->next;
        
        // ? Remove links
        tail = node;
        tail->next = head;

        // ? Remove from tail
        delete temp;
    }

    // * Method - Print the list
    void print()
    {
        if (head == NULL)
            return;
        
        Node *start = head;

        while (start != tail)
        {
            cout << start->value << "->";
            start = start->next;
        }
        cout << start->value << endl;
    }
};

int main()
{
    // ? Create object
    CircularLinkedList list;

    // ? Insert values
    list.insert_at_head(3);
    list.insert_at_head(2);
    list.insert_at_head(1);

    list.insert_at_tail(4);
    list.insert_at_tail(5);
    list.insert_at_tail(6);

    // ? Remove values
    list.pop_from_head();
    list.pop_from_tail();

    // ? Print the list
    list.print();
}

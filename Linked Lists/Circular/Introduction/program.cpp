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
    void delete_at_head()
    {
        if (head == NULL)
            return;

        // ? Establish temp node
        Node *temp = head;

        // ? Remove links
        if (head != tail)
        {
            head = head->next;
            tail->next = head;
        }
        else
        {
            head = tail = NULL;
        }

        // ? Remove from head
        delete temp;
    }

    // * Method - Pop from tail
    void delete_at_tail()
    {
        if (head == NULL)
            return;

        // ? Establish temp node
        Node *temp = tail;

        if (head != tail)
        {
            // ? Find the 2nd last node
            Node *node = head;
            while (node->next != tail)
                node = node->next;

            // ? Remove links
            tail = node;
            tail->next = head;
        }
        else
        {
            head = tail = NULL;
        }

        // ? Remove from tail
        delete temp;
    }

    // * Method - Print the list
    void print()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node *start = head;

        while (start != tail)
        {
            cout << start->value << "->";
            start = start->next;
        }
        cout << start->value << endl;
    }

    // * Destructor
    ~CircularLinkedList()
    {
        while (head != NULL)
            delete_at_head();
    }
};

int main()
{
    // ? Create object
    CircularLinkedList list;

    // ? Insert values
    list.insert_at_head(5);
    list.insert_at_head(4);
    list.insert_at_head(3);
    list.insert_at_head(2);
    list.insert_at_head(1);
    list.insert_at_head(0);

    list.insert_at_tail(6);
    list.insert_at_tail(7);
    list.insert_at_tail(8);
    list.insert_at_tail(9);
    list.insert_at_tail(10);

    // ? Remove values
    list.delete_at_head();
    list.delete_at_tail();

    // ? Print the list
    list.print();
}

#include <iostream>

using namespace std;

// ? Node
class Node
{
public:
    // * Attributes
    int value;
    Node *next, *previous;

    // * Constructor
    Node(int value) : value(value), next(NULL), previous(NULL) {}
};

// ? Double linked list
class LinkedList
{
    // * Attributes
    Node *head, *tail;

public:
    // * Constructor
    LinkedList() : head(NULL), tail(NULL) {}

    // * Method - Add a node at front
    void push_front(int value)
    {
        // ? New node
        Node *node = new Node(value);

        // ? Create links
        if (head == NULL)
            tail = node;

        else
        {
            node->next = head;
            head->previous = node;
        }

        head = node;
    }

    // * Method - Add a node at back
    void push_back(int value)
    {
        // ? New node
        Node *node = new Node(value);

        // ? Create links
        if (head == NULL)
            head = node;

        else
        {
            node->previous = tail;
            tail->next = node;
        }

        tail = node;
    }

    // * Method - Pop a node from front
    void pop_front()
    {
        if (head != NULL)
        {
            // ? Get address of head node
            Node *start = head;

            if (head != tail)
            {
                // ? Move head pointer to next node
                head = head->next;

                // ? Disconnect the front (first) node
                start->next = NULL;
                head->previous = NULL;
            }
            else
                // ? Make both null if there is only single node int his list
                head = tail = NULL;

            // ? Delete the front (first) node
            delete start;
        }
    }

    // * Method - Pop a node from back
    void pop_back()
    {
        if (head != NULL)
        {
            if (head != tail)
            {
                // ? Get head of the list
                Node *node;

                // ? 2nd last node of the list
                node = tail->previous;

                // ? Get address of tail node
                Node *temp = tail;

                // ? Move tail pointer to 2nd last node
                tail = tail->previous;

                // ? Disconnect the back (last) node
                node->next = NULL;
                temp->previous = NULL;

                // ? Delete the back (last) node
                delete temp;
            }
            else
            {
                Node *temp = head;
                head = tail = NULL;
                delete temp;
            }
        }
    }

    // * Method - Print the list
    void print()
    {
        // ? Get the starting node
        Node *start = head;

        // ? Iterate through the list
        while (start != NULL)
        {
            cout << start->value << "<->";
            start = start->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    // ? Create Doubly Linked List Object
    LinkedList list;

    // ? Add some data
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    list.push_back(4);
    list.push_back(5);
    list.push_back(6);

    list.pop_front();
    list.pop_back();

    // ? Print the list
    cout << "Doubly List: ";
    list.print();
}

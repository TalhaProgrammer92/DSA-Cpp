#include <iostream>

using namespace std;

// ? Node that stores a integer value and address of another node
class Node
{
public:
    // * Data of the node
    int value;
    Node *next;

    // * Constructor
    Node(int value) : value(value), next(NULL) {}
};

// ? Linked list to create a list of connected nodes
class LinkedList
{
public:
    // * Main pointers
    Node *head, *tail;

    // * Constructor
    LinkedList() : head(NULL), tail(NULL) {}

    // * Method - Push a node at back
    void push_back(int value)
    {
        // ? Create a new node
        Node *node = new Node(value);

        // ? If the list is empty
        if (head == NULL)
            head = node;

        // ? If the list is not empty
        else
            tail->next = node;

        // ? Finalize
        tail = node;
    }

    // * Method - Print the list
    void print()
    {
        // ? Get the starting node
        Node *start = head;

        // ? Iterate through the list
        while (start != NULL)
        {
            cout << start->value << "->";
            start = start->next;
        }
        cout << "NULL" << endl;
    }
};

// * Function - Reverse in k-group
Node *reverse(Node *head, int k)
{
    // ? Check k nodes' existence
    Node *node = head;
    int count = 1;
    while (count < k)
    {
        if (node == NULL)
            return head;

        count++;
        node = node->next;
    }

    // ? Reverse recursively
}

int main()
{
    // ? Create list
    LinkedList list;

    // ? Add nodes
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    // ? Print the list
    cout << "List: ";
    list.print();

    // ? Reverse
    // list.head = reverse(list.head, 2);
    // cout << "Reversed: ";
    // list.print();
}

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
class DoublyList
{
public:
    // * Main pointers
    Node *head, *tail;

    // * Constructor
    DoublyList() : head(NULL), tail(NULL) {}

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

// * Function - Merge two sorted linked lists
Node *merge(Node *head1, Node *head2)
{
    // ? Base Case if any head becomes NULL
    if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;

    // ? If the value of head 1 <= the value of head 2
    if (head1->value <= head2->value)
    {
        head1->next = merge(head1->next, head2);
        return head1;
    }
    // ? If the value of head 2 < the value of head 1
    else
    {
        head2->next = merge(head1, head2->next);
        return head2;
    }
}

int main()
{
    // * Create two sorted lists
    DoublyList list1, list2;

    // * Adding elements
    list1.push_back(1);
    list1.push_back(3);
    list1.push_back(5);

    list2.push_back(2);
    list2.push_back(3);
    list2.push_back(6);

    // * Print them
    cout << "List 1:\t";
    list1.print();
    cout << "List 2:\t";
    list2.print();

    // * Merge them
    merge(list1.head, list2.head);
    cout << "Merged:\t"; list1.print();
}

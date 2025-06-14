#include <iostream>

using namespace std;

// ? Node
class Node
{
public:
    // * Attributes
    int value;
    Node *next, *previous, *child;

    // * Constructor
    Node(int value) : value(value), next(NULL), previous(NULL), child(NULL) {}
};

// ? Doubly Linked List
class DoublyList
{
public:
    // * Attributes
    Node *head, *tail;

    // * Constructor
    DoublyList() : head(NULL), tail(NULL) {}

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

    // * Method - Create child
    void creat_child(int index, Node *head /* Head of other doubly list */)
    {
        // ? Necessary data
        int i = 0;
        Node *node = this->head;

        // ? Find the required index
        while (node != NULL)
        {
            // ? Index found
            if (i == index)
                break;

            // ? Go to next node and increment i (index)
            node = node->next;
            i++;
        }

        // ? Required index not found
        if (i != index)
            return;

        // ? Create child
        node->child = head;
    }

    // * Method - Print the list
    void print()
    {
        // ? Get the starting node
        Node *start = head;

        // ? Iterate through the list
        while (start != NULL)
        {
            cout << start->value;

            // ? If current node has a child
            if (start->child != NULL)
                cout << " (child " << start->child->value << ")";

            cout << " <-> ";
            start = start->next;
        }
        cout << "NULL" << endl;
    }
};

// * Function - Flatten a multi-level doubly linked list
Node *flatten_list(Node *head)
{
    // ? Create a node which start from head
    Node *node = head;

    // ? Traverse the list
    while (node != NULL)
    {
        // ? If a child exists
        if (node->child != NULL)
        {
            // ? Preserve next node of current node
            Node *next = node->next;

            // ? Flatten the child node and create valid connections
            node->next = flatten_list(node->child);
            node->next->previous = node;
            node->child = NULL;

            // ? Link with preserved next node
            if (next != NULL)
            {
                // ? Find the tail of the flattened list
                while (node->next != NULL)
                    node = node->next;

                // ? Link that tail with next node
                node->next = next;
                next->previous = node;
            }
        }

        // ? Move to next node
        node = node->next;
    }

    // ? Return head of current list
    return head;
}

int main()
{
    // ? Create lists for multi-level doubly list
    DoublyList list1, list2, list3, flatten;

    // ? Inserting data
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(4);
    list1.push_back(5);

    list2.push_back(6);
    list2.push_back(7);
    list2.push_back(8);

    list3.push_back(9);
    list3.push_back(10);

    // ? Create links (child)
    list2.creat_child(1, list3.head);
    list1.creat_child(2, list2.head);

    // ? Print lists
    cout << "List 1: ";
    list1.print();

    cout << "List 2: ";
    list2.print();

    cout << "List 3: ";
    list3.print();

    // ? Flatten
    flatten.head = flatten_list(list1.head);
    cout << "Flatten: ";
    flatten.print();
}

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
    int size;

public:
    // * Constructor
    LinkedList() : head(NULL), tail(NULL), size(0) {}

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

        size++;
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
        size++;
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

            size--;
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
            size--;
        }
    }

    // * Getter - size
    int get_size()
    {
        return size;
    }

    // * Method - Get a node at particular index
    Node *getAt(const unsigned int &index)
    {
        if (index <= size)
        {
            Node *node = head;

            for (int i = 0; i <= index; i++)
                node = node->next;

            return node;
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

// * Function - Swap two nodes
void swap(Node *node1, Node *node2)
{
    // ? Store neibour conenctions
    Node *temp1 = node1->previous, *temp2 = node2->next;

    // ? reconnect node2
    temp1->next = node2;
    node2->previous = temp1;
    node2->next = node1;

    // ? reconnect node1
    node1->next = temp2;
    node2->previous = node2;
}

// * Function - Bubble sort
void sort(LinkedList &list)
{
    for (int i = 0; i < list.get_size() - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < list.get_size() - i - 1; j++)
        {
            Node *a = list.getAt(j), *b = a->next;

            if (a->value > b->value)
            {
                swapped = true;
                swap(a, b);
            }
        }

        if (!swapped) break;
    }
}

int main()
{
    LinkedList list;

    list.push_back(2);
    list.push_back(5);
    list.push_back(1);
    list.push_back(4);
    list.push_back(3);

    list.print();
    sort(list);
    list.print();
}

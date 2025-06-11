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
private:
    // * Main pointers
    Node *head, *tail;

public:
    // * Constructor
    LinkedList() : head(NULL), tail(NULL) {}

    // * Method - Push a node at front
    void push_front(int value)
    {
        // ? Create a new node
        Node *node = new Node(value);

        // ? If the list is empty
        if (head == NULL)
            tail = node;

        // ? If the list is not empty
        else
            node->next = head;

        // ? Finalize
        head = node;
    }

    // * Method - Calculate size of the linked list
    int size()
    {
        int count = 0;

        Node *start = head;

        while (start != NULL)
        {
            start = start->next;
            count++;
        }

        return count;
    }

    // * Method - Get a node at particular index
    Node *at(int index)
    {
        if (head != NULL)
        {
            Node *start = head;

            for (int i = 0; i < index; i++)
                start = start->next;

            return start;
        }
        throw out_of_range("The given index is out of range!");
    }

    // * Method - Middle node of the list
    Node *middle_brute_force()
    {
        if (head != NULL)
        {
            // ? Get necessary values
            Node *start = head;
            int mid = size() / 2;

            // ? Return the middle node
            return at(mid);
        }

        return NULL;
    }

    Node *middle_slow_fast()
    {
        if (head != NULL)
        {
            // ? Get two pointers
            Node *slow = head, *fast = head;

            // ? Treverse the list
            while (fast != NULL && fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow;
        }

        return NULL;
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

int main()
{
    // * Create object
    LinkedList list;

    // * Add values
    list.push_front(6);
    list.push_front(5);
    list.push_front(4);
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    // * Print
    cout << "List: "; list.print();

    // * Find middle
    cout << "Middle Node: " << list.middle_brute_force()->value << endl;
    cout << "Middle Node: " << list.middle_slow_fast()->value << endl;
}

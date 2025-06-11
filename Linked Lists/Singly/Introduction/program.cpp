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
        // Node node(value);   // ! It'll be deleted from memory on function exit (Static)
        Node *node = new Node(value); // ! It'll remain in memomry after function exit (Dynamic)

        // ? If the list is empty
        if (head == NULL)
            tail = node;

        // ? If the list is not empty
        else
            node->next = head;

        // ? Finalize
        head = node;
    }

    // * Method - Insert at index of the list
    void insert(int value, int index)
    {
        // ? If list is not empty
        if (head != NULL)
        {
            int size = this->size();

            // ? If given index is starting index
            if (index == 0)
                push_front(value);

            // ? If given index is last index
            else if (index == size - 1)
                push_back(value);

            // ? If given index lie between start and end indices
            else if (index > 0 && index < size)
            {
                // ? Create a new node
                Node *node = new Node(value);

                // ? Get node at given index
                Node *prev = at(index - 1), *next = prev->next;

                // ? Establish connections (Prev -> Node -> Next)
                node->next = next;  // ! Node -> Next
                prev->next = node;  // ! Prev -> Node
            }

            // ? If given index is out of range
            else
                throw out_of_range("The given index is out of range!");
        }
    }

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

    // * Method - Pop a node from front
    void pop_front()
    {
        if (head != NULL)
        {
            // ? Get address of head node
            Node *start = head;

            // ? Move head pointer to next node
            head = head->next;

            // ? Disconnect the front (first) node
            start->next = NULL;

            // ? Delete the front (first) node
            delete start;
        }
    }

    // * Method - Pop a node from back
    void pop_back()
    {
        if (head != NULL)
        {
            // ? Get head of the list
            Node *node = head;

            // ? Find the 2nd last node of the list
            while (node->next != tail)
                node = node->next;

            // ? Get address of tail node
            Node *temp = tail;

            // ? Move tail pointer to 2nd last node
            tail = node;

            // ? Disconnect the back (last) node
            node->next = NULL;

            // ? Delete the back (last) node
            delete temp;
        }
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

    // * Method - Search for a value
    int index(int value)
    {
        // ? Get head node
        Node *start = head;
        int index = 0;

        // ? Search for given value
        while (start != NULL)
        {
            // ? If found the given value
            if (start->value == value)
                return index;

            start = start->next;
            index++;
        }
        
        return -1;
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
    // * Linked list object
    LinkedList list;

    // * Pushing values at front
    list.push_front(1);
    list.push_front(2);

    // * Pushing values at back
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    // * Delete from front
    list.pop_front();

    // * Delete from back
    list.pop_back();

    // * Insert a value at an index
    list.insert(2, 1);

    // * Print the list
    list.print();

    // * Print the element of the list at an index
    const int index = 2;
    cout << "Value at Node#" + to_string(index + 1) << ": " << list.at(index)->value << endl;

    // * Print a value's index located in the list
    const int value = 2;
    cout << "Value " + to_string(value) + " is located at index: " << list.index(value) << endl;

    // * Display size of the list
    cout << "Size: " << list.size() << endl;
}

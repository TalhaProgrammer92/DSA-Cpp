#include <iostream>
#include <unordered_map>

using namespace std;

// ? Node that stores a integer value and address of another node
class Node
{
public:
    // * Data of the node
    int value;
    Node *next, *random;

    // * Constructor
    Node(int value) : value(value), next(NULL), random(NULL) {}
};

// ? Linked list to create a list of connected nodes
class DoublyList
{
public:
    // * Main pointers
    Node *head, *tail;

    // * Constructor
    DoublyList() : head(NULL), tail(NULL) {}

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

    // * Method - Create a random link
    void random_link(int index1, int index2)
    {
        at(index1)->random = at(index2);
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

    // * Method - Print random links
    void print_random()
    {
        // ? Get the starting node
        Node *start = head;

        // ? Iterate through the list
        while (start != NULL)
        {
            if (start->random != NULL)
                cout << start->value << "->" << start->random->value << endl;
            else
                cout << start->value << "->" << "NULL" << endl;
            start = start->next;
        }
    }
};

Node *deep_copy(Node *head)
{
    // ? Necessary pointers
    Node *old_node = head->next, *new_head, *new_node, *new_temp;
    unordered_map<Node*, Node*> map;

    // ? Set head of new list
    new_head = new Node(head->value);
    new_temp = new_head;

    // ? Add both address's map
    map[head] = new_temp;

    // ? Copying values
    while (old_node != NULL)
    {
        // ? Create new node with old node's value
        Node *new_node = new Node(old_node->value);
        
        // ? Link it with new (temp) node's next
        new_temp->next = new_node;

        // ? Add both address's map
        
        // ? Update both old and new node's pointers
        new_temp = new_temp->next;  // ! Update new (temp) node
        map[old_node] = new_temp;   // ! Create map for old and new temp nodes' addresses
        old_node = old_node->next;  // ! Update old node
    }

    // ? Traverse again to form random connections
    old_node = head;
    new_temp = new_head;
    while (old_node != NULL)
    {
        // ? Get the corresponding node and copy random link
        new_temp->random = map[old_node->random];

        // ? Update both old and new node
        old_node = old_node->next;  // ! Update old node
        new_temp = new_temp->next;  // ! Update new (temp) node
    }

    return new_head;
}

int main()
{
    // ? Create list
    DoublyList list, copy;

    // ? Add numbers
    list.push_back(7);
    list.push_back(13);
    list.push_back(11);
    list.push_back(10);
    list.push_back(1);

    // ? Print the list
    cout << "\n=== Original ===\n" << endl;
    cout << "List: ";
    list.print();

    // ? Create random links
    list.random_link(1, 0);
    list.random_link(2, 4);
    list.random_link(3, 2);
    list.random_link(4, 0);

    // ? Print Random Links
    cout << "\nRandom Links:" << endl;
    list.print_random();

    // ? Copy the list
    copy.head = deep_copy(list.head);

    // ? Print the copy list
    cout << "\n=== Copy ===\n" << endl;
    
    cout << "List: ";
    copy.print();

    cout << "\nRandom Links:" << endl;
    copy.print_random();
}

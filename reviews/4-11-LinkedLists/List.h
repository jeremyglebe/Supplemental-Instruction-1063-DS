#include <iostream>

class List
{

  public:
    class Node
    {
      public:
        int data;
        Node *next;
        Node(int d, Node *n = NULL)
        {
            data = d;
            next = n;
        }
    };

    Node *head = NULL;

    void insert(int value)
    {
        // Check if the item should be inserted at the head
        // OR: if ((*head).data > value)
        if (!head || head->data > value)
        {
            // New node that points to head
            Node *n = new Node(value, head);
            head = n;
        }
        else
        {
            Node *low = head;
            // Find the node that we should insert after
            while (low->next != NULL && low->next->data < value)
            {
                low = low->next;
            }
            Node *high = low->next;
            Node *n = new Node(value, high);
            low->next = n;
        }
    }

    void remove(int value)
    {
        Node *low = head;
        // Find the node that we should insert after
        while (low->next != NULL && low->next->data != value)
        {
            low = low->next;
        }
        if (low->next != NULL)
        {
            Node *high = low->next->next;
            delete low->next;
            low->next = high;
        }
        else
        {
            std::cout << "Value " << value << " is not in the list!\n";
        }
    }

    bool search(int value)
    {
        Node *tmp = head;
        // Find the node that we should insert after
        while (tmp != NULL && tmp->data != value){
            tmp = tmp->next;
        }
        if (tmp != NULL){
            return true;
        }
        return false;
    }

    void print()
    {
        Node *tmp = head;
        while (tmp != NULL)
        {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << '\n';
    }
};
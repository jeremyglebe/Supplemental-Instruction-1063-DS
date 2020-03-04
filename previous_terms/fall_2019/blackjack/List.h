#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
    ListNode *prev;
    ListNode(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class List
{
public:
    List()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void FrontSert(int x)
    {
        ListNode *temp = new ListNode(x);
        if (head)
        {
            head->prev = temp;
            temp->next = head;
            head = temp;
        }
        else
        {
            head = temp;
            tail = temp;
        }
        size++;
    }
    void EndSert(int x)
    {
        ListNode *temp = new ListNode(x);
        if (tail)
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        else
        {
            head = temp;
            tail = temp;
        }
        size++;
    }
    int FrontDel()
    {
        int val = head->data;
        ListNode *temp = head;
        head = head->next;
        if (head)
            head->prev = NULL;
        delete temp;
        size--;
        return val;
    }
    int EndDel()
    {
        int val = tail->data;
        ListNode *temp = tail;
        tail = tail->prev;
        if (tail)
            tail->next = NULL;
        delete temp;
        size--;
        return val;
    }
    void print()
    {
        ListNode *temp = head;
        cout << temp->data;
        temp = temp->next;
        while (temp)
        {
            cout << " <-> " << temp->data;
            temp = temp->next;
        };
        cout << '\n';
    }
    ListNode *head;
    ListNode *tail;
    int size;
};
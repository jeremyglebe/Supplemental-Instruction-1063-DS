#include <iostream>
using namespace std;

struct Node
{
    int d;
    Node *n;
    Node *p;
    Node(int d, Node *n = NULL, Node *p = NULL)
    {
        this->d = d;
        this->n = n;
        this->p = p;
    }
};

class List
{
private:
    Node *front;
    Node *back;
    Node *center;
    int count;
    int mpos;
    // push to empty
    void _pushe(int n)
    {
        front = new Node(n);
        back = center = front;
        mpos = 1;
        count = 1;
    }
    void _track_mid()
    {
        // true middle position
        int tpos = count / 2 + 1;
        // compare the current mpos to tpos
        if (mpos < tpos)
        {
            // if its less, we need to send the middle pointer to the right
            int adj = tpos - mpos; // number of steps to the right
            for (int i = 0; i < adj; i++)
            {
                center = center->n;
                mpos++;
            }
        }
        else if (mpos > tpos)
        {
            // if its more, we need to send the middle pointer to the left
            int adj = mpos - tpos; // number of steps to the left
            for (int i = 0; i < adj; i++)
            {
                center = center->p;
                mpos--;
            }
        }
    }

public:
    List()
    {
        front = back = center = NULL;
        mpos = 0;
        count = 0;
    }
    // push to the front
    void pushf(int n)
    {
        if (!front)
        {
            // inserting to empty
            _pushe(n);
        }
        else
        {
            // insertion logic
            front->p = new Node(n, front, NULL);
            front = front->p;
            count++;
            // adjust the middle
            // any time you push to the front, the middle position
            // increases by 1 before you make any other changes
            mpos++;
            _track_mid();
        }
    }
    // push to the back
    void pushb(int n)
    {
        if (!front)
        {
            // inserting to empty
            _pushe(n);
        }
        else
        {
            // insertion logic
            back->n = new Node(n, NULL, back);
            back = back->n;
            count++;
            // adjust the middle
            _track_mid();
        }
    }
    void print()
    {
        // traverse and print the list
        Node *temp = front;
        while (temp)
        {
            cout << temp->d << ' ';
            temp = temp->n;
        }
        cout << '\n';
        // print the values of our pointers
        cout << "Front: " << front->d << '\n';
        cout << "Center: " << center->d << '\n';
        cout << "Back: " << back->d << '\n';
    }
};

int main()
{
    List l;
    srand(42);
    // Everything below here is just to get a fairly randomized test case
    // you don't need to worry about it
    for (int i = 0; i < 15; i++)
    {
        int back = rand() % 2;
        if (back)
        {
            cout << "pushb()\n";
            l.pushb(rand() % 100);
        }
        else
        {
            cout << "pushf()\n";
            l.pushf(rand() % 100);
        }
        l.print();
        cout << endl;
    }
    return 0;
}
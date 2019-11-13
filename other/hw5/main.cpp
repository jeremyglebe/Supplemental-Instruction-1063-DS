/**
 * Solving the students' homework 5 just so I know how to help them on it.
 * Obviously I won't be uploading this until after they've turned it in.
 * 
 * Assignment was to fix the class written by the professor. There was 
 * something wrong with a loop in the "ReOrder" method. It was not terminating
 * and was not producing a correctly ordered list.
 * 
 * I also made it use random data just for the fun.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

struct Node
{
    string word;
    Node *Next;
    Node(string w)
    {
        word = w;
        Next = NULL;
    }
};

class Dictionary
{
private:
    Node *Start;

    string LowerCase(string input)
    {
        for (int i = 0; i < input.length(); i++)
        {
            if ((int)input[i] < 96)
            {
                input[i] += 32;
            }
        }
        return input;
    }

public:
    Dictionary()
    {
        Start = NULL;
    }

    void Add(string word)
    {

        word = LowerCase(word);
        // create new memory
        Node *temp = new Node(word);

        // if list is empty hook in new Node
        if (Start == NULL)
        {
            Start = temp;
        }
        else
        {
            // get ready to walk the list
            Node *traverse = Start;
            while (traverse->Next != NULL)
            {
                // walks the list
                traverse = traverse->Next;
            }
            // now at proper place to link in new memory
            traverse->Next = temp;
        }
    }

    string Remove(string key)
    {
        string temp = "";

        if (!Start)
        {
            return "";
        }
        else
        {
            Node *cptr = Start;
            Node *prev = Start;
            while (cptr && cptr->word != key)
            {
                prev = cptr;
                cptr = cptr->Next;
            }
            // if cptr then we found the word
            if (cptr)
            {
                temp = cptr->word;
                prev->Next = cptr->Next;
                delete cptr;
            }
            else
            {
                // no word, return empty
                temp = "";
            }
            return temp;
        }

        return temp;
    }

    void ReOrder()
    {
        // pointers for new list
        Node *NewList = NULL;
        Node *Tail = NULL;

        int i = 0;

        while (Start != NULL)
        {

            // helper pointers to manipulate lists
            Node *Ptr = Start;
            Node *Min = Start;
            Node *Prev = Start;
            Node *MinPrev = Start;

            // find one minimum word in old list
            while (Ptr != NULL)
            {
                if (Ptr->word < Min->word)
                {
                    MinPrev = Prev;
                    Min = Ptr;
                }

                Prev = Ptr;
                Ptr = Ptr->Next;
            }
            //end finding one word in old list

            // add one word to new list

            if (!NewList)
            {
                NewList = Min;
            }
            else
            {
                Tail->Next = Min;
            }

            Tail = Min;
            /**
             * THIS BREAKS IF THE SECOND ELEMENT OF THE OLD LIST IS REMOVED TO BE
             * ADDED TO THE NEW LIST
             * 
             * EXAMPLE)
             * Start -> 5 -> 4 -> 6 ->     (3 elements in start list with middle item taken out)
             * NewList -> 1 -> 2 -> 3 ->
             * 
             * becomes
             * 
             * Newlist -> 1 -> 2 -> 3 -> 4 ->
             *                            ^
             *                            |
             *                          Start
             * 
             * 
             * Fix by changing
             * MinPrev == Start
             * to
             * Min == Start
             * 
             */
            // if (MinPrev == Start)
            if (Min == Start)
            {
                Start = Start->Next;
            }
            else
            {
                MinPrev->Next = Min->Next;
            }

            Min->Next = NULL;
            i++;

            // DEBUGGING: PRINT THE CURRENT MIN AT THIS STAGE
            // cout << "i: " << i << "  Min: " << Min->word << endl;
        }

        Start = NewList;
    }

    void Print()
    {
        Node *temp = Start;
        while (temp)
        {
            cout << temp->word;
            if (temp->Next)
            {
                cout << "-> ";
            }
            temp = temp->Next;
        }
        cout << endl;
    }
};
/////////////////////////////////////////////////////

int main()
{
    Dictionary W;
    ifstream fin("clean_animals.txt");

    // Generate fun random data
    // seed our rng
    srand(time(NULL));
    // we need to know how many animals are in the file
    int num_animals;
    fin >> num_animals;
    // create an array of animals names and populate form the file
    string *rand_animals = new string[num_animals];
    for (int i = 0; i < num_animals; i++)
    {
        fin >> rand_animals[i];
    }
    fin.close();
    // add 6 random animals from the array to our "Dictionary"
    for (int i = 0; i < 6; i++)
    {
        W.Add(rand_animals[rand() % num_animals]);
    }

    // Test the reorder method and print the lists before and after
    cout << "Original List: ";
    W.Print();
    W.ReOrder();
    cout << " Ordered List: ";
    W.Print();

    return 0;
}

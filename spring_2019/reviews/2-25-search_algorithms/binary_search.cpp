#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int SIZE = 100;

void bsearch(int[], int);
void printArr(int[]);

int main()
{
    // Declare an array that we will search. Here I use odd numbers
    // It will be sorted because of the way we declare it (small to large)
    int odd[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        odd[i] = 2 * i + 1;
    }

    // Print it for a reference so we know what can be found
    cout << "[[[ARRAY DATA]]]\n";
    printArr(odd);

    // Print results for searching for various keys
    cout << "\n\n[[[BINARY SEARCH RESULTS]]]\n";
    // Search for a number near the beginning
    bsearch(odd, 7);
    // Search for a number near the end
    bsearch(odd, 193);
    // Search for the first number
    bsearch(odd, 1);
    // Search for the last number
    bsearch(odd, 199);
    // Search for a number that is not there
    bsearch(odd, 40);
    // Search for a number that outside the bounds on the high end
    bsearch(odd, SIZE * 10);
    // Search for a number that outside the bounds on the low end
    bsearch(odd, SIZE * -1);

    return 0;
}

// Function to perform a linear search
// WE ASSUME THAT array IS SORTED
void bsearch(int array[], int key)
{
    // Has the key been found yet?
    bool found = false;
    // Number of steps until key is found
    int steps = 0;
    // Index the key is found at
    int index = -1;

    // To start the search we need to keep track of our endpoints (left and right)
    int l = 0;
    int r = SIZE - 1;
    // Keep track of the middle value to compare to key
    int m;

    // We keep cutting the array in half until left and right meet
    while (l <= r && !found)
    {

        // Keep track of the middle value to compare to key
        m = (l + r) / 2;

        // If the key is LESS than the number in the center we cut out the right half
        if (key < array[m])
        {
            // Set the right bound to the middle to cut out the right half
            r = m - 1;
        }

        // If the key is GREATER than the number in the center we cut out the left half
        else if (key > array[m])
        {
            // Set the left bound to the middle to cut out the left half
            l = m + 1;
        }

        // If its equal, we found it
        else
        {
            found = true;
            index = m;
        }

        steps++;

    }

    // If the key was found, lets print the results
    cout << left;
    if (found)
    {
        cout << "Key " << setw(6) << key << " was found at index " << setw(6) << index << " after " << setw(6) << steps << " steps.\n";
    }
    else
    {
        cout << "Key " << setw(6) << key << " was not found" << string(13, ' ') << "after " << setw(6) << steps << " steps.\n";
    }
}

// Function to print the values of a large array in a nice format
void printArr(int array[])
{
    for (int i = 0; i < SIZE; i += 5)
    {
        for (int j = i; j < i + 5 && j < SIZE; j++)
        {
            cout << setw(5) << array[j];
        }
        cout << '\n';
    }
}
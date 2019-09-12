#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int SIZE = 4096;

string lsearch(int[], int);
string bsearch(int[], int);
void printArr(int[]);

int main()
{
    // Declare an array that we will search. Here I use odd numbers
    int odd[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        odd[i] = 2 * i + 1;
    }

    // Print it for a reference so we know what can be found
    cout << "[[[ARRAY DATA]]]\n";
    printArr(odd);

    // Print results for searching for various keys
    cout << "\n\n[[[SEARCH RESULTS]]]\n";
    // Search for a number near the beginning
    cout << left << setw(10) << "[113]"
         << "Linear: " << setw(20) << lsearch(odd, 113)
         << " Binary: " << bsearch(odd, 113) << '\n';
    // Search for a number near the end
    cout << left << setw(10) << "[3867]"
         << "Linear: " << setw(20) << lsearch(odd, 3867)
         << " Binary: " << bsearch(odd, 3867) << '\n';
    // Search for the first number
    cout << left << setw(10) << "[1]"
         << "Linear: " << setw(20) << lsearch(odd, 1)
         << " Binary: " << bsearch(odd, 1) << '\n';
    // Search for the last number
    cout << left << setw(10) << "[4095]"
         << "Linear: " << setw(20) << lsearch(odd, 4095)
         << " Binary: " << bsearch(odd, 4095) << '\n';
    // Search for a number that is not there
    cout << left << setw(10) << "[986]"
         << "Linear: " << setw(20) << lsearch(odd, 986)
         << " Binary: " << bsearch(odd, 986) << '\n';
    // Search for a number that outside the bounds on the high end
    cout << left << setw(10) << "[" + to_string(SIZE * 10) + "]"
         << "Linear: " << setw(20) << lsearch(odd, SIZE * 10)
         << " Binary: " << bsearch(odd, SIZE * 10) << '\n';
    // Search for a number that outside the bounds on the low end
    cout << left << setw(10) << "[" + to_string(SIZE * -1) + "]"
         << "Linear: " << setw(20) << lsearch(odd, SIZE * -1)
         << " Binary: " << bsearch(odd, SIZE * -1) << '\n';

    return 0;
}

// Function to perform a linear search
string lsearch(int array[], int key)
{
    // Has the key been found yet?
    bool found = false;
    // Number of steps until key is found
    int steps = 0;
    // Index the key is found at
    int index = -1;

    // Loop through the array
    for (int i = 0; i < SIZE && !found; i++, steps++)
    {
        if (array[i] == key)
        {
            found = true;
            index = i;
        }
    }

    // If the key was found, lets print the results
    if (found)
    {
        return to_string(steps);
    }
    else
    {
        return "NOT_FOUND_" + to_string(steps);
    }
}

// Function to perform a linear search
// WE ASSUME THAT array IS SORTED
string bsearch(int array[], int key)
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
    if (found)
    {
        return to_string(steps);
    }
    else
    {
        return "NOT_FOUND_" + to_string(steps);
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
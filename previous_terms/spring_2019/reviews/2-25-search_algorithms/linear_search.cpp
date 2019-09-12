#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

const int SIZE = 100;

void lsearch(int[], int);
void printArr(int[]);

int main(){
    // Declare an array that we will search. Here I use odd numbers
    int odd[SIZE];
    for(int i = 0; i < SIZE; i++){
        odd[i] = 2*i + 1;
    }

    // Print it for a reference so we know what can be found
    cout << "[[[ARRAY DATA]]]\n";
    printArr(odd);

    // Print results for searching for various keys
    cout << "\n\n[[[LINEAR SEARCH RESULTS]]]\n";
    // Search for a number near the beginning
    lsearch(odd, 7);
    // Search for a number near the end
    lsearch(odd, 193);
    // Search for the first number
    lsearch(odd, 1);
    // Search for the last number
    lsearch(odd, 199);
    // Search for a number that is not there
    lsearch(odd, 40);
    // Search for a number that outside the bounds on the high end
    lsearch(odd, SIZE * 10);
    // Search for a number that outside the bounds on the low end
    lsearch(odd, SIZE * -1);
    
    return 0;
}

// Function to perform a linear search
void lsearch(int array[], int key){
    // Has the key been found yet?
    bool found = false;
    // Number of steps until key is found
    int steps = 0;
    // Index the key is found at
    int index = -1;

    // Loop through the array
    for(int i = 0; i < SIZE && !found; i++, steps++){
        if(array[i] == key){
            found = true;
            index = i;
        }
    }

    // If the key was found, lets print the results
    cout << left;
    if(found){
        cout << "Key " << setw(6) <<  key << " was found at index " << setw(6) << index << " after " << setw(6) << steps << " steps.\n";
    }else{
        cout << "Key " << setw(6) << key << " was not found"  << string(13, ' ') << "after " << setw(6) << steps << " steps.\n";
    }

}

// Function to print the values of a large array in a nice format
void printArr(int array[]){
    for(int i = 0; i < SIZE; i += 5){
        for(int j = i; j < i + 5 && j < SIZE; j++){
            cout << setw(5) << array[j];
        }
        cout << '\n';
    }
}
#include "session_header.h"
#include "arrays.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "quick_sort.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    session_header();

	int SIZE = 0;
	cout << "What size arrays to sort? ";
	cin >> SIZE;
    // Array
    int* arr = new int[SIZE];
    // Bubble sort
    populate_random(arr, SIZE);
    bubble_sort(arr, SIZE);
    // Insertion sort
    populate_random(arr, SIZE);
    insertion_sort(arr, SIZE);
    // Quick sort
    populate_random(arr, SIZE);
    quick_sort(arr, SIZE);

}
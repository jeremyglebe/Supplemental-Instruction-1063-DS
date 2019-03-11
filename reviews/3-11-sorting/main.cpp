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

    // Array of 5000
    int* arr = new int[5000];
    // Bubble sort
    populate_random(arr, 5000);
    bubble_sort(arr, 5000);
    // Insertion sort
    populate_random(arr, 5000);
    insertion_sort(arr, 5000);
    // Quick sort
    populate_random(arr, 5000);
    quick_sort(arr, 5000);

}
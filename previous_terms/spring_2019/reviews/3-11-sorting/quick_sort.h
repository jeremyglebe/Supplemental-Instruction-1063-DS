#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;
// Back-end functions' prototypes
void _quicksort(int[], int, int);
int _partition(int[], int, int);

/* quick_sort
 * Front facing function that performs a quick sort - this is what you would
 * call from your code. Sorts an array of integers large->small.
 * Input:
 *     arr, an array of integers
 *     size, the size of the array
 */
void quick_sort(int arr[], int size)
{
    /****MEASURING EXECUTION TIME****/
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    /********************************/
    _quicksort(arr, 0, size - 1);
    /****MEASURING EXECUTION TIME****/
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2 - t1).count() * .001;
    cout << "Quick sort completed\n"
         << "\t- Execution time: " << duration << "ms\n";
    /********************************/
}
/* _quicksort
 * This is the recursive code that actually runs the quick sort
 * algorithm. It will call itself in an appropriate manner.
 * Inputs:
 *     arr, an array of integers
 *     top, the index of the top element (for this call)
 *     bottom, the index of the bottom element (for this call)
 */
void _quicksort(int arr[], int top, int bottom)
{
    int middle;
    if (top < bottom)
    {
        // determine where to split the array
        middle = _partition(arr, top, bottom);
        // sort first section
        _quicksort(arr, top, middle);
        // sort second section
        _quicksort(arr, middle + 1, bottom);
    }
    return;
}
/* _partition
 * Function to determine the partitions (where to split the arrays)
 * partitions the array and returns the middle subscript
 * Inputs:
 *     arr, an array of integers
 *     top, the index of the top element (for this call)
 *     bottom, the index of the bottom element (for this call)
 */
int _partition(int arr[], int top, int bottom)
{
    int x = arr[top];
    int i = top - 1;
    int j = bottom + 1;
    int temp;
    do
    {
        do
        {
            j--;
        } while (x > arr[j]);

        do
        {
            i++;
        } while (x < arr[i]);

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    return j;
}

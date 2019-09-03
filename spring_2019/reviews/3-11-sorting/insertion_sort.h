#include <chrono>
using namespace std::chrono;

void insertion_sort(int arr[], int size)
{
    /****MEASURING EXECUTION TIME****/
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    /********************************/
    int i, j, key;
    for (j = 1; j < size; j++)
    {
        key = arr[j];
        for (i = j - 1; (i >= 0) && (arr[i] < key); i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[i + 1] = key;
    }
    /****MEASURING EXECUTION TIME****/
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2 - t1).count() * .001;
    cout << "Insertion sort completed\n"
         << "\t- Execution time: " << duration << "ms\n";
    /********************************/
    return;
}
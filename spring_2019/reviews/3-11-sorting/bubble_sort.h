#include<chrono>
using namespace std::chrono;

void bubble_sort(int arr[], int size)
{
    /****MEASURING EXECUTION TIME****/
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    /********************************/
    int i, j, flag = 1;
    int temp;
    for (i = 1; (i <= size) && flag; i++)
    {
        flag = 0;
        for (j = 0; j < (size - 1); j++)
        {
            if (arr[j + 1] > arr[j])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
    }
    /****MEASURING EXECUTION TIME****/
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2 - t1).count() * .001;
    cout << "Bubble sort completed\n"
         << "\t- Execution time: " << duration << "ms\n";
    /********************************/
    return;
}
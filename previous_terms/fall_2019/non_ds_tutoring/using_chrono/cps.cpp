#include <iostream>
#include <chrono>
using namespace std;

int main()
{
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < 1000000; i++)
    {
        continue;
    }
    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    // nanoseconds -> seconds by dividing by 1 billion
    long double seconds = duration.count() / (long double)(1000000000);
    long double comps_per_sec = 1 / seconds;
    if (comps_per_sec >= 1000)
    {
        cout << "Made 1 million comparisons in " << seconds << " seconds\n";
        cout << comps_per_sec / 1000
             << " billion comparisons per second!" << endl;
    }
    else if (seconds > 0)
    {
        cout << "Made 1 million comparisons in " << seconds << " seconds\n";
        cout << comps_per_sec << " million comparisons per second!" << endl;
    }
    else
    {
        cout << "Made 1 million comparisons in " << seconds << " seconds\n";
        cout << "Number of seconds was too small!\n";
        cout << "Can't calculate comparisons per second.\n";
        cout << "It is in the billions! (at least)" << endl;
    }
}
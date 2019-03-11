#pragma once
#include<iostream>
using namespace std;

void session_header(){
    cout << "\033[31;47m"
        << "╔══════════════════════════════════════╗\n"
        << "║   Topics To Cover (Review 3/11/19)   ║\n"
        << "╚══════════════════════════════════════╝\n"
        << "\033[0;32m"
        << "\t- Bubble Sort\n"
        << "\t- Insertion Sort\n"
        << "\t- Quick Sort\n"
        << "\t- Execution Time\n"
        << "\t- Big-O\n\n";
    return;
}
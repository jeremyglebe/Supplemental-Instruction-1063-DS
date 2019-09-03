#pragma once
#include<iostream>
#include<cstdlib>
using namespace std;

void populate_random(int arr[], int size){
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 1000;
    }
}

void print_array(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}
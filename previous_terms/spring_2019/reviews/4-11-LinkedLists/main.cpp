#include<iostream>
#include"List.h"
using namespace std;

int main(){
    List l;
    l.insert(14);
    l.print();
    l.insert(37);
    l.print();
    l.insert(3);
    l.print();
    l.insert(7);
    l.print();
    l.remove(7);
    l.print();
    l.remove(99999);
    l.print();
    cout << l.search(14) << '\n';
    cout << l.search(140) << '\n';
}
#include <iostream>
#include "BigNum.h"
using namespace std;

int main() {
    BigNum myNum("9849841654849866451654615424242");
    cout << "BigNum was constructed.\n";
    cout << myNum.ToString();

    cout << "\nTesting adding nums.\n";
    BigNum num1("192");
    BigNum num2("52");
    BigNum num3 = num2.Add(num1);
    cout << num3.ToString() << endl;
    num3 = num1.Add(num1);
    cout << num3.ToString() << endl;
}
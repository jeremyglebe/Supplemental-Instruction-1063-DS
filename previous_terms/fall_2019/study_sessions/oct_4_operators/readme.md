# Overloading Operators
We are demonstrating in the session how to overload an operator in C++.
Specifically, we are making a class called a "Band" which represents a group
of musicians. Every band has a name, logo, and vector of members. We should be
able to print the band using the "<<" operator (from main, not from inside the
class). We should be able to add members from one band into another using the
"+" operator (from main). "<<" will work with cout or with ofstreams (files)
because we are overloading the operator with "ostreams" which both of those
count as.
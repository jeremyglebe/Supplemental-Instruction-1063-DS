#include"Band.h"

Band::Band(){
    num = 0;
    band_name = "";
    logo = ' ';
    members = std::vector<std::string>();
}

Band::Band(std::string name, char l){
    num = 0;
    band_name = name;
    logo = l;
    members = std::vector<std::string>();
}

void Band::add_member(std::string member_name){
    members.push_back(member_name);
    num++;
}

/** Returns a clone of the first band with the members of the other band added
 * to it.
 * @param other the Band being added (the b2 in "b3 = b1 + b2")
 * @return Band, the Band containing the new members (the b3 in "b3 = b1 + b2")
 */
Band Band::operator+(Band other){
    Band result = *this;
    for(int i = 0; i < other.num; i++){
        result.num++;
        result.members.push_back(other.members[i]);
    }
    return result;
}

/**
 * Overloaded Stream Insertion Operator
 * This function is not a method of the class because when overloading
 * operators as methods, the class is automatically the first parameter. And in
 * the case of the "<<" operator, we need the stream object to be the first
 * parameter. This is not usually an issue. (that's why our "+" operator above
 * IS a method of the class) Since it can't be a method of the class, we have
 * made it a "friend". Friends have access to private data members, just like
 * the class's methods.
 * @param out the output stream that you want to print to (cout, ofstream, etc)
 * @param b the Band you want to print out
 * @return ostream&, returning the ostream you pass in allows for stringing
 * together outputs like so: cout << Card << 5 << "hello" << endl;
 */
std::ostream &operator<<(std::ostream & out, Band b){
    out << b.band_name << '\n' << b.logo << '!' << '\n';
    out << b.num << " members:\n";
    for (int i = 0; i < b.num; i++){
        out << b.members[i] << '\n';
    }
    return out;
}
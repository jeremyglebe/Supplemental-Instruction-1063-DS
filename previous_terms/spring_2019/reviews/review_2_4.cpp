/*
 * DESCRIPTION:
 * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * You're hosting a party. You've mailed out the invites
 * and are processing the reponses via a program. This
 * program will tell you how many people will be there,
 * so that you can purchase enough food. You sent out 25
 * invitations but at the moment have only received 5
 * responses. Make sure this program is flexible and
 * could be easily adjusted when more responses come in.
 *
 * INSTRUCTIONS:
 * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Type a header with your name in it
 * COMMENT EVERYTHING AS YOU GO
 * Add necessary includes (iostream, etc...)
 * Create a global constant (or precompiler directive
 *     if you prefer) MAX_INVITES with value 25
 * Declare a struct Response containing:
 *     - name
 *     - attending (boolean)
 *     - number of guests
 * Use a type definition for an array of Response,
 *     call it GuestList. (Students who have learned
 *     about vectors in class may use them)
 * Create a function called getResponse that returns
 *     Response from the keyboard
 * Create a function totalAttendees. Takes an
 *     array of Response and returns the total
 *     number of attendees, including guests
 * In main, make use of these functions by doing the
 * following:
 *     - Get 5 Response items
 *     - Get the number of attendees
 *     - Display the number of attendees
 *
 * AFTER YOU'RE FINISHED:
 * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Demo your program to the SI
 * If you want to keep the program, make sure to upload
 *  it somewhere you can access on another computer.
 * Sign your name on the appropriate roll sheet.
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// constant
const int MAX_INVITES = 25;

struct Response{
    string name;
    bool attending;
    int guests;
};
typedef Response GuestList[MAX_INVITES];
// We can do the same thing with vectors
typedef vector<Response> Guests;

void header();
Response getResponse();
//Using arrays
int totalAttendees(GuestList, int);
//Using vectors instead
int totalAttendees(Guests);

int main(){
    header();
    GuestList list;
    for(int i = 0; i < 2; i++){
        //Get the responses.
        list[i] = getResponse();
    }
    cout << "\n\nThe total number of attendees is "
        << totalAttendees(list, 2) << endl;

    //And with vectors
    /*
    Guests gVector;
    for(int i = 0; i < 3; i++){
        gVector.push_back(getResponse());
    }
    */

    return 0;
}

Response getResponse(){
    Response r;
    cout << "Enter Your Name: ";
    cin >> r.name;
    char input;
    cout << "Are you coming to the event? [Y/N] ";
    cin >> input;
    if (input == 'Y'){
        r.attending = true;
    }else{
        r.attending = false;
    }
    cout << "How many guests are you bringing? ";
    cin >> r.guests;
    return r;
}

int totalAttendees(GuestList list, int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        if(list[i].attending){
            sum += list[i].guests + 1;
        }
    }
    return sum;
}

int totalAttendees(Guests guest_vector){
    int sum = 0;
    for(int i = 0; i < guest_vector.size(); i++){
        if(guest_vector[i].attending){
            sum += guest_vector[i].guests + 1;
        }
    }
    return sum;
}

void header(){
    cout << "\033[31;47m"
        << "╔══════════════════════════════════════╗\n"
        << "║   Topics To Cover (Review 2/04/19)   ║\n"
        << "╚══════════════════════════════════════╝\n"
        << "\033[0;32m"
        << "\t*Programming lab*\n"
        << "\t- Structs\n"
        << "\t- Arrays of Structs\n"
        << "\t- Vectors of Structs\n\n";
    return;
}
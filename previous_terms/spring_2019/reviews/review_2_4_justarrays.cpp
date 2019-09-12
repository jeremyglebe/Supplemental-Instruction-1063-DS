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
using namespace std;

// constant to set the size of the array
const int MAX_INVITES = 25;

struct Response{
    string name;
    bool attending;
    int guests;
};
typedef Response GuestList[MAX_INVITES];

Response getResponse();
int totalAttendees(GuestList, int);

int main(){
	// List of Reponses
    GuestList list;
	
	// Get the number of responses from the user
	int num_responses;
	cout << "How many responses do you want to enter? ";
	cin >> num_responses;
	
	// Get all the responses and put them into the list
    for(int i = 0; i < num_responses; i++){
        //Get the responses.
        list[i] = getResponse();
    }
	
	// Calculate and print the total # of attendees
    cout << "\n\nThe total number of attendees is "
        << totalAttendees(list, num_responses) << endl;

    return 0;
}

Response getResponse(){
	// Create a Response object "r" to send back
    Response r;
	
	// Get a name to put in the response
    cout << "Enter Your Name: ";
    cin >> r.name;
	
	// Get a confirmation if they're going
    char input;
    cout << "Are you coming to the event? [Y/N] ";
    cin >> input;
	// Interpret the character and assign a value to the attending boolean
    if (input == 'Y'){
        r.attending = true;
    }else{
        r.attending = false;
    }
    
	// Get the number of guests the invited person is bringing
	cout << "How many guests are you bringing? ";
    cin >> r.guests;
	
	// Send back the Response object
    return r;
}

int totalAttendees(GuestList list, int size){
	// Start the total at 0
    int sum = 0;
	
	// Loop through every Response in the array (GuestList list)
    for(int i = 0; i < size; i++){
		
		//If attending, add the person invited and their guests to the total
        if(list[i].attending){
            sum += list[i].guests + 1;
        }
    }
	
	// Send back the total attendees
    return sum;
}

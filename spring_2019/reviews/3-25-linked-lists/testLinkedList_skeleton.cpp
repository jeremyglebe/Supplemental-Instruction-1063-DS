/*
  The purpose of this code is to test the
  NumberList class you have implemented.
*/

#include"NumberList.h"
#include<iostream>
#include<fstream>

using namespace std;

int main(){
  ifstream infile;
  infile.open("spooky.dat");
  // variable to hold values read from spooky.dat
  double num;
  // 3 separate lists
  NumberList listA, listB, listC;
  // Put values in listA by inserting nodes at front
  for (double x = 1.5; x <= 14; x += 1)
    // -------Write a statement here that 
    // will insert x at the front of listA
   

  // ---------Write a statement here to display listA
  


  // Put values in listB by inserting nodes at end
  for (double y = 2.7; y < 100; y += 5)
    // -----------Write a statement here that will 
    // insert y at the end of listB
   

  // -------------Write a statement here to display listB
 


  // ---------Write a statement to remove the node at the front of listA
  // Hint:  That node has the value 13.5
  


  // --------------Write a statement to display listA and verify that 
  // 13.5 is no longer in the list.

  

  // --------------Write a statement to remove the node at the end of listA
  // Hint:  That node has the value 1.5

  

 
  // -----------------Write a statement to display listA and verify that 
  // 1.5 is no longer in the list.

  


  // ----------Write a statement to remove 5.5 from listA
  

  //----------Write a statment to display listA and verify that 5.5 is gone.
 

  // --------Write a statement to attempt to remove 8.4 from listA
  // That value is not in the list.  Your program should not crash!!!

  //----------Write a statment to display listA and verify that it didn't change.


  // Now do the same things for listB
  // Remove the node at the front, the node at the end
  // and a node in the middle.  Display the list
  // after each remove.
  // 6 statements total

  // Now use the insertInOrder function
  // to read values from a file and insert
  // them into listC.
  if (infile){
    while (infile >> num)
      //------Write a statement to insert num into listC
      // using the insertInOrder function
      

    // ------Write a statement to display listC
    // and verify that the values were inserted in order.
    

  }
  else
    cout << "Couldn't open the input file.\n";

  system("pause");
  return 0;

}
#include "NumberList.h"
#include<iostream>
using namespace std;
NumberList::NumberList()
{
  head = NULL;
}


NumberList::~NumberList()
{
  ListNode* p = head;
  while (p != NULL){
    head = p->next;
    delete p;
    p = head;
  }
  head = NULL;
}

void NumberList::insertAtFront(double num){
  head = new ListNode(num, head);
}

void NumberList::insertAtEnd(double num){
  ListNode* p = head;
  if (p == NULL){
    head = new ListNode(num);
  }
  else{
    while (p->next != NULL)
      p = p->next;
    p->next = new ListNode(num);
  }
}

void NumberList::remove(double num){
  ListNode* p, *prev;
  p = head;
  prev = p;
  //First node is the one to be removed
  if (p->value == num){
    head = p->next;
    delete p;
  }
  else{
    while (p != NULL && p->value != num){
      prev = p;
      p = p->next;
    }
    //p is now pointing to Node to remove
    // or p is NULL
    if (p != NULL){
      prev->next = p->next;
      delete p;
    }
  }

}

void NumberList::displayList(){
  ListNode* p = head;
  while (p != NULL){
    cout << p->value << endl;
    p = p->next;
  }
  cout << "******************" << endl;
}

/*
  This function will insert a node into a list
  The nodes will be inserted so that the values
  in the list remain in ascending order.

  You will finish this function

*/
void NumberList::insertInOrder(double num){
  // You can use the function written on page
  // 1034

}


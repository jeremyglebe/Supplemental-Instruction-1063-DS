#pragma once
#include<iostream>
class NumberList
{
protected:
  struct ListNode{
    double value;
    ListNode* next;
    ListNode(double num, ListNode* p = NULL)
    {
      value = num;
      next = p;
    }
  };
private:
  ListNode* head;
public:
  NumberList();
  ~NumberList();
  void insertAtFront(double num);
  void insertAtEnd(double num);
  void insertInOrder(double num);
  void remove(double num);
  void displayList();
};


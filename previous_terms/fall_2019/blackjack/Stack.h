#include<iostream>
using namespace std;

struct StackNode{
    int data;
    StackNode* next;
    StackNode(int d){
        data = d;
        next = NULL;
    }
};

class Stack
{
public:
    Stack(){
        top = NULL;
        size = 0;
    }
    void push(int x){
        StackNode* temp = new StackNode(x);
        temp->next = top;
        top = temp;
        size++;
    }
    int pop(){
        int top_value = -1;
        if(size > 0){
            StackNode* temp = top;
            top_value = top->data;
            top = top->next;
            size--;
            delete temp;
        }
        return top_value;
    }
    void print(){
        StackNode* temp = top;
        cout << " Stack\n-------\n";
        while(temp){
            cout << temp->data << '\n';
            temp = temp->next;
        }
        cout << '\n';
    }
private:
    StackNode *top;
    int size;
};
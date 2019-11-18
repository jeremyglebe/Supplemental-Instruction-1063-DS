#include <string>
using namespace std;

struct Node{
    int digit;
    Node* prev;
    Node* next;
    Node(){
        digit = 0;
        prev = NULL;
        next = NULL;
    }
    Node(int d){
        digit = d;
        prev = NULL;
        next = NULL;
    }
};

/**
 * Basic idea for the layout of main()
 * 
 * - Read in strings X and Y from the file
 * 
 * - Read an operation OP from the file
 * 
 * - Create two BigNums using the strings X and Y.
 * 
 * - Perform OP on X and Y resulting in a BigNum Z.
 *     ex) Z = X.Add(Y)
 * 
 * - Get a string S from Z and print it to a file.
 *     ex) S = Z.ToString()
 * 
 * 
 * Example algorithm for operation (Add, Subtract, Multiply)
 * 
 * - Assuming we are inside BigNum X and passed in BigNum Y:
 *     Make a copy of X (called xx)
 *       Ex) xx.Copy(X)
 *     Make a copy of Y (called yy)
 *       Ex) yy.Copy(Y)
 * 
 * - This will prevent us from destroying the original lists.
 * 
 * - Perform the actual operation on the two copies, creating a
 *   new BigNum called zz.
 * 
 * - Return the zz to main.
 */

/**
 * A BigNum is just a doubly-linked list with some math operations. Each Node
 * should represent a single digit of some large number.
 */
class BigNum {
public:
    /**
     * Create a BigNum with an empty list. No value yet.
     */
    BigNum(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    /**
     * Create a BigNum from a string. Each digit will be stored in a Node.
     */
    BigNum(string big_number){
        head = NULL;
        tail = NULL;
        size = 0;
        for(int i = 0; i < big_number.size(); i++){
            char c_digit = big_number[i];
            int digit = c_digit - '0';
            EndSert(digit);
        }
    }
    /**
     * Add some other BigNum to this BigNum and return the
     * result (as a BigNum). The original two BigNums should be unaffected.
     */
    BigNum Add(BigNum other){
        BigNum thisNum;
        thisNum.Copy(*this);
        BigNum otherNum;
        otherNum.Copy(other);
        BigNum result;

        while(thisNum.size > 0 || otherNum.size >0) {
            if(thisNum.tail && otherNum.tail){
                int dig = thisNum.tail->digit + otherNum.tail->digit;
                result.FrontSert(dig);
                thisNum.EndDel();
                otherNum.EndDel();
            }else{
                if(thisNum.size < otherNum.size){
                    int dig = otherNum.tail->digit;
                    result.FrontSert(dig);
                    otherNum.EndDel();
                }else{
                    int dig = thisNum.tail->digit;
                    result.FrontSert(dig);
                    thisNum.EndDel();
                }
            }
        }
        return result;
    }
    /**
     * Subtract some other BigNum from this BigNum and return the
     * result (as a BigNum). The original two BigNums should be unaffected.
     */
    BigNum Sub(BigNum other);
    /**
     * Multiply some other BigNum with this BigNum and return the
     * result (as a BigNum). The original two BigNums should be unaffected.
     */
    BigNum Mul(BigNum other);
    /**
     * Traverse list and add the number from each Node to a string. Return
     * that string.
     */
    string ToString(){
        string result = "";
        Node* temp = head;
        while(temp){
            int digit = temp->digit;
            char c_digit = digit + '0';
            result += c_digit;
            temp = temp->next;
        }
        return result;
    }
private:
    Node* head;
    Node* tail;
    int size;
    // Insert a Node at the front of the list
    void FrontSert(int digit){
        Node* temp = new Node(digit);
        if(head){
            head->prev = temp;
            temp->next = head;
            head = temp;
        }else{
            head = temp;
            tail = temp;
        }
        size++;
    }
    // Insert a Node at the end of the list
    void EndSert(int digit){
        Node* temp = new Node(digit);
        if(tail){
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }else{
            head = temp;
            tail = temp;
        }
        size++;
    }
    // Delete a Node from the front of the list
    void FrontDel();
    // Delete a Node from the end of the list
    void EndDel(){
        Node* temp = tail;
        tail = tail->prev;
        if(tail)
            tail->next = NULL;
        delete temp;
        size--;
    }
    /**
     * Copy all the values from one BigNum X into another BigNum Y.
     * We will use these in our math operations so we don't
     * destroy the originals.
     * 
     * Advice:
     * Just traverse list X and for each of its Nodes create a new Node
     * in Y with the same data.
     * 
     * Example Usage:
     * BigNum X('12345');
     * BigNum Y();
     * Y.Copy(X);
     * 
     * Y is now an exact copy of X, but you can modify Y
     * without affecting X. 
     */
    void Copy(BigNum other){
        // We have access to other's head even though its private because
        // other is a BigNum and Copy is a method of BigNum
        Node* temp = other.head;
        while(temp){
            EndSert(temp->digit);
            temp = temp->next;
        }
    }
};
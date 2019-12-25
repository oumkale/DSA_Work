#include <iostream>
using namespace std;
template <typename T>
class Node
{
  public:
   T data;
   Node<T> *next;
   Node(T data)
   {
     this -> data = data;
     next = NULL;  
   }
};
template <typename T>
class Stack
{
   Node<T> *head;
   int size;
   
   public:
   Stack()
   {
      head = NULL;
      size = 0;
   }
   
   int getSize()
   {
     return size;
   }
   void push(T element)
   {
       Node<T> *temp;
      if(head == NULL)
      {
        temp = new Node<T>(element);
        head = temp;        
      }
      else
      {
        temp  = new Node<T>(element);
        temp ->next = head;
        head = temp;
      }
      size++;
      
   }
   T pop()
   {
     if(head == NULL)
      return 0;// return head;
     else
     {
      Node<T> *temp = head;
      head = head -> next;
      T te = temp -> data;
      delete temp;
      size--;
      return te;
     }  
   }
   bool isEmpty()
   {
      if(size == 0)
        return true;
      else
        return false ;
   }
   T top()
   {
      return head->data;
   }
};
int main() 
{
        Stack<int> st;
        
        int choice,ch;
            
        do{
        
        cout<<"1 Push"<<endl;
        cout<<"2 Pop"<<endl;
        cout<<"3 Top"<<endl;
        cout<<"4 Size"<<endl;
        cout<<"5 Is Empty"<<endl;
        cout<<"Enter choice for operation."<<endl;
        cin >> choice;
        int input;
        
        if (choice !=-1)
         {
            if(choice == 1) {
                cin >> input;
                st.push(input);
                
            }
            else if(choice == 2) {
                int ans = st.pop();
                if(ans != 0) {
                    cout <<"Element-> Pop :"<< ans << endl;
                }
                else {
                    cout << "Empty Stack" << endl;
                }
            }
            else if(choice == 3) {
                int ans = st.top();
                if(ans != 0) {
                    cout << "Top Element : "<<ans << endl;
                }
                else {
                    cout << "Empty" << endl;
                }
            }
            else if(choice == 4) {
                cout <<"Size od stack : "<< st.getSize() << endl;
            }
            else if(choice == 5) {
                cout <<"Is Empty ?"<< st.isEmpty() << endl;
            }
          }
        }while(ch!=-1);
} 
/*





/*******
 Following Node class and main already created internally. You can directly use that.
 
#include<iostream>
using namespace std;


template <typename T>
class Node {
    public :
    T data;
    Node<T> *next;
    
    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};

#include "Stack.h"
    int main() {
        
        Stack<int> st;
        
        int choice;
        cin >> choice;
        int input;
        
        while (choice !=-1) {
            if(choice == 1) {
                cin >> input;
                st.push(input);
            }
            else if(choice == 2) {
                int ans = st.pop();
                if(ans != 0) {
                    cout << ans << endl;
                }
                else {
                    cout << "-1" << endl;
                }
            }
            else if(choice == 3) {
                int ans = st.top();
                if(ans != 0) {
                    cout << ans << endl;
                }
                else {
                    cout << "-1" << endl;
                }
            }
            else if(choice == 4) {
                cout << st.getSize() << endl;
            }
            else if(choice == 5) {
                cout << st.isEmpty() << endl;
            }
            cin >> choice;
        }
    
    } 
**********

template <typename T>
class Stack {
    Node<T> *head;
    int size;		// number of elements prsent in stack
    
    public :
    
    Stack() {
        
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        
    }
    
    void push(T element) {
        
    }
    
    T pop() {
        // Return 0 if stack is empty. Don't display any other message
        
    }
    
    T top() {
        // Return 0 if stack is empty. Don't display any other message
        
    }
    
  
    
};


*/



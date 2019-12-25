#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node * next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
   void print(Node * head)
   {
    Node *temp=head;
    
    while(temp != NULL)
    {
       cout<<temp->data<<" ";
       temp = temp->next;
    }
    cout<<endl;
   }
};
Node * createList()
{
  cout<<"Please follow instructions"<<endl;
  int data;
  Node * head = NULL;
  Node * temp = NULL;
  cout<<"Enter Data (-1 for exit)"<<endl;
  cin>>data;
  while(data!=-1)
  {
     Node * node = new Node(data);
     if(head == NULL)
     {
       head = node;
       temp = node;
     }
     else
     {
      temp -> next = node;
      temp = temp -> next;
     }
    cin>>data;
  } 
  return head;
}
Node *reverse_linked_list_rec(Node *head)
{
    //write your recursive code here
  if(head == NULL || head->next==NULL)
     return head;
  Node * newHead = reverse_linked_list_rec(head->next);
  Node *temp = newHead;
  while(temp->next!=NULL)
  {
     temp = temp -> next;
  }   
     temp -> next = head;
     head -> next = NULL;
  return newHead;
}
int main()
{
      Node *head = createList();
      Node *poi = new Node(0);
      poi->print(head);
      Node *headreverse = reverse_linked_list_rec(head);
      poi->print(headreverse);
      delete poi;
}

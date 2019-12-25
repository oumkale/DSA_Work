#include <iostream>
using namespace std;
class Node
{
   public:
   int data;
   Node * next=NULL;

   Node(int data)
    {
       this -> data = data;
       this -> next = NULL;    
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
Node * iterativelyInsert(Node *head, int i)
{
    int data;
    cout<<"Enter data"<<endl;
    cin>>data;
    Node *node = new Node(data);
     int count = 0;
     Node *temp = head;
       if(i == count)
        {
           if(head == NULL)
           {
             head = node;
           }
           else
           {
              node -> next = temp;
              temp = node;
              head = temp;
              return head;
           }
        }
          while(temp!=NULL && count < i-1)
          {
              temp = temp-> next;
              count++;
          }
          if(temp!=NULL)
          {
            node -> next = temp -> next;
            temp -> next = node;
          }
          return head;
}
Node * recursivelyInsert(Node *head,int data,int i)
{
    if(head == NULL)
    {
       if(i == 0)
       {    
         Node *node = new Node(data);
         head = node;
         return head;
       }  
       else
       {
         
         return head;
       }
    }
    if(i==0)
    {
        Node *node = new Node(data);
        node -> next = head;
        head = node;
        return head;
    }
   
       head -> next =  recursivelyInsert(head->next,data,i-1);
    
    return head;
}
Node * iterativelyDelete(Node * head, int i)
{
  if(head == NULL)
    return head;
  Node *temp = head;
  Node *prev = head;
  int count = 0;
  if(i == count)
  {
    head = head -> next;
    delete temp;
    return head;
  }  
  while(temp!= NULL && count <= i-1)
    {
      prev= temp;
      temp = temp -> next;
      count++;
    }
    if(temp!=NULL )
    {
     prev -> next = temp -> next;
        delete temp;
       
    }
 
   return head;
}
Node *recursivelyDelete(Node *head,int i)
{
   if(head == NULL)
     return head;
   if(i == 0)
   {
     Node * temp = head;
     temp = temp ->next;
     return temp;
   }  
   head -> next = recursivelyDelete(head->next,i-1);
}
int main()
{
   cout<<"Single Link List"<<endl;
   int choice;
   Node * head = NULL;
   do{
     cout<<"0.Create Link List."<<endl;
     cout<<"1.Insert Node at i position"<<endl;
     cout<<"2.Delete Node from i posotion"<<endl;
     cout<<"3.Print List"<<endl;
     cout<<"4.Delete Node from i position"<<endl;
    /* cout<<<<endl;
     cout<<<<endl;
     cout<<<<endl;
  */ cout<<"Enter choice"<<endl; 
     cin>>choice;
     switch(choice)
     {
       case 0:
             head = createList();
             break;
       case 1:
              cout<<"Enter position"<<endl;
              int pos;
              cin>>pos;
             cout<<"1 for Iteratively and 2 for Recursively"<<endl;
             int ch;
             cin>>ch;
             switch(ch)
             {
               case 1: head = iterativelyInsert(head,pos);
               break;
               case 2:
                cout<<"Enter data to be ensert."<<endl;
                int data;
                cin>>data;
                head= recursivelyInsert(head,data,pos);
                       
               break;
               default: cout<<"Enter correct choice for node insertion."<<endl;
               break;
             }
             break;
       case 2:
             cout<<"1 for Iteratively and 2 for Recursively"<<endl;
         
             cin>>ch;
             cout<<"Enter position"<<endl;
               pos;
              cin>>pos;
             switch(ch)
             {
               case 1: head = iterativelyDelete(head,pos);
               break;
               case 2:
                head= recursivelyDelete(head,pos);
               break;
               default: cout<<"Enter correct choice for node insertion."<<endl;
               break;
             }
             break;    
       case 3:
               Node *poi = new Node(0);
               poi->print(head);
               delete poi;
             break;  
       /*default:
          cout<<"Hey man, please type corect choice!"<<endl;
          break; */                 
     }
   }while(choice != 9);
   
   return 0;
}

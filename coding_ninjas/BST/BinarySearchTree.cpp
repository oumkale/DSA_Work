#include <iostream>
#include <climits>
#include <queue>
#include <stack>
#include <utility> 
#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
 
 template <typename T>
 class Node{
    public:
    T data;
    Node<T> *next;
    
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
 };
BinaryTreeNode<int> * takeInput()
{
     
     cout << " Enter Data " << endl;
     int data;
     cin>>data;
     if( data == -1 )
      return NULL;
      
     BinaryTreeNode<int> * root = new BinaryTreeNode<int>(data);
     BinaryTreeNode<int> * left = takeInput();
     BinaryTreeNode<int> * right= takeInput();
     root -> right = right;
     root -> left  = left; 
   return root;
}
void printTree(BinaryTreeNode<int> *root)
{
   if(root == NULL)
   return ;
   cout << root -> data << " : ";
   if(root->left )
     cout<< " L " << root -> left -> data << " ";
   if(root -> right)
     cout<< " R " << root -> right -> data << " ";
     cout<<endl;
   printTree(root->left);
   printTree(root->right);
         
}
BinaryTreeNode<int>* takeInputUsingQueue()
{
   cout<<"Enter Root Data"<<endl;
   int da;
   cin>>da;
   if(da == -1)
     return NULL;
     
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(da);
    queue<BinaryTreeNode<int>*> pendingChilds;
    pendingChilds.push(root);
    //cout<< pendingChilds.front() -> data<<endl;;
    while(pendingChilds.size() != 0)
    {
          BinaryTreeNode<int>* front = pendingChilds.front();
          pendingChilds.pop();
          cout<< "Enter data for Left Node of "<<front->data<<endl;
          int daLeft;
          cin>>daLeft;
          if(daLeft != -1)
          { 
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(daLeft);
               front -> left = leftChild;
               pendingChilds.push(leftChild);
          }  
          cout<< "Enter data for Right Node of "<<front->data<<endl;
          int daRight;
          cin>>daRight;
          if(daRight != -1)
          {  
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(daRight);
               front -> right = rightChild;
               pendingChilds.push(rightChild);
          }
            
    }
    cout<<"Data ->"<<root->data<<endl;
    return root;
}
int numberofNodes(BinaryTreeNode<int>* root)
{
    if(root == 0)
      return 0;
  return 1 + numberofNodes(root->left) + numberofNodes(root->right);
}
bool isNodePresent(BinaryTreeNode<int>* root, int x) {
    
    bool flag = false;
    
     if(root==NULL)
         return false;
     if(root -> data == x)
         return true;
     
     flag = isNodePresent(root->left,x);
     if(flag == false)
     flag = isNodePresent(root->right,x);
    return flag;

}
BinaryTreeNode<int>* mirrorBinaryTree(BinaryTreeNode<int>* root) {
    // Write your code here
    if(root == NULL)
        return NULL;
    if(root->left==NULL && root->right==NULL)
         return NULL;
    queue<BinaryTreeNode<int>*> queuenodes;
    queuenodes.push(root);
    while(queuenodes.size() != 0)
    {
        BinaryTreeNode<int> * front = queuenodes.front();
        queuenodes.pop();
        
        BinaryTreeNode<int> * temp;
       
         temp = front->right;
          front->right = front -> left;
          front->left = temp;
        
          if(front ->right)
            queuenodes.push(front->right);
           if(front->left)
             queuenodes.push(front->left);
        
    }
    return root;
}
BinaryTreeNode<int>* mirrorBinaryTreeR(BinaryTreeNode<int>* root)
{
  if(root==NULL)
    return NULL;
  if(root->left==NULL&&root->right==NULL)  
    return NULL;
   mirrorBinaryTreeR(root -> left);
   mirrorBinaryTreeR(root -> right);
   BinaryTreeNode<int>* templeft=root->left;
     root -> left = root->right;
     root->right=templeft;
  return root;   
}
void preOrder(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
      return ;
    }
    
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);  
}
void postOrder(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
      return ;
    }
    postOrder(root->left);
    postOrder(root->right);  
      cout<<root->data<<" ";
  
}
void inOrder(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
      return ;
    }
    
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);  
}
BinaryTreeNode<int>* create(int *a, int lpres,int lpree,int *b,int lins,int line)
{ 
    if(lpres > lpree || lins > line)
        return NULL;
     int val = a[lpres];
    int k=0;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(val);
    
    for(int i=lins;i<=line;i++)
    {
        if(val == b[i])
        {
            k = i;
            break;
        }
    }
    root -> left = create(a,lpres+1,lpres+(k-lins),b,lins,k-1);
    root -> right= create(a,lpres+k-lins+1,lpree,b,k+1,line);
   
    return root;
}
BinaryTreeNode<int>* createTreeIP(int *preorder, int preLength, int *inorder, int inLength)
 {
   
    int Lins =0;
    int Lpres =0;
    int Line = inLength-1;
    int Lpree = preLength-1;
     
    BinaryTreeNode<int>* root = create(preorder,Lpres,Lpree,inorder,Lins,Line);
    return root;
}
BinaryTreeNode<int>* createPostIn(int *a, int postS, int postE, int *b, int inS, int inE)
{
    if(inS > inE )
       return NULL; 
     int val = a[postS];
    int k=0,LinS,LinE,RinS,RinE,RpostS,RpostE,LpostS,LpostE;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(val);
    for(int i=inS;i<=inE;i++)
    {
        if(val == b[i])
        {
             k = i;
            break;
        }
    }
    LinS = inS;
    LinE = k-1;
    RinS = k+1;
    RinE = inE;
    RpostS = postS-1;
    RpostE = postS-1 - (inE-(k+1));
    LpostS = RpostE-1;
    LpostE = postE;
    
   root -> left = createPostIn(a,LpostS,LpostE,b,LinS,LinE);
   root -> right = createPostIn(a,RpostS,RpostE,b,RinS,RinE); 
    
    return root;
}
BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    int inS,inE,postS,postE;
     inS=0;
     inE= inLength-1;
     postS = inLength-1;
     postE = 0;
         
      BinaryTreeNode<int>* root = createPostIn(postorder,postS,postE,inorder,inS,inE);
    return root;
}
int height(BinaryTreeNode<int> * root)
{
   if(root == NULL)
     return 0;
   return 1 + max(height(root->right), height(root->left));  
}
// Normal Calculation of Diameter
int diameter(BinaryTreeNode<int> * root)
{
  if(root == NULL)
    return 0;
  int opt1 = height(root->left) + height(root->right);
  int opt2 = diameter(root->left);
  int opt3 = diameter(root->right);
  return max(opt1,max(opt2,opt3));
}
// pair is a inbuilt template which has two members first & second.
pair<int,int> heightDiameter(BinaryTreeNode<int>* root)
{
      
      if(root == NULL)
      {
         pair<int,int> pa;
         pa.first = 0;
         pa.second = 0;
         return pa;
      }  
     
     pair<int,int> leftAns = heightDiameter(root -> left);
     pair<int,int> rightAns = heightDiameter(root -> right);
     int leftDia = leftAns.second;
     int leftHeight = leftAns.first;
     int rightDia = rightAns.second;
     int rightHeight = rightAns.first;
     int height = 1 + max(leftHeight, rightHeight);
     int diameter = max((leftHeight+rightHeight),max(leftDia,rightDia));
     pair<int,int> p;
     p.first = height;
     p.second = diameter; 
     return p; 
}

 // PairAns class -
class PairAns {
    public :
        int min;
        int max;
 };
// #include<climits>
PairAns minMax1(BinaryTreeNode<int> *root)
{

  PairAns p;
    p.min=INT_MAX;
    p.max=INT_MIN;
   if(root==NULL)
    return p;
    PairAns leftPair=minMax1(root->left);
	PairAns rightPair=minMax1(root->right);
	p.max=max(max(leftPair.max,rightPair.max),root->data);
	p.min=min(min(leftPair.min,rightPair.min),root->data);
	return p;
}
PairAns minMax(BinaryTreeNode<int> *root) {
    

    if(root == NULL)
    {
        PairAns p;
        p.min = 0;
        p.max = 0;
        return p;
    }
    int val = root -> data;
    
    PairAns left = minMax(root->left);
    PairAns right = minMax(root->right);  
    if(right.min == 0)
        right.min = root->data;
    if(right.max == 0)
        right.max = root->data;
    if(right.min > root->data)
        right.min = root->data;
    if(right.max < root->data)
        right.max = root->data;
     // left
      
    if(left.min == 0)
        left.min = root->data;
    if(left.max == 0)
        left.max = root->data;
    if(left.min > root->data)
        left.min = root->data;
    if(left.max < root->data)
        left.max = root->data;
    
    //----
    PairAns p;
    if(left.min < right.min)
        p.min = left.min;
    else
       p.min = right.min; 
    if(left.max > right.max)
        p.max = left.max;
    else
       p.max = right.max; 
    return p;
}
int sumOfAllNodes(BinaryTreeNode<int>* root) {
    int sum=0,sum1,sum2;
    if(root == NULL)
        return 0;
    int val = root -> data;
    sum1 = sumOfAllNodes(root -> right);
    sum2 = sumOfAllNodes(root -> left);
    return sum1 + sum2 + val;
}
////////////////////////// Balance 
pair<int, int> balance(BinaryTreeNode<int>* root)
{
   if(root == NULL)
   {
      pair<int, int> p;
       p.first = 0;
       p.second = 1;
      return p;
   }
    int pp=0;
     pair<int, int> p1 = balance(root -> right);
     pair<int, int> p2 =  balance(root -> left);
     pair<int, int> p;
    if(p1.second == 0 || p2.second == 0 || abs(p1.first - p2.first) > 1)
    {  
         pp = 0; 
       // return p;
    }
    else
    {   
          pp= 1;
    }
     int h = 1 + max(p1.first,p2.first);
     p.first = h;
     p.second = pp;
    return p;
}
bool isBalanced(BinaryTreeNode<int> *root) {
    // Write your code here
   if(root == NULL)
       return false;
    pair<int,int> p = balance(root);
    return p.second;
    /*if(p.second==1)
        return false;
    else
        return true;
   */
}
void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
    
      if(root == NULL)
          return ;
    
    
    if(root -> data >= k1 && root -> data <=k2)
    {
         
        if(root -> data > k1)
           elementsInRangeK1K2(root->left,k1,k2);
          cout << root -> data << " ";
        if(root -> data < k2)
           elementsInRangeK1K2(root->right,k1,k2);
    }
    if(root -> data < k1)
        elementsInRangeK1K2(root->right,k1,k2);
    else if(root -> data > k2)
        elementsInRangeK1K2(root -> left,k1,k2);    
 
}

BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int> *root , int k){
   
    BinaryTreeNode<int>* temp;
    if(root == NULL)
         return root;
       if(root -> data == k)
         return root;
       else if(root -> data < k)
            temp = searchInBST(root->right,k);
       else
           temp = searchInBST(root->left,k);
             
}
bool isbst(BinaryTreeNode<int> * root, int a,int b)
{
    if(root == NULL)
        return true;
    if(root->data < a || root->data > b)
        return false;
   bool c =  isbst(root->left, a ,root->data);
   bool d = isbst(root->right, root->data, b);
    return c & d;
}
bool isBST(BinaryTreeNode<int> *root){
    
    return isbst(root, INT_MIN,INT_MAX);
}
// 1st way of cheking BST 
int minimum(BinaryTreeNode<int> * root)
{
  if(root == NULL)
    return INT_MAX;
    
   return min(root->data , min(minimum(root->left) , minimum(root->right))); 
}
int maximum(BinaryTreeNode<int> * root)
{
  if(root == NULL)
    return INT_MIN;
    
   return max(root->data , max(maximum(root->left) , maximum(root->right))); 
}
bool isBSTree(BinaryTreeNode<int> * root)
{
    if(root == NULL)
      return true;
    int minn = minimum(root-> right);
    int maxx = maximum(root -> left);
    
    return (root -> data < minn && root -> data > maxx && isBSTree(root->right) && isBSTree(root->left));  
}
// Using class pair isBST2
class isBSTclass
{
   public:
   
   int maximum;
   int minimum;
   bool isBST;
};
isBSTclass isBST2(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
      isBSTclass isBSTpair;
      isBSTpair.maximum = INT_MIN;
      isBSTpair.minimum = INT_MAX;
      isBSTpair.isBST = true; 
      return isBSTpair; 
    }
    
    isBSTclass leftoutput = isBST2(root -> left);
    isBSTclass rightoutput = isBST2(root -> right);
    int minn = min(root->data,min(leftoutput.minimum,rightoutput.minimum));
    int maxx = max(root->data, max(leftoutput.maximum,rightoutput.maximum));
    bool isbstoutput = (root -> data < rightoutput.minimum && root -> data > leftoutput.maximum && leftoutput.isBST && rightoutput.isBST);
    
    isBSTclass output;
    output.minimum = minn;
    output.maximum = maxx;
    output.isBST = isbstoutput;
    return output;
}
//   Construct BST from sorted array
BinaryTreeNode<int>* construct(int *input, int s,int e) 
{
    int c,m;
    if(s>e)
        return NULL;
    m = (s+e) / 2;
    BinaryTreeNode<int> * temp = new BinaryTreeNode<int>(input[m]);
    temp -> left = construct(input,s,m-1);
    temp ->right = construct(input,m+1,e);    
    return temp; 
}
BinaryTreeNode<int>* constructTree(int *input, int n) 
{    
     BinaryTreeNode<int>* root = construct(input,0,n-1);
      return root;
}
////    Construct sorted LL using BST
class helper
{
    public:
    Node<int> *head ,*tail;
};
helper construct(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        helper obj;
        obj.head=NULL;
        obj.tail=NULL;
        return obj;
    }
    helper l,r;
    if(root->left!=NULL)
    l=construct(root->left);
    if(root->right!=NULL)
    r=construct(root->right);
    
    Node<int>* nn = new Node<int>(root->data);
    helper ans;
    if(root->left!=NULL)
    {
         ans.head=l.head;
            l.tail->next = nn;                       //linking left subtree LL with nn
    }
   
    else
        ans.head=nn;
    if(root->right!=NULL)
    {
         ans.tail=r.tail;
        nn->next = r.head;                            // linking nn with right subtree LL
    }
   
    else 
        ans.tail=nn;
    return ans;
}
Node<int>* constructBST_LL(BinaryTreeNode<int>* root) 
{

    helper obj=construct(root);                    
    return obj.head;
}
void printLL(Node<int> * root)
{
   cout << "Link List" << endl;
   while(root)
   {
      cout << root->data << " ";
      root = root -> next;
   }
   cout << endl;
}
int main()
{
    BinaryTreeNode<int> * root ;
    BinaryTreeNode<int> * root1,*root2 ; 
    int ch,num,x,c,l1,l2;
    Node<int> *node;
    int *a = new int[1000];
    int *b = new int[1000];
    pair<int,int> p;
    bool flag=false;
    //int a[1000];
    PairAns pairAns;

    do{
          cout<<endl;
         cout << "********************* Binary Search Tree ****************" << endl;
         cout << "0. Take Input Using Recursively or Create Binary Tree" << endl;
         cout << "1. Take Input Level Wise  #Using Queue" << endl;
         cout << "2. Number of Nodes in Binary Tree" << endl;
         cout << "3. Find Node x in Tree" << endl;
         cout << "4. Mirror of Tree" << endl;
         cout << "5. Traversals of Tree" << endl;
         cout << "6. Print Tree" << endl;
         cout << "7. Create Tree fron InOrder and PreOrder" << endl;
         cout << "8. Create Tree fron InOrder and PostOrder"  << endl;
         cout << "9. Diameter of Binary Tree Better Approach" <<endl;
         cout << "10.Max and Min using Pair class" << endl;
         cout << "11.Sum of all Nodes" << endl;
         cout << "12.Tree is Balanced?" << endl;
         cout << "13.Print elements form range given" <<endl;
         cout << "14.Find a Integer in Tree" << endl;
         cout << "15.Is Tree is BST?"<<endl;
         cout << "16.Construct BST using sorted array" << endl;
         cout << "17.Construct Sorted Link List using BST" << endl;
         cout << "Please select choice : ";
         ch;
        cin >> ch;
        switch(ch)
        {
           case 0: root = takeInput();
           break;
           case 1: root = takeInputUsingQueue();
           break;
           case 2:  num = numberofNodes(root);
                     cout<< "Number of nodes in a Tree :" <<num<<endl;
           break;
           case 3: cout<<"Enter node Data to find ?"<<endl;
                   cin>>x; 
                flag = isNodePresent(root,x);
                 cout<<"Node Exist (1:Yes/0:No) : "<<flag<<endl;
           break;
           case 4:   cout <<" 1 for using queue and 2 for using recursion" <<endl;
                      cin>>c;
                      if(c==1)   
                        root1 = mirrorBinaryTree(root);
                      else
                        root1=mirrorBinaryTreeR(root);
                       printTree(root1);
                      root1 = NULL;  
           
           break;
           case 5:  cout<<"1 . PreOrder, 2 . PostOrder, 3 . Inorder"<<endl;
              cin>>c;
              cout<<"Tree is,  "<<endl;
              if(c==1)
                  postOrder(root);
              else if(c==2)
                 preOrder(root);
              else  
                 inOrder(root);
                 cout<<endl;
           break;
           
           
           case 6: printTree(root);
           break;
           case 7: 
           cout << "Enter length PreOrder and InOrder"<<endl; 
             cin>>l1;
           cout << "Inorder List" <<endl;  
             for(int i=0;i<l1;i++)
                cin>>a[i];
           
           cout << "PreOrder List" <<endl;  
             for(int i=0;i<l1;i++)
                cin>>b[i];
             
             root1 = createTreeIP(a,l1,b,l1);
             printTree(root1);
           break;
           case 8:
                cout << "Enter length PostOrder and InOrder"<<endl; 
                   cin>>l1;
             cout << "Inorder List" <<endl;  
              for(int i=0;i<l1;i++)
                 cin>>a[i];
           
           cout << "PostOrder List" <<endl;  
             for(int i=0;i<l1;i++)
                cin>>b[i];
             
             root2 = getTreeFromPostorderAndInorder(a,l1,b,l1);
             printTree(root2);
           break;
           case 9:
                     p = heightDiameter(root);
                     cout<< "Height : "<<p.first<<endl;
                     cout<< "Diameter : "<<p.second<<endl;
           break;
           case 10:
                  pairAns = minMax(root);
                  cout<< "Min : "<<pairAns.min<<endl;
                  cout<< "Max : "<<pairAns.max<<endl;
           break;
           case 11:
                     c = sumOfAllNodes(root);
                     cout <<"Sum is :"<< c << endl;
           break;
           case 12:
                      flag = isBalanced(root);
                      cout<<"Is Tree is Banced (1:Yes/0:No): "<<flag<<endl;
           break;
           case 13:
                      cout << "Enter range of two elements" << endl;
                      cin>> l1 >> l2;
                          elementsInRangeK1K2(root,l1,l2);
           break;
           case 14:  cout<<"Enter value to find?"<<endl;
                      cin>>x;
                       root1 = searchInBST(root,x);
                       if(root1==NULL)
                          cout<<"Node does not exist."<<endl;
                       else   
                          cout << "Node Exist : "<<root1->data<<endl;
           break;
           case 15:
               cout << "1.Using max and min (TC : n*h)" << endl;
               cout << "2.Using INT_MAX and INT_MIN (Best Solution)" << endl;
               cout << "3.Using pair class (TC : n)" << endl;
               cin>>c;
               switch(c)
               {
                 case 1:
                       flag = isBSTree(root);
                          if(flag)
                             cout<<"Yes"<<endl;
                          else
                             cout<<"No"<<endl;
                break;
                 case 2:
                 
                flag = isBST(root);
                if(flag)
                  cout<<"Yes"<<endl;
                else
                  cout<<"No"<<endl;
                break;
                case 3:
                  isBSTclass bb = isBST2(root);
                if(bb.isBST)
                  cout<<"Yes"<<endl;
                else
                  cout<<"No"<<endl;
                break;
                    
               }
           break;
           case 16:
                    cout <<"Enter size of array."<<endl;
                    cin>>x;
                    for(int i=0;i<x;i++)
                       cin>>a[i];
                   root = constructTree(a,x);
           break;
           case 17:
                      node = constructBST_LL(root);
                      printLL(node);
           break;
           default: cout << "Please type correct choice!" << endl; 
           break;
        } 
    }while(ch!=-1);
     
    delete a;
    delete b;
    return 0;
}



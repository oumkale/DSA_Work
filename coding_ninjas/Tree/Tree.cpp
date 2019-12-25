#include <iostream>
#include "TreeNode.h"
#include <queue>
using namespace std;
void printTree(TreeNode<int>* root)
{
  if(root == NULL)
    return ;
   
  cout<< root -> data << " : ";
  for(int i=0;i< root->children.size();i++)
    cout<<root->children.at(i)->data<<"  ";
  cout<<endl;
  for(int i=0; i<root->children.size(); i++)
  {
       printTree(root->children.at(i));
  }
    
}

TreeNode<int>* makeTree(TreeNode<int>* root)
{
    
      cout << "Enter Data : " << endl;
      int data ;
      cin>>data;
      root = new TreeNode<int>(data);
     cout << " Enter Number of Nodes : " << endl;
      int n ;
      cin>>n;
      for(int i=0;i<n;i++)
      {
        TreeNode<int>* temp = makeTree(root);
        root -> children.push_back(temp);
      } 
      return root;
    
}
TreeNode<int>* makeTreeLevelWise()
{
   cout << "Enter Data : " << endl;
      int data ;
      cin>>data;
      TreeNode<int>* root = new TreeNode<int>(data);
      // Very important
      queue<TreeNode<int>*> pendingNodes;
      pendingNodes.push(root);
      TreeNode<int>* r = root;
      while(pendingNodes.size() != 0)
      {
         TreeNode<int> * front = pendingNodes.front();
         pendingNodes.pop();
         cout << " Enter Number of Nodes of parent : "<< front->data << endl;
         int n;
         cin>>n;
         for(int i=0;i<n;i++)
         {
            cout << "Enter Data of " <<i+1<<"th node. Root Node is " << front->data << endl;
             cin>>data;  
             TreeNode<int> * child = new TreeNode<int>(data);
             pendingNodes.push(child);  
             front->children.push_back(child);
         }
      }
      return r;
}
int numOfNodes(TreeNode<int>* root)
{
   int ans = 1;
   for(int i=0;i<root->children.size();i++)
     ans += numOfNodes(root->children.at(i));
     
    return ans; 
}
int sumOfNodes(TreeNode<int>* root)
{
   int sum=root->data;
   for(int i=0;i<root->children.size();i++)
   {
    sum += sumOfNodes(root->children.at(i));
    
   } 
   return sum; 
}

TreeNode<int>* maxDataNode(TreeNode<int>* root)
{
    if(root == NULL)
        return root;
    
     TreeNode<int>* max=root;
   for(int i=0;i<root->children.size();i++)
   {
       TreeNode<int>* temp = maxDataNode(root->children.at(i));
       if(temp->data > max->data)
           max = temp;
   } 
   return max; 
}

int height(TreeNode<int>* root)
 {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
  /// Very important
     int ans = 0;
   for(int i=0;i<root->children.size();i++)
   {
       int a = height(root->children.at(i));
       if(ans < a)
       {
        ans = a;
        
       }
   }    
    return ans+1; 
}
void printAtLevelK(TreeNode<int>* root,k)
{
   if(k == 0)
   {
     cout<<root->data<<endl;
   }
    for(int i=0;i<root->children.size();i++)
     printAtLevelK(root->children.at(i),k-1);
     
}
int numLeafNodes(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int ans=0;
    if(root == NULL)
        return ans;
    if(root -> children.size() == 0)
        ans += 1;
    for(int i=0;i<root->children.size();i++)
      ans += numLeafNodes(root->children.at(i));
     
     return ans;
}
int main()
{
    TreeNode<int>*root;
   /* TreeNode<int>*r1 = new TreeNode<int>(2);
    TreeNode<int>*r2 = new TreeNode<int>(3);
    
    root->children.push_back(r1);
    root->children.push_back(r2);
      */
     root = makeTreeLevelWise();
    //root = makeTree(root);
    cout << "Tree :" << endl;
    printTree(root);
    int l = numOfNodes(root);
    cout << "Number of Nodes in a tree is "<<l<<endl;
    int sum = sumOfNodes(root);
    cout << "Sum of Nodes is "<<sum<<endl;
    TreeNode<int>* max = maxDataNode(root);
    cout << "Max Data of Tree is "<<max->data<<endl;
    delete root;
    int he = height(root);
    cout << "Height of the Tree is "<<he<<endl;
    cout<<"Enter level to be printed of tree"<<endl;
    int k;
    cin>>k;
    printAtLevelK(root,k);
    cout<<"Number of Leaf nodes are "<<endl;
    int lNodes = numLeafNodes(root);
    cout<<lNodes<<endl
    
    
    return 0;
}

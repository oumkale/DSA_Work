#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
//====================
void printBFS(int** edge, int n, int sv, int* visited) 
{
    queue<int> pendingVertices;
	pendingVertices.push(sv);
	visited[sv] = 1;
	while (!pendingVertices.empty()) 
	{
		int currentVertex = pendingVertices.front();
		pendingVertices.pop();
		cout << currentVertex << " " ;
		for (int i = 0; i < n; i++) 
		{
			if (i == currentVertex) 
			{
				continue;
			}			
			if (edge[currentVertex][i] == 1 && !visited[i]) 
			{
				pendingVertices.push(i);
				visited[i] = 1;
			}
		}
	}
}
void BFS(int** edge, int n) 
{
		int * visited = new int[n];
		for (int i = 0; i < n; i++) 
		{
			visited[i] = 0;
		}
		for(int i = 0; i < n; i++) 
		{
			if(!visited[i]) 
			{
				printBFS(edge, n, i, visited);
			}
		}
	delete [] visited;
}
void printDFS(int **edge, int sv, int *visited, int n)
{
   cout << sv << " ";
   visited[sv]=1;
   for(int i=0;i<n;i++)
   {
      if(sv == i)
        continue;
      if(edge[sv][i] == 1)
      {  
        if(visited[i] == 1)
          continue;
        printDFS(edge,i,visited,n); 
      }
   }   
}
void DFS(int **edge,int n)
{
    
	 int visited[n];
     for(int i=0;i<n;i++)
      visited[i] = 0;
      for(int i=0;i<n;i++)
      {
          if(visited[i]==0)
          {
            printDFS(edge,i,visited,n);
          }
      }
      
}
int main() 
{
	int n;
	int e;
	cout << "Enter number of Vertex and Edges :" << endl;
	cin >> n >> e;
	int** edge = new int*[n];
	for (int i = 0; i < n; i++) 
	{
		edge[i] = new int[n];
		for (int j = 0; j < n; j++) 
		{
			edge[i][j] = 0;
		}
	}
	for (int i = 0; i < e; i++) 
	{
		int f, s;
		cin >> f >> s;
		edge[f][s] = 1;
		edge[s][f] = 1;
	}
	
	 int visited[n];
   for(int i=0;i<n;i++)
      visited[i] = 0;
	//BFS(edge, n);
	
	int c;
   cout << "Which Graph Connected or Disconnected?" << endl;
   cin>>c;
   if(c==1)
   {    
     cout << "**Connected Graph**" << endl;
     cout << "DFS Traversal :"<<endl;
     printDFS(edge,0,visited,n);
     cout << "BFS Traversal :"<<endl;
     printBFS(edge,n,0,visited);
   }
   else
   {
     cout << "**Non Connected**" << endl;
     cout << "DFS Traversal :"<<endl;
     DFS(edge,n);
     cout << "BFS Traversal :"<<endl;
     BFS(edge,n);
   }
   for (int i = 0; i < n; i++) 
	{
		delete [] edge[i];
	}	
}

//====================
/*
void printDFS(int **edge, int sv, int *visited, int n)
{
   cout << sv << " ";
   visited[sv]=1;
   for(int i=0;i<n;i++)
   {
      if(sv == i)
        continue;
      if(edge[sv][i] == 1)
      {  
        if(visited[i] == 1)
          continue;
        print(edge,i,visited,n); 
      }
   }   
}
void printBFS(int **edge, int n)
{
   int sv=0;
   int visited[n],currVer;
   for(int i=0;i<n;i++)
      visited[i] = 0;
    
   queue<int> pendingVer;
   pendingVer.push(0);
   visited[sv] = 1;
   
   while(!pendingVer.empty())
   {
        currVer = pendingVer.front();
        pendingVer.pop(); 
        cout << currVer << " ";
        
        for(int i=0;i<n;i++)
        {
            if(currVer == i)
              continue;
            sv = currVer;
            if( edge[sv][i]==1 && visited[i]==0 ) 
            {
               pendingVer.push(i);
               visited[i]=1;
            }
        }    
   }   
}
*/
/*
int main()
{ 
   int n,e;
   cout << "Enter number of Vertex and Edges :" << endl;
   cin>>n>>e;
   int **edge = new int*[n];
   for(int i=0;i<n;i++)
   {
     edge[i] = new int[n];
      for(int j=0;j<n;j++)
        edge[i][j]  = 0;
   } 
   int fv,ev;
   for(int i=0;i<e;i++)
   {
      cin>>fv>>ev;
      edge[fv][ev] = 1;
      edge[ev][fv]=1;
   }
   int visited[n];
   for(int i=0;i<n;i++)
      visited[i] = 0;
      
   cout << "**Connected Graph**" << endl;
     cout << "DFS Traversal :"<<endl;
     print(edge,0,visited,n);
     cout << "BFS Traversal :"<<endl;
     printBFS(edge,n);
   cout << "**Non Connected**" << endl;
   cout << "DFS Traversal :"<<endl;
     print(edge,0,visited,n);
     cout << "BFS Traversal :"<<endl;
     printBFS(edge,n);
   return 0;
print}
*/

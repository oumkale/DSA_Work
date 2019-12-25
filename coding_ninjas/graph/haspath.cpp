#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
bool hasPath_DFS(unordered_map<int, vector<int>* > &adjacencyList, int v1, int v2, unordered_map<int, bool> &visited) 
{
	vector<int> *adjacentVertices = adjacencyList[v1];
for(int i = 0; i < adjacentVertices -> size(); i++) {
		if(adjacentVertices -> at(i) == v2) {
			return true;
		}
	}
	visited[v1] = true;
	for(int i = 0; i < adjacentVertices -> size(); i++) 
	{
		if(visited.count(adjacentVertices -> at(i)) == 0) 
		{
			bool ans = hasPath_DFS(adjacencyList, adjacentVertices -> at(i), v2, visited);
			if(ans) 
			{
				return true;
			}
		}
	}
	return false;
}
bool hasPath_DFS(unordered_map<int, vector<int>* > &adjacencyList, int v1, int v2) 
{
	unordered_map<int, bool> visited;
	return hasPath_DFS(adjacencyList, v1, v2, visited);
}
int main() 
{
	int n, e;	
	cin >> n >> e;
    unordered_map<int, vector<int>* > adjacencyList;
	for(int i = 0; i < n; i++) 
	{
		vector<int> *v = new vector<int>;
		adjacencyList[i] = v;
	}
	int count = 1;
	while(count <= e) 
	{
		int source, dest;
		cin >> source >> dest;
		adjacencyList[source] -> push_back(dest);
		adjacencyList[dest] -> push_back(source);
		count++;
	}
	int v1, v2;
	cin >> v1 >> v2;
	if(hasPath_DFS(adjacencyList, v1, v2)) 
	{
		cout<< "true" << endl;
	}
	else 
	{
		cout<< "false" << endl;
	}
	return 0;
}
/*
//====================
bool printBFS(int** edge, int n, int sv,int en, int* visited) 
{
    queue<int> pendingVertices;
	pendingVertices.push(sv);
	visited[sv] = 1;
	while (!pendingVertices.empty()) 
	{
		int currentVertex = pendingVertices.front();
		pendingVertices.pop();
        
				if(currentVertex == en)
				  return 1;	
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
	return 0;
}
bool printDFS(int **edge, int sv,int en, int *visited, int n)
{
   
   cout << sv << " ";
   visited[sv]=1;
   if(visited[en]==1)
     return 1;
   for(int i=0;i<n;i++)
   {
      if(sv == i)
        continue;
      if(edge[sv][i] == 1)
      {  
        if(visited[i] == 1)
          continue;
        printDFS(edge,i,en,visited,n); 
      }
   } 
   return 0;  
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
	
   cout << "Enter start and end index :" << endl;
   int st,en;
   cin>>st>>en;
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
    int visited1[n];
   for(int i=0;i<n;i++)
      visited1[i] = 0;  
	//BFS(edge, n);
	
   bool l=false;
     cout << "DFS Traversal :"<<endl;
     l = printDFS(edge,st,en,visited,n);
     cout <<endl<< "Is Path : " <<l<< endl;
     l=false;
     cout << "BFS Traversal :"<<endl;
     l = printBFS(edge,n,st,en,visited1);
     cout <<endl<< "Is Path : " <<l<< endl;
   for (int i = 0; i < n; i++) 
	{
		delete [] edge[i];
	}	
	delete [] edge;
}
*/

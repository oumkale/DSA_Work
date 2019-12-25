#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <map>
using namespace std;
priority_queue<int> buildpriorityqueue(vector<char> ch,vector<int> freq, int n)
{
     priority_queue<int,vector<int>,greater<int>> pq; 
     for(int i=0;i<n;i++)
     {
         pq.push(freq[i]);
     }
     for()
     {
      
     }
     return pq;
}
map<char,int> buildhuffman(vector<char> ch,vector<int> freq, int n)
{
     priority_queue<int,vector<int>,greater<int>> pq; 
     pq = buildpriorityqueue(ch,freq,n);
}
int main()
{
    cout << "********** HUFFMAN CODING ************" << endl;
    vector<char> ch;
    vector<int> freq;
    cout << "Enter number of charters to be insert :"
    int n;
    cin>>n;
    cout << endl;
    char c;
    int f; 
    for(int i=0;i<n;i++)
    {
       cin >> c;
       cin>> f;
       ch.pusu_back(c);
       freq.push_back(f);
    }    
    map<char,int> m;
    m = buildhuffman(ch,freq,n);
    return 0;
}

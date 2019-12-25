#include <iostream>
#include <vector>
#include <unordered_map>
#include <string> 
#include <unordered_set>
#include <map>
#include <set>
#include <vector>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#include <unordered_map>
void printPairs(int *input, int n, int k) {
        unordered_map<int, int> m;
    for(int i = 0; i < n; i++) 
    {
        int key = input[i];
        m[key]++;
    }
    for(int i = 0; i < n; i++) 
    {
        int key = input[i];
        if(k == 0) 
        {
        int a = m[key];
        int count = ((a - 1) * a) / 2;
            for(int j = 0; j < count; j++) 
            {
            cout << key << " " << key << endl;
            }
        }
        else 
        {
            int a = key + k;
            int b = key - k;
            int count = m[key];
            int count1 = m[a];
            int count2 = m[b];
            for(int j = 0; j < count*count1; j++) 
            {
                cout << min(a, key) << " " << max(a, key) << endl;
            }
            for(int j = 0; j < count*count2; j++) 
            {
                cout << min(b, key) << " " << max(b, key) << endl;
            }
        }
        m.erase(key);
    }
}
std::vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
	//Your Code goes here

	std::unordered_map<int,bool> visitedElements ;
    std::unordered_map<int,int> elementToIndexMapping;
    for(int i = 0; i < n; i++)
    {
         elementToIndexMapping[arr[i]] = i;
        if(visitedElements.count(arr[i]) == 0)
        {
         visitedElements[arr[i]] = true;
    
        }
    }
     std::vector<int> longestSequence;
     int globalMaxSequenceLength = 1;
     int globalMinStartIndex = 0;
      for(int i = 0; i < n; i++)
      {
        int num = arr[i];
        int currentMinStartIndex = i;
        int count = 0;
        int tempNum = num;
        //Forward
        while(visitedElements.count(tempNum) == 1 && visitedElements[tempNum] == true)
        {
            visitedElements[tempNum] = false;
            count++;
            tempNum++;
        }
        //Backward
        tempNum = num-1;
        while(visitedElements.count(tempNum) == 1 && visitedElements[tempNum] == true)
        {
            visitedElements[tempNum] = false;
            count++;
            currentMinStartIndex = elementToIndexMapping[tempNum];
            tempNum--;
        }
       if(count > globalMaxSequenceLength)
       {
          globalMaxSequenceLength = count;
          globalMinStartIndex = currentMinStartIndex;
        }
        else if(count == globalMaxSequenceLength) 
        {
          if(currentMinStartIndex < globalMinStartIndex) 
           {
               globalMinStartIndex = currentMinStartIndex;
           }
        }
     }
        int globalStartNum = arr[globalMinStartIndex];
        longestSequence.push_back(globalStartNum);
        globalMaxSequenceLength--;
        while(globalMaxSequenceLength != 0)
        {
            globalStartNum++;
            longestSequence.push_back(globalStartNum);
            globalMaxSequenceLength--;
        }
   return longestSequence;
}
int lengthOfLongestSubsetWithZeroSum(int* arr, int size){
unordered_map<int,int> freq;
for(int i=1;i<size;i++)
arr[i]+=arr[i-1];
int m=0;
for(int i=0;i<size;i++){
if(arr[i]==0){
if(m<i+1) m=i+1;
}
else if(freq.count(arr[i])>0){
if(m<i-freq[arr[i]]) m=i-freq[arr[i]];
}
else freq[arr[i]]=i;
}
return m;
}
int main()
{
    unordered_map<string,int> ourUnMap;
    map<string,int> ourMap;
    // for Unordered map
   // pair<string,int> p("abc");
   // ourUnMap.insert(p)=4;
    ourUnMap["def"]=1;
    ourUnMap["ijk"]=2;
    ourUnMap["lmn"]=3;
    // for Ordered map
    //pair<string,int> p1("abc");
    //ourMap.insert(p1);
    ourMap["def"]=1;
    ourMap["ijk"]=2;
    ourMap["lmn"]=3;
    // Creating iterator for unordered map
    unordered_map<string,int>::iterator it = ourUnMap.begin();
    // Print all values
    while(it != ourUnMap.end())
    {
       cout << "Key :" << it -> first << "Value :" << it -> second << endl;
       it++;
    } 
    // Creating iterator for Ordered map
    map<string,int>::iterator it1 = ourMap.begin();
    // Print all values
    while(it1 != ourMap.end())
    {
       cout << "Value :" << it1->first << "Key :"<< it1->second << endl;
       it1++;
    }
    // ********* Vector **********
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    vector<int>::iterator it2 = v.begin();
    while(it2 != v.end())
    {
       cout << "Value :" << *it2  << endl;
       it2++;
    }
    int l,a[100];
    cout << "Enter Array Length" << endl;
      cin >> l;
    cout << "Enter Array" << endl;
        for(int i=0;i<l;i++)
          cin>>a[i];
    cout << "Longest Subsequence Inc" << endl;
    vector<int> c = longestConsecutiveIncreasingSequence(a,n);
    // 
    vector<int> :: iterator it1=c.begin();
    while(it1 != c.end())
    {
       cout << *it1 << "";
       it1++;
    }
    cout << endl
     cout << "Pairs with diff k" << endl;
     int k;
     cout <<"k? "<< endl;
     cin>>k;
     
     printPairs(a,n,k);
           cout << "lengthOfLongestSubsetWithZeroSum" << endl;
     lengthOfLongestSubsetWithZeroSum(a,n)
    return 0;
}

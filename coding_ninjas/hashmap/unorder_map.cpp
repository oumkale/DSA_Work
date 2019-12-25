#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
void basic()
{
   
   unordered_map<string,int> ourmap;
   //pair<ket,value>
   pair<string, int> ourpair("abc",1);
   ourmap.insert(ourpair);
   ourmap["def"] = 2;
   cout << ourmap.at("abc") << endl;
   //error cout << ourmap.at("ghi") << endl;
   cout << ourmap["ghi"] << endl;
   cout << ourmap["def"] << endl;
   cout<< ourmap.count("ghi") << endl; // Will create key and value is 0.
   if(ourmap.count("ghi") > 0)
   {
      cout<< "Yes present" << endl;
   }
   
   cout <<"Size :"<< ourmap.size() << endl;
   
   ourmap.erase("ghi");
   
   cout <<"Size :"<< ourmap.size() << endl;
}
vector<int> removeDuplicate(int *a,int n)
{
   vector<int> v;
    unordered_map<int,bool> ourmap;
  
    for(int i=0;i<n;i++)
    {
        if(ourmap.count(a[i]) > 0)
          continue;
        ourmap[a[i]] = true;
        v.push_back(a[i]);       
    }
   return v;
}
int freq(int *a, int n)
{
             vector<int> vec;
     unordered_map<int,int> ourmap;
     int max=0,u=0,m,j;
     for(int i=0;i<n;i++)
     {
         ourmap[a[i]]++;
         u++;
     }
     m=0;
     for(int i=0;i<u;i++)
     {
         m = ourmap[a[i]];
         if(m > max)
         { 
            max = m;
            j = a[i]; 
         }
      }
     return j;

     	
}
int takearray(int *a)
{
     int n;
           cout << "Enter size of array" << endl;
           cin>>n;
           cout << "Array ?" << endl;
           for(int i=0;i<n;i++)
              cin>>a[i];     
     return n;
}
void intersection(int a[], int b[], int n, int m) 
{
      unordered_map<int,int> ourmap;
    
    for(int i=0;i<n;i++)
    {
        
        ourmap[a[i]]++;
    }
    for(int i=0;i<m;i++)
    {
        if(ourmap[b[i]] > 0)
        {
            ourmap[b[i]]--;
            cout << b[i] << endl;
            
        }
    }
    
}
void PairSum(int arr[], int n) 
{ 
     int sum=0;
    unordered_map<int, int> m; 
  for (int i = 0; i < n; i++) { 
   int rem = sum - arr[i]; 
        if (m.find(rem) != m.end()) { 
            int count = m[rem]; 
            for (int j = 0; j < count; j++) 
            {
                if(rem < arr[i])
                 cout << rem << " "  << arr[i]  << endl;
                 else
                  cout << arr[i] << " "  << rem  << endl;
            }    
        } 
        m[arr[i]]++; 
    } 
} 
int main()
{
     int ch,n,m;
     
   unordered_map<string,int> ourmap;
   //pair<ket,value>
   pair<string, int> ourpair;
   vector<int> v;
   int a[10],b[10];
   
   do{
        cout << "**********Hashing************" << endl;
        cout << "1. Basic Operations" << endl;
        cout << "2. Remove Duplicates" << endl;
        cout << "3. Maximum Freaquency Number" << endl;
        cout << "4. Intersection of two arrys" << endl;
        cout << "5. Pairs having sum Zero" <<endl;
        cout << "Enter choice :";
        cin >> ch;
        switch(ch)
        {
           case 1: basic();
           break;
           case 2:
                   takearray(a);
            v = removeDuplicate(a,n);
            for(int i=0;i<v.capacity();i++)
                cout << v[i]<< " ";
                cout<< endl;  
           break;
           case 3:
                   n = takearray(a);
                   m = freq(a,n);
           break;
           case 4:
                n = takearray(a);
                m = takearray(b);
               intersection(a,b,n,m);
           break;
           case 5:
               n = takearray(a);
                 PairSum(a,n);
           break;
           default:  cout << "Enter correct choice" << endl;
           break;
        }
   }while(ch!=-1);
     
}

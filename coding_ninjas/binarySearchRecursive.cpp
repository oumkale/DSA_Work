#include <iostream>
using namespace std;
int find(int input[],int start ,int size, int element)
{
    if(size  < start )
        return -1;
    int mid = (size + start)/2;
    if(element == input[mid])
        return mid;
    else if(element < input[mid])
    {
      
      find(input,start, mid-1, element);
    }
    else
    {
    
        find(input,mid+1,size, element);
    }  
}
int binarySearch(int input[], int size, int element) {

    int r = find(input,0, size-1, element);
    return r;
}
int main()
{
   int n,x,a[1000];
   cin>>n;
   for(int i=0;i<n;i++)
     cin>>a[i];
   cin>>x;  
   int ans = binarySearch(a,n,x);
   cout<<ans<<endl;
   return 0;
}


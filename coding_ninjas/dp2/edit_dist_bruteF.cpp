#include <iostream>
#include <vector>
using namespace std;

int editDistance(string a, string b){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    if(a.size() ==0 || b.size()==0)
         return max(a.size(), b.size());
     if(a[0] == b[0])
        return  editDistance(a.substr(1),b.substr(1));
     else
     {
         //write your code here
       int x,y,z;
       x = 1 + editDistance(a.substr(1),b);
       y = 1 + editDistance(a,b.substr(1));
       z = 1 + editDistance(a.substr(1),b.substr(1));
       int m = min(x,min(y,z));
       return m;
     }
         
}

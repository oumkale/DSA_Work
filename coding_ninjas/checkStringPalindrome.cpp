#include <iostream>
#include <cstring>
using namespace std;
bool checkPalindrome(string a,int start, int end)
{
    if(a[0] == '\0' || a[1] == '\0')
       return true;
    if(start>=end)
      return true;
    
    if(a[start] == a[end])
       checkPalindrome(a,start + 1, end - 1);     
    else
      return false;
}
int main()
{
  string str;
  cout << "Enter string : "<<endl; 
  cin>>str;
  int l = str.size();
 // char a[] = "Oum Kale";
  //int k = strlen(a);
  //cout<<"Length of char :"<<k<<endl;
   bool flag = checkPalindrome(str,0,l-1);
  if(flag)
     cout<< "Yes, it is palindrome. "<<endl;
  else
     cout<< "No, it is not palindrome. "<<endl;   
     
  return 0;
}

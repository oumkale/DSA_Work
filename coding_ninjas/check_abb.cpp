#include <iostream>
using namespace std;
int length(char input[])
{
    if(input[0] == 0)
        return 0;
    int l = length(input+1);
    return l +1;
}
bool func(char input[],int start,int end)
{
     
        if(input[start] == '\0')
           return true;
          
    if(input[0] == 'a')
    {  
        
     if( input[0+1] == 'b'  && input[0+2] == 'b')
           func(input+3,start,end-3);
        else
            func(input+1,start,end-1);
    } 
    else
        return false;
}
bool checkAB(char input[]) {
	// Write your code here
    int l = length(input);
    bool r = func(input ,0,l);
   return r;
}

int main()
{
  char a[100];
  cin>>a;
  bool r; 
    if(checkAB(a))
       cout<<"true"<<endl;
    else
       cout<<"false"<<endl;      
}



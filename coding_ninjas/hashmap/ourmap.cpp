#include <iostream>
#include "ourmap.h"
using namespace std;
int main()
{
   ourmap<int> map;
   string key;
   cout << "Main" << endl;
   for(int i=0;i<5;i++)
   {
       cout << "Enter key " << endl;
       cin>>key ;
       
       int value = i+1;
       map.insert(key, value);
       cout <<" Load Factor :"<<map.getLoadFactor()<<endl;
   }
   cout<<map.size()<<endl;
   cout<<map.getValue("abc")<<endl;
   cout<<map.remove("def",map.getValue("def"))<<endl;
   cout<<map.size()<<endl;
   
   return 0;
}

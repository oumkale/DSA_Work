#include <vector>
#include<cstring>
#include<string>
#include <iostream>
#include "Trie.h"
using namespace std;
int main() 
{
   Trie t;
   int ch,choice,l,ans,m;
   vector<string> vect;
   bool tr=true;
   string word;
   do{
      cout << "Trie" << endl;
      cout << "1.Add word" << endl;
      cout << "2.Search Word" << endl;
      cout << "3.Remove Word"<< endl;
      cout << "4.Pattern Matchhing" << endl;
      cout << "9.Enter Choice :";
      cin >> ch;
      switch(ch)
      {
         case 1: 
          cout << "Enter a word to Add :";
           cin >> word;
                t.insertWord(word);
                cout << endl;
         break;
         case 2:
         // getline(cin, word);
           cout << "Enter a word to Search :";
         
            	cin >> word;
                ans = t.search(word);
                if (ans) {
                    cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
                cout << endl;
         break;
         case 3:
           
          cout << "Enter a word to Remove :";
           cin >> word;
                t.remove(word);
                cout << endl;
         break;
         case 4:
             cout << "Enter n :"; cin>>m;
             cout << "Enter n words" << endl;
             for(int i=0;i<m;i++)
             {
                cin>>word;
                vect.push_back(word);
             }
             cout <<"Enter a word to match :" ; cin>>word;
             tr = t.patternMatching(vect,word);
             
             if(tr == true)
               cout << "Yes" << endl;
             else
               cout << "No" << endl;  
             cout << endl;
         break;
         default:  cout << "Please Enter Correct choice" << endl;
         break;
         
      }
      
   }while(ch!=-1);
             
	return 0;
}

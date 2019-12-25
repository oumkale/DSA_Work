#include <vector>
#include <string>
#include <iostream>
#include "TrieNode.h"
using namespace std;
std::string word;
class Trie
{  
   
   TrieNode *root;
   
   int count;
   public:
   Trie()
   {
      root = new TrieNode('\0');
      count =0;
   }   
   void insert(TrieNode *root ,std::string word)
   {
       if(word.size() == 0)
       {
          root->isTerminal = true;
          return ;
       }
       char index = word[0] - 'a'; 
       TrieNode *child;
       if(root -> children[index])
       {
          child = root -> children[index];
       }
       else
       {
         child = new TrieNode(word[0]);
         root -> children[index] = child;
         
       }
       insert(child,word.substr(1));
   }
   void insertWord(std::string word)
   {
       insert(root,word);
  		this->count++;
		
	}
   void removeword(TrieNode *root, std::string word)
   {
       if(word.size() == 0)
       {
          root -> isTerminal = false;
          return ;
       }
       TrieNode *child;
       int index = word[0] - 'a';
       if(root -> children[index])
       {
               child = root -> children[index];
               
       }
       else
           return ;
       removeword(child,word.substr(1));
            if(child -> isTerminal == false)
            {
              for(int i=0;i<26;i++)
              {
                if(child->children[i])
                  return;
              }
            }  
            delete child;
            child -> children[index] = NULL;      
   }

	
	// For 
	//==============
	
	   bool search(TrieNode *root, std::string word) 
	   { 
	       if(word.size() == 0) 
	       { 
	          return root -> isTerminal; 
	       } 
	       int index = word[0] - 'a'; 
	       TrieNode *child; 
	       if(root -> children[index] != NULL) 
	       { 
	           child = root -> children[index]; 
	       }
	       else 
	       { 
	         return false; 
	       } 
	       return search(child, word.substr(1)); 
	   } 
	   bool search(std::string word) 
	   { 
	      return search(root, word); 
	   }
 
	//===========
	
	//for pattern maching
     bool searchMP(TrieNode * root, std::string word)
    {
        int index = word[0] -'a';
        TrieNode *child;
         if(word.size() == 1)
         {
             if(root -> children[index])
                  return true;
             else
                 return false;
                                 
         }
         else
         {
             if(root -> children[index])
                     child = root -> children[index];
             else  
                    return false;                          
                                              
         }
         return searchMP(child,word.substr(1)); 
                                                      
    }
    //==================
    
    //=======
	bool patternMatching(std::vector<std::string> vect, std::string word) {
		// Complete this function
		// Return true or false
        std::string wo;
        //cout << "---" << endl;
        for(int i=0; i<vect.size(); i++)
        {
            wo = vect[i]; 
            for(int j=0; j<wo.size(); j++)
            {
              
            //cout << wo.substr(j) << endl;
               insertWord(wo.substr(j));
            }    
        }
        
        return searchMP(root,word);   
	}


   void remove(std::string word)
   {
       removeword(root, word);
   }
};

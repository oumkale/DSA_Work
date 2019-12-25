#include <string>
#include <vector>
#include <iostream>

#include<algorithm> 
using namespace std;
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;
	int childCount;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
		childCount = 0;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
			root->childCount++;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}

	
    bool searchMP(TrieNode * root, string word)
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
   bool search(string word) 
	   { 
	      return searchMP(root, word); 
	   }
	bool findIfPalindromePair(vector<string> vect) {
		// Complete this function
		// Return true or false.
        std::string wo;
        vector<string> rev;
        //cout << "---" << endl;
        for(int i=0; i<vect.size(); i++)
        {
            wo = vect[i]; 
              //cout << "-->"<<wo << endl;
            //cout << wo.substr(j) << endl;
               insertWord(wo);
            reverse(wo.begin(),wo.end());
            
              //cout << "<--"<<wo << endl;
            rev.push_back(wo);
            
        }
        int count=0;
        for(int i=0; i<rev.size(); i++)
        {
                if(search(rev[i]))
                {
                 // cout << vect[i]<<" --" << rev[i]<< endl;
                   
                    count++;
                }    
        }
        if(count)
            return true;
        else
            return false;
        
	}
};


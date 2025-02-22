#include<iostream>
using namespace std;

class TrieNode {

    public:
            char data;
            TrieNode * children[26];
            bool isTerminal;
    
            TrieNode (char ch){
                data = ch;
                for(int i=0;i<26;i++){
                    children[i]=NULL;
                }
                isTerminal=false;
            }

};

class Trie {
    public:
            TrieNode* root;

            //constructer.
            Trie(){
                root = new TrieNode('\0');
            }

            //recursive func.
            void insertUtil(TrieNode* root,string word){
                //base case
                if(word.length()==0){
                    root->isTerminal=true;
                    return;
                }
                //index_assuming char are in caps
                int index = word[0]-'A';
                TrieNode * child;//pointer to specific children_node.

                //if caharcter is present.
                if(root->children[index]!=NULL){
                    child=root->children[index];
                }
                //not present
                else{
                    child = new TrieNode(word[0]);
                    root->children[index]=child;
                }
                insertUtil(child,word.substr(1));
            }

            void insertWord(string word){
                insertUtil(root,word);
            }

            bool searchUtil(TrieNode * root,string word){
                if(word.length()==0){
                    return root->isTerminal;
                }

                int index = word[0]-'A';
                TrieNode*child;

                if(root->children[index]!=NULL){
                    child=root->children[index];
                }
                else{
                    return false;
                }
                return searchUtil(child,word.substr(1));
            }

            bool searchWord(string word){
                searchUtil(root,word);
            }
};

int main(){

    Trie *first = new Trie();

    first->insertWord("abcd");
    //search
    cout<<endl;
    bool result = first->searchWord("abcd");
    cout<<result;

}
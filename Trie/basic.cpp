#include<iostream>
#include<climits>
using namespace std;

class Trienode {
    public:
        char data;
        Trienode* children[26];
        bool isTerminal;

        Trienode(char ch) {
            data = ch;
            for (int i = 0; i < 26; i++)
            {
                children[i] = NULL;
            }
            isTerminal = false;
            
        }
};

class Trie {
    public:
        Trienode* root;

        Trie() {
            root = new Trienode('\0');
        }

        void insertUtil(Trienode* root, string word) {

            //base case for recursion
            if(word.length() == 0) {
                root -> isTerminal = true;
                return;
            }

            //assumption, word will be in caps
            int index = word[0] - 'A';
            Trienode* child;

            //present 
            if(root -> children[index] != NULL) {
                child = root -> children[index];
            }
            else {
                //absent
                child = new Trienode(word[0]);
                root -> children[index] = child;
            }

            //recursion
            insertUtil(child, word.substr(1));
        }

        void insertword(string word) {
            insertUtil(root, word);
        }

        bool searchUtil(Trienode* root, string word) {
            //base case
            if(word.length() == 0) {
                return root->isTerminal;
            }

            int index = word[0] - 'A';
            Trienode* child;

            //present
            if(root -> children[index] != NULL ) {
                child = root -> children[index];
            }
            else{
                //absent
                return false;
            }

            //recursion
            return searchUtil(child, word.substr(1));
        }

        bool searchWord(string word) {
            return searchUtil(root, word);
        }


};

int main() {

    Trie *t = new Trie;

    t->insertword("ARM");
    t->insertword("DO");
    t->insertword("TIME");

    cout << "present or not " << t->searchWord("abcdw") << endl;

    return 0;
}

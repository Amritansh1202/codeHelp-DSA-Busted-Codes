#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
        
    }
};

class Trie
{
    public:

    TrieNode* root;

    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode* root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root -> isTerminal = true;
            return;
        }
        
        // assumption : word will be in CAPS
        int index = word[0] - 'a';
        TrieNode* child;

        // present
        if (root -> children[index] != NULL)
        {
            child = root -> children[index];
        }
        else
        {
            // absent
            child = new TrieNode(word[0]);
            root -> childCount++;
            root -> children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void longestCommon(string str, string &ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if (root -> childCount == 1)
            {
                ans.push_back(ch);
                // aage badh jao

                int index = ch - 'a';
                root = root -> children[index];
            }
            else
            {
                break;
            }

            if (root -> isTerminal)
            {
                break;
            }
            
            
        }
        

    }
};

void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix)
{
    if (curr ->isTerminal)
    {
        temp.push_back[prefix];
    }
    
    for (char ch = 'a'; ch < 'z'; ch++)
    {
        TrieNode* next = curr -> children[ch - 'a'];

        if (next != NULL)
        {
            prefix.push_back(ch);
            printSuggestions(next, temp, prefix);
            prefix.pop_back(); 
        }
        
    }
    
}

vector<vector<string> > getSuggestions(string str)
{
    TrieNode* prev = root;
    vector<vector<string> > output;
    string prefix = "";

    for (int i = 0; i < str.length(); i++)
    {
        char lastch = str[i];

        prefix.push_back(lastch);

        // check for lastch
        TrieNode* curr = prev -> children[lastch - 'a'];

        // if not found
        if (curr == NULL)
        {
            break;
        }
        else
        {
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
    }
    return output;
    
}

vector<vector<string> > phoneDirectory(vector<string>&contactList, string &queryStr)
{
    // crate a trie
    Trie *t = new Trie('\0');

    // insert all contact in trie
    for (int i = 0; i < contactList.size(); i++)
    {
        //string str = contactList[i];
        t -> insertWord(contactList[i]); 
    }
    return getSuggestions(queryStr);
}

int main(int argc, char const *argv[])
{
    
    
    return 0;
}

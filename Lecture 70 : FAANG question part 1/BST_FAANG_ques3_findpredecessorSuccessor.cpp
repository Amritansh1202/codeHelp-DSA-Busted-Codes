#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// Boundary Traversal

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }

};

pair<int, int> PredecessorSuccessor(Node* root, int key)
{
    // find key
    Node* temp = root;
    int pred = -1;
    int suc = -1;

    while (temp -> data != key)
    {
        if (temp -> data > key)
        {
            temp = temp -> left;
            suc = temp -> data;
        }
        if (temp -> data < key)
        {
            temp = temp -> right;
            pred = temp -> data;
        }
    }
    
    // pred and succ

    // pred
    Node* leftTree = temp -> left;
    while (leftTree != NULL)
    {
        pred = leftTree -> data;
        leftTree = leftTree -> right;
    }
    
    Node* rightTree = temp -> right;
    while (rightTree != NULL)
    {
        suc = rightTree -> data;
        rightTree = rightTree -> left;
    }
    
    pair<int, int> ans = make_pair(pred, suc);
    return ans;
}
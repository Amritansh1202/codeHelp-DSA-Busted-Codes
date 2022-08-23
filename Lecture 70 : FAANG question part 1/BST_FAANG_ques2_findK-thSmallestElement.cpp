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

// M1 : using inorder
int solve(Node* root, int &i, int k)
{
    // base case
    if (root == NULL)
    {
        return -1;
    }

    //L
    int left = solve(root -> left, i, k);
    if (left != -1)
    {
        return left;
    }
    // N
    i++;
    if (i == k)
    {
        return root -> data;
    }
    
    // R
    return solve(root -> right, i, k);
}

// M2 : Morris Traversal

int solveByMorrisTraversal(Node* root, int i, int k)
{
    Node* curr = root;

    while (curr != NULL)
    {
        if (curr -> left == NULL)
        {
            i++;
            if (i == k)
            {
                return curr -> data;
            }
            
            curr = curr -> right;
        }
        else
        {
            // find predecessor
            Node* pred = curr -> left;
            while (pred -> right != NULL)
            {
                pred = pred -> right;
            }
            
            if (pred -> right == NULL)
            {
                pred -> right = curr;
                curr = curr -> left;
            }
            else
            {
                pred -> right = NULL;
                i++;
                if (i == k)
                {
                    return curr -> data;;
                }
                
                curr = curr -> right;
            }
            
        }
        
    }
    
}

int kthSmallest(Node* root, int k)
{
    int i = 0;
    int ans =  solve(root, i, k);
    return ans;
}
#include <iostream>
#include <queue>

using namespace std;

class BinaryTreeNode {
    public : 
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};

void inorder(BinaryTreeNode* root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

bool twoSumInBST(BinaryTreeNode* root, int target) {
	//Write your code here

    vector<int> inorderVal;
    inorder(root, inorderVal);

    int i = 0, j = inorderVal.size();

    while (i < j)
    {
        int sum = inorderVal[i] + inorderVal[j];
        if (sum == target)
        {
            return true;
        }
        else if (sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
        
        return false;
    }
    
}
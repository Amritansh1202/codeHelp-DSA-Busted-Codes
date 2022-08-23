#include <iostream>
#include <queue>

using namespace std;

/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void inorder(TreeNode<int>* root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }
    
    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector <int> inorderVal;
    inorder(root, inorderVal);

    TreeNode<int>* newRoot = new TreeNode<int>(inorderVal[0]);

    // 2nd step 
    TreeNode<int>* curr = newRoot;
    for (int i = 1; i < inorderVal.size(); i++)
    {
        TreeNode<int> *temp = new TreeNode<int>(inorderVal[i]);
        curr -> left = NULL;
        curr -> right = temp;
        curr = temp;
    }
    
    // 3rd step - last vali node ka left aur right dono null kro
    curr -> left = NULL;
    curr -> right = NULL;

    return newRoot;
}
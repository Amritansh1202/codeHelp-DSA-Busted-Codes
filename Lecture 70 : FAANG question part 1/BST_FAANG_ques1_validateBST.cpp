#include <iostream>
#include <queue>

using namespace std;
/*******************************************
 * Bianry Tree Node Structure
 * 
class BinaryTreeNode 
{
public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
*********************************************/

class BinaryTreeNode 
{
public : 
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int d)
    {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

bool isBST(BinaryTreeNode<int> *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root -> data > min && root -> data < max)
    {
        bool left = isBST(root -> left, min, root -> data);
        bool right = isBST(root -> right, root -> data, max);
    }
    else
    {
        return false;
    }
    return left && right;
}

bool validateBST(BinaryTreeNode<int> *root) {
    

    return isBST(root, INT_MIN, INT_MAX);
}

int main(int argc, char const *argv[])
{
    
    
    return 0;
}

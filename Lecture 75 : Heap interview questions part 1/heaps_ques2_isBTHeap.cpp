#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <heap>

using namespace std;

    template<typename T>
     class BinaryTreeNode 
    {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() 
        {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

int countNodes(BinaryTreeNode<int>* root)
{
    if (root == NULL)
    {
        return 0;   
    }
    int ans = 1 + countNodes(root -> left) + countNodes(root -> right);
    return ans;
}

bool isCBT(BinaryTreeNode<int>* root, int index, int cnt)
{
    if (root == NULL)
    {
        return true;
    }
    if (index >= cnt)
    {
        return false;
    }
    else
    {
        bool left = isCBT(root -> left, 2*index + 1, cnt);
        bool right = isCBT(root -> right , 2*index + 2, cnt);
        return (left && right);
    }
}

bool isMaxOrder(BinaryTreeNode<int>* root)
{
    // base case
    if (root -> left == NULL && root -> right == NULL)
    {
        return true;
    }
    if (root -> right == NULL) // only left exist
    {
        return(root -> data > root -> left -> data);
    }
    else
    {
        bool left = isMaxOrder(root -> left);
        bool right = isMaxOrder(root -> right);

        return (left && right && (root -> data > root -> left -> data && root -> data > root -> right -> data));
    }
    
}

bool isBinaryHeapTree(BinaryTreeNode<int>* root) 
{
    int index = 0;
    int totalCount = countNodes(root);
    if (isCBT(root, index, totalCount) && isMaxOrder(root))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int main(int argc, char const *argv[])
{
    
    
    return 0;
}

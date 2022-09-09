#include <iostream>
#include <queue>
#include <heap>
#include <vector>

using namespace std;

template <typename T>
class Node
{
    public:
    T data;
    Node<T> *left;
    Node<T> *right;

    Node(T d)
    {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void inorder(Node<int> *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    
    inorder(root -> left, ans);
    ans.push_back(root -> data);
    inorder(root -> right, ans);
}

Node<int> *preorderToHeap(Node<int> *root, vector<int> &ans, int i)
{
    //base case
    if (root == NULL)
    {
        return;
    }
    root -> data = ans[i++];
    preorderToHeap(root -> left, ans, i);
    preorderToHeap(root -> right, ans, i);

    return root;
}

void convert(Node<int> *root)
{
    vector<int> ans;
    inorder(root, ans);

    Node<int> *tree = preorderToHeap(root, ans, 0);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}

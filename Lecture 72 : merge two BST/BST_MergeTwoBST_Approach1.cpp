#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

/*************
 * APPROACH 1
 * **************/

    template <typename t>
    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int d) {
                this -> data = d;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

void inorder(TreeNode<int> *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }
    
    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

vector<int> mergeArray(vector<int> a, vector<int> b)
{
    vector <int> ans(a.size() + b.size());
    int i = 0, j = 0;
    int k = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            ans[k++] = a[i];
            i++;
        }
        else 
        {
            ans[k++] = b[j];
            j++;
        }
        
    }
    while (i < a.size())
    {
        ans[k++] = a[i];
        i++;
    }
    while (j < b.size())
    {
        ans[k++] = b[j];
        j++;
    }
    return ans;
}

TreeNode<int>* inorderToBST(int s, int e, vector<int> &in)
{
    // base case
    if (s > e)
    {
        return NULL;
    }
    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(in[mid]); 
    root -> left = inorderToBST(s, mid - 1, in);
    root -> right = inorderToBST(mid + 1, e, in);

    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    
    // step 1 : store number

    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    // step 2 : sort two sorted arrays

    vector<int> mergedArray = mergeArray(bst1, bst2);

    // step 3 : inorderTOBST

    int s = 0, e = mergedArray.size() - 1;
    return inorderToBST(s, e, mergedArray);
}
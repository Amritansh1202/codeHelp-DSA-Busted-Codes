#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

/*************
 * APPROACH 2
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

// step 1 : CONVERT INTO SORTED DOUBLE LINKED LIST
TreeNode<int> *convertIntoSortedDLL(TreeNode<int> *root, TreeNode<int>* &head)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    convertIntoSortedDLL(root -> right, head);

    root -> right = head;
    if (head != NULL)
    {
    head -> left = head;    
    }
    head = root;
    convertIntoSortedDLL(root -> left, head);
}

TreeNode<int>* mergedLinkedList(TreeNode<int> *head1, TreeNode<int> *head2)
{
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1 -> data < head2 -> data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1 -> right;
            }
            else
            {
                tail -> right = head1;
                head1 -> left = tail;
                tail = head1;
                head1 = head1 -> right;
            }
            
        }
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2 -> right;
            }
            else
            {
                tail -> right = head2;
                head2 -> left = tail;
                tail = head2;
                head2 = head2 -> right; 
            }
            
        }
    }
    
    while (head1 != NULL)
    {
        tail -> right = head1;
        head1 -> left = tail;
        tail = head1;
        head1 = head1 -> right;
    }
    while (head1 != NULL)
    {
        tail -> right = head2;
        head2 -> left = tail;
        tail = head2;
        head2 = head2 -> right;
    }
    return head;
}

// count number of nodes
int countNodes(TreeNode<int> *head)
{
    int count = 0;
    TreeNode<int> *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp -> right;
    }
    return count;
}

TreeNode<int>* sortedLLToBST(TreeNode<int>* &head, int n)
{
    // base case
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }
    TreeNode<int> *left = sortedLLToBST(head, n/2);

    TreeNode<int> *root = head;
    root -> left = left;

    head = head -> right;

    root -> right = sortedLLToBST(head, n/2 - 1);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){

    // ste[ 1 : convert BST into sorted DLL
    TreeNode<int> *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1 -> left = NULL;

    TreeNode<int> *head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2 -> left = NULL;

    // step 2 : merge two sorted LL
    TreeNode<int> *head = mergedLinkedList(head1, head2);

   //  step 3 : convert sorted LL into BST
   return sortedLLToBST(head, countNodes(head));
}

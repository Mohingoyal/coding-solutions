/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int getbkst(TreeNode* root,int &counter,int & k)
{
    if(root==NULL)
    return -1;
    int recv;
    recv=getbkst(root->left,counter,k);
    if(recv!=-1)
    return recv;
    if(counter==k)
    return root->val;
    counter++;
    recv=getbkst(root->right,counter,k);

    return recv;
}
    int kthSmallest(TreeNode* root, int k) {
        int counter=1;
       int ans= getbkst(root,counter,k);
       return ans;
    }
};
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
int getdia(TreeNode* root,int &h)
{
    if(root==NULL)
    return 0;
    int h1=getdia(root->left,h);
     int h2=getdia(root->right,h);
    h=max(h1+h2,h);
     return max(h1,h2)+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
        int h=0;
        getdia(root,h);
        return h;
    }
};
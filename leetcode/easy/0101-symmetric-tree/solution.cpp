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
void getarray(TreeNode* root,vector<int> &ary)
{
    if(root==NULL)
    return;
    getarray(root->left,ary);
    ary.push_back(root->val);
    getarray(root->right,ary);
    return;
}
    bool isSymmetric(TreeNode* root) {
        vector<int> ary;
        getarray(root,ary);
        if(ary.size()%2==0)
        return false;
        for(int i=0;i<ary.size()/2;i++)
        {
            if(ary[ary.size()-1-i]!=ary[i])
            return false;
        }
        return true;
    }
};
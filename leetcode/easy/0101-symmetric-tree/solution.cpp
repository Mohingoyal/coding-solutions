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
bool mirrortree(TreeNode* root1,TreeNode* root2)
{bool var;
    if(root1==NULL&&root2==NULL)
    return true;
    if(root1==NULL||root2==NULL)
    return false;
    if(root1->val==root2->val)
    {
       var= mirrortree(root1->left,root2->right);
       if(var==false)
       return false;
        var=mirrortree(root1->right,root2->left);
        if(var==false)
        return false;
    }
    else var=false;
     return var;
}
    bool isSymmetric(TreeNode* root) {
        return mirrortree(root,root);
    }
};
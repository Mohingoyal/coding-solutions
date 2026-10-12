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
int height(TreeNode* root,bool &result)
{
    if(root==NULL)
    return 0;
  
int hleft=height(root->left,result);
int hright=height(root->right,result);
if(!(abs(hleft-hright)==1||abs(hleft-hright)==0))
result=false;
int x=max(hleft,hright)+1;
return x;
}
    bool isBalanced(TreeNode* root) {
        bool result=true;
        height(root,result);
        return result;
    }
};
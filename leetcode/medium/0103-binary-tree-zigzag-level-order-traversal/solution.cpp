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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
        return ans;
        queue<TreeNode* > q;
        q.push(root);
     
        int level=0;
        while(!q.empty())
        {vector<int> temp;
        int size=q.size();
        for(int i=0;i<size;i++)
        {TreeNode* ptr=q.front();
            temp.push_back(q.front()->val);
            q.pop();
            
                 if(ptr->left!=NULL)
                q.push(ptr->left);
                    if(ptr->right!=NULL)
                q.push(ptr->right);
            
        }
        if(level%2==0)
        {
            ans.push_back(temp);
        }
        else{
            for(int i=0;i<temp.size()/2;i++)
            {
               swap(temp[i],temp[temp.size()-1-i]);
            }
            ans.push_back(temp);
        }
        level++;
    
             
        }
        return ans;
        
    }
};
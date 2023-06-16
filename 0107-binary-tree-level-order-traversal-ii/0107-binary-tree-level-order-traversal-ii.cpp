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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> t;
        while(!q.empty()){
            
            TreeNode* tmp=q.front();
            q.pop();
            if(tmp!=NULL)
            t.push_back(tmp->val);
            
            
            if(tmp==NULL){
                ans.push_back(t);
                t.clear();
                if(!q.empty())
                q.push(NULL);
            }
            else{
                if(tmp->left!=NULL)q.push(tmp->left);
                if(tmp->right!=NULL)q.push(tmp->right);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
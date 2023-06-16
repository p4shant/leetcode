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
        if(root==NULL){
            return ans;
        }
        int test=1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int x=q.size();
            vector<int> tmp;
            for(int i=0;i<x;i++){
                TreeNode* node=q.front();
                q.pop();
                tmp.push_back(node->val);
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
            }
            if(!test){
                reverse(tmp.begin(),tmp.end());
                ans.push_back(tmp);
                test=1;
            }
            else{
                ans.push_back(tmp);
                test=0;
            }
        }
        return ans;
    }
};
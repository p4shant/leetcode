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
    int maxDepth(TreeNode* root) {
        int height=0;
        if(root==NULL)
            return height;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            ++height;
            for(int i=0;i<sz;i++){
                root=q.front();
                q.pop();
                if(root->left!=NULL)
                q.push(root->left);
                if(root->right!=NULL)
                q.push(root->right);
            }
        }
        return height;
    }
};
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


    void left(TreeNode* root,vector<int> &v1){
        queue<TreeNode*> q;
        if(root)
        q.push(root);

        while(!q.empty()){
            int sz=q.size();

            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node)
                v1.push_back(node->val);
                else
                v1.push_back(-101);
                if(node){
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
    }
    
    void right(TreeNode* root,vector<int> &v2){
        queue<TreeNode*> q;
        if(root)
        q.push(root);

        while(!q.empty()){

            int sz=q.size();

            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node)
                v2.push_back(node->val);
                else
                v2.push_back(-101);

                if(node){
                    q.push(node->right);
                    q.push(node->left);
                }
            }
        }
    }


    bool isSymmetric(TreeNode* root) {
        vector<int> v1,v2;

        left(root,v1);
        right(root,v2);

        if(v1==v2)
        return true;
        else
        return false;
    }
};
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
    
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        
        int l=height(root->left);
        int r=height(root->right);
        return max(l,r)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        
        if(root==NULL)
            return true;
        
        int lft=height(root->left);
        int rgt=height(root->right);
        
        //checking if tree is not balanced
        int df=abs(lft-rgt);
        if(df>1)
        return false;
        
        //calling the function again
        if(!isBalanced(root->left)) return false;
        if(!isBalanced(root->right)) return false;
        
        
        return 1;
    }
};
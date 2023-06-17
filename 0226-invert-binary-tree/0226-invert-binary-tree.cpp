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
// TreeNode* invert(TreeNode* tmp,TreeNode* root){
//     if(root==NULL)
//     return 0;
      
//     // tmp->left=root->right;
//     // root=root->right;
//     // tmp=tmp->left;
//     // invert(tmp,root);
//     // tmp->right=root->left;
//     // root=root->left;
//     // tmp=tmp->right;
//     // invert(tmp,root);
//     // return tmp;
// }

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return root;
        
        
        invertTree(root->left);
        invertTree(root->right); 
        
        swap(root->left,root->right);
        
        return root;
        
        
        // TreeNode* tmp=root;
        // return invert(tmp,root);
    }
};
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
    
    bool isSymmetric(TreeNode* root) {
        return root==NULL || isSymmetry(root->left,root->right);
    }
    bool isSymmetry(TreeNode* leftway,TreeNode* rightway){
        if(leftway==NULL || rightway==NULL) return leftway==rightway;
        if(leftway->val!=rightway->val) return false;
        return isSymmetry(leftway->left,rightway->right) && isSymmetry(leftway->right,rightway->left);
    }
};
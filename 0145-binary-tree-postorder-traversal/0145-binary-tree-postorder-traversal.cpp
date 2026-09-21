class Solution {
public:
    vector<int> postorder(TreeNode* root, vector<int>& ans) {
        if(root == NULL) return ans;
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
        return ans;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        return postorder(root, ans);
    }
};
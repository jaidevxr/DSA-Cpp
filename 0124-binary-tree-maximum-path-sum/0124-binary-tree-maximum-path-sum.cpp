class Solution {
public:
    int findpath(TreeNode* node, int &maxsum) {
        if (node == NULL) return 0;

        int leftsum = max(0, findpath(node->left, maxsum));
        int rightsum = max(0, findpath(node->right, maxsum));

        maxsum = max(maxsum, leftsum + rightsum + node->val);

        return node->val + max(leftsum, rightsum);
    }

    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        findpath(root, maxsum);
        return maxsum;
    }
};
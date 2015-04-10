/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root == NULL)
            return 0;
        int left_depth = minDepth(root->left);
        int right_depth = minDepth(root->right);
        if(left_depth == 0 || right_depth == 0)
            return right_depth + left_depth + 1;
        else
            return min(left_depth, right_depth) + 1;
    }
};
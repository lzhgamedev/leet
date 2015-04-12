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
    int maxPathSum(TreeNode *root) {
        int *max_sum = NULL;
        startPathSum(root, max_sum);
        return *max_sum;
    }
    int startPathSum(TreeNode *root, int*& max_sum) {
        if(root == NULL)
            return 0;
        int left = max(startPathSum(root->left, max_sum), 0);
        int right = max(startPathSum(root->right, max_sum), 0);
        int choose = max(left, right);
        if(max_sum == NULL)
            max_sum = new int (left + right + root->val);
        else if(left + right + root->val > *max_sum)
            *max_sum = max(*max_sum, left + right + root->val);
        return root->val + choose;
    }
};
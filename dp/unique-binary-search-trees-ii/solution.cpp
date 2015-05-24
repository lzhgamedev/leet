/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> dp[n+1];
        dp[0] = vector<TreeNode*>(1, (TreeNode*)NULL);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= i; ++j) {
                for(int m = 0; m < dp[j-1].size(); ++m) {
                    for(int k = 0; k < dp[i-j].size(); ++k) {
                        TreeNode* root = new TreeNode(j);
                        copyTree(dp[j-1][m], root->left, 0);
                        copyTree(dp[i-j][k], root->right, j);
                        dp[i].push_back(root);
                    }
                }
            }
        }
        return dp[n];
    }
    void copyTree(TreeNode* origin, TreeNode* &node, int base_val) {
        if(origin == NULL)
            return;
        node = new TreeNode(origin->val+base_val);
        copyTree(origin->left, node->left, base_val);
        copyTree(origin->right, node->right, base_val);
        return;
    }
};
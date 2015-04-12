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
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> nodes;
        vector<int> result;
        TreeNode* node;
        while(root != NULL || !nodes.empty()) {
            if(root != NULL) {
                result.push_back(root->val);
                if(root->right != NULL) {
                    nodes.push(root->right);
                }
                root = root->left;
            } else {
                root = nodes.top();
                nodes.pop();
            }
        }
        return result;
    }
};
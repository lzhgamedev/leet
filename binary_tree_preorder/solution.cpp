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
        if(node == NULL)
            return result;
        nodes.push(root);
        while(!nodes.empty()) {
            node = nodes.top();
            nodes.pop();
            result.push_back(node->val);
            if(node->right != NULL)
                nodes.push(node->right);
            if(node->left != NULL)
                nodes.push(node->left);
        }
        return result;
    }
};
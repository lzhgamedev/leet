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
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> nodes;
        vector<int> result;
        while(root != NULL || !nodes.empty()) {
            if(root != NULL) {
                nodes.push(root);
                root = root->left;
            } else {
                root = nodes.top();
                if(root->right == NULL) {
                    result.push_back(root->val);
                    nodes.pop();
                    if(nodes.empty())
                        return result;
                    while(nodes.top()->right == root) {
                        result.push_back(nodes.top()->val);
                        root = nodes.top();
                        nodes.pop();
                        if(nodes.empty())
                            return result;
                    }
                    root = nodes.top();
                }
                root = root->right;
            }
        }
        return result;
    }
};
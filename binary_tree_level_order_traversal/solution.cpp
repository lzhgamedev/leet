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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        vector<int> record;
        queue<TreeNode*> nodes;
        TreeNode *node;
        int level_count = 1;
        if(root == NULL)
            return result;
        nodes.push(root);
        while(!nodes.empty()) {
            node = nodes.front();
            record.push_back(node->val);
            if(node->left != NULL) {
                nodes.push(node->left);
            }
            if(node->right != NULL) {
                nodes.push(node->right);
            }
            level_count--;
            nodes.pop();
            if(level_count == 0) {
                level_count = nodes.size();
                result.push_back(record);
                record.clear();
            }
        }
        return result;
    }
};
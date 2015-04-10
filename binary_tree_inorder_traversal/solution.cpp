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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> visit;
        set<TreeNode*> visited;
        if(root == NULL)
            return result;
        visit.push(root);
        while(!visit.empty()) {
            TreeNode* node = visit.top();
            if(visited.find(node) == visited.end()) {
                visited.insert(node);
                if(node->left != NULL)
                    visit.push(node->left);
            } else {
                result.push_back(node->val);
                visit.pop();
                if(node->right != NULL)
                    visit.push(node->right);
            }
        }
        return result;
    }
};
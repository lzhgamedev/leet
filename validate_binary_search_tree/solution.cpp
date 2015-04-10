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
    bool isValidBST(TreeNode *root) {
        stack<TreeNode*> nodes;
        int *last_val = NULL;
        while(root != NULL || !nodes.empty()) {
            if(root != NULL) {
                nodes.push(root);
                root = root->left;
            } else {
                root = nodes.top();
                if(last_val != NULL && root->val <= *last_val) 
                    return false;
                else
                    last_val = &root->val;
                nodes.pop();
                root = root->right;
            }
        }
        return true;
    }
};
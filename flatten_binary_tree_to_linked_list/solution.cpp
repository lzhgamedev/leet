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
    void flatten(TreeNode *root) {
        stack<TreeNode*> nodes;
        TreeNode* node;
        if(root == NULL)
            return;
        nodes.push(root);
        while(!nodes.empty()) {
            node = nodes.top();
            nodes.pop();
            if(node->right != NULL)
                nodes.push(node->right);
            if(node->left != NULL) {
                nodes.push(node->left);
                node->right = node->left;
                node->left = NULL;
            } else {
                if(!nodes.empty())  
                    node->right = nodes.top();
                else
                    return;
            }
            
        }
    }
};
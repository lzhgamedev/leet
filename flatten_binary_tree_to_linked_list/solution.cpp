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
        TreeNode *node_right_pre, *node_right_cur;
        if(root == NULL)
            return;
        node_right_pre = root->right;
        while(root->left != NULL || root->right != NULL || node_right_pre != NULL) {
            if(root->right != NULL && node_right_pre != root->right) {
                node_right_cur = root->right;
                while(node_right_cur->right != NULL) {
                    node_right_cur = node_right_cur->right;
                }
                node_right_cur->right = node_right_pre;
                node_right_pre = root->right;
            }
            if(root->left != NULL) {
                root->right = root->left;
                root->left = NULL;
                root = root->right;
            } else if(node_right_pre != NULL){
                root->right = node_right_pre;
                root = node_right_pre;
                node_right_pre = root->right;
            }
        }
    }
};
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
        if(root == NULL || root->left == NULL && root->right == NULL)
            return true;
        int* last_val = NULL;
        return inorder_check(root, last_val);
    }
    bool inorder_check(TreeNode *root, int* &last_val) {
        if(root == NULL)
            return true;
        bool b_left = inorder_check(root->left, last_val);
        bool b_mid;
        if(last_val == NULL) {
            b_mid = true;
            last_val = &(root->val);
        } else {
            b_mid = root->val > *last_val;
            last_val = &(root->val);
        }
        bool b_right = inorder_check(root->right, last_val);
        return b_left && b_mid && b_right;
    }
};
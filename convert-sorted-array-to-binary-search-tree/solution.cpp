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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return helper(num, 0, num.size() - 1);
    }
    TreeNode *helper(vector<int> &num, int begin, int end) {
        if(begin > end)
            return NULL;
        int mid = (begin + end) / 2;
        TreeNode* root = new TreeNode(num[mid]);
        root->left = helper(num, begin, mid - 1);
        root->right = helper(num, mid + 1, end);
        return root;
    }
};
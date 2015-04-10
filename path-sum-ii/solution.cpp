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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> path_num;
        helper(root, sum, path_num, result);
        return result;
    }
    void helper(TreeNode *root, int sum, vector<int> &path_num, vector<vector<int> > &result) {
        if(root == NULL)
            return;
        path_num.push_back(root->val);
        if(root->left == NULL && root->right == NULL && sum == root->val) {
            result.push_back(path_num);
            path_num.pop_back();
            return;
        }
        helper(root->left, sum - root->val, path_num, result);
        helper(root->right, sum - root->val, path_num, result);
        path_num.pop_back();
    }
};
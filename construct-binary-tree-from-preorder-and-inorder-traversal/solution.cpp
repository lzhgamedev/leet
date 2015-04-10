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
    map<int, int> map_inorder;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size() == 0)
            return NULL;
        for(int i = 0; i < inorder.size(); ++i) {
            map_inorder[inorder[i]] = i;
        }
        return helper(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode *helper(vector<int> &preorder, int begin_1, int end_1, int begin_2, int end_2) {
        if(begin_1 > end_1 || begin_2 > end_2)
            return NULL;
        TreeNode* root = new TreeNode(preorder[begin_1]);
        int mid = map_inorder[preorder[begin_1]];
        int diff = mid - begin_2 - 1;
        root->left = helper(preorder, begin_1 + 1, begin_1 + 1 + diff, begin_2, mid - 1);
        root->right = helper(preorder, begin_1 + 2 + diff, end_1, mid + 1, end_2);
        return root;
    }
};
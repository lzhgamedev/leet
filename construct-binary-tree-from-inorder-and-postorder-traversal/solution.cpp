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
    map<int, int> map_in;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0)
            return NULL;
        for(int i = 0; i < inorder.size(); ++i) {
            map_in[inorder[i]] = i;
        }
        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int begin, int end, int begin_2, int end_2) {
        if(begin > end || begin_2 > end_2)
            return NULL;
        int root_val = postorder[end_2];
        TreeNode* root = new TreeNode(root_val);
        int mid = map_in[root_val];
        int diff =  mid - begin - 1;
        root->left = helper(inorder, postorder, begin, mid - 1, begin_2, begin_2 + diff);
        root->right = helper(postorder, postorder, mid + 1, end, begin_2 + diff + 1, end_2 - 1);
        return root;
    }
};
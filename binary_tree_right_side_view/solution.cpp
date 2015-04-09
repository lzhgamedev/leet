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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        vector<TreeNode*> record;
        int index_1 = 0, index_2 = 1;
        if(root == NULL)
            return result;
        record.push_back(root);
        while(index_1 != record.size()) {
            TreeNode* node = record.at(index_1);
            if(node->left != NULL)
                record.push_back(node->left);
            if(node->right != NULL)
                record.push_back(node->right);
            index_1 ++;
            if(index_1 == index_2) {
                result.push_back(node->val);
                index_2 = record.size();
            }
        }
        return result;
    }
};
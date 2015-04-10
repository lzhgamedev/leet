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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        vector<TreeNode*> queue;
        int index_1 = 0, index_2 = 1;
        if(root == NULL)
            return result;
        queue.push_back(root);
        while(index_1 != queue.size()) {
            vector<int> record;
            while(index_1 != index_2) {
                record.push_back(queue.at(index_1)->val);
                if(queue.at(index_1)->left != NULL) {
                    queue.push_back(queue.at(index_1)->left);
                }
                if(queue.at(index_1)->right != NULL) {
                    queue.push_back(queue.at(index_1)->right);
                }
                index_1 ++;
            }
            index_2 = queue.size();
            result.push_back(record);
        }
        return result;
    }
};
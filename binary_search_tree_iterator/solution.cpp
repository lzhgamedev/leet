/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> nodes;
    BSTIterator(TreeNode *root) {
        while(root != NULL) {
            nodes.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(!nodes.empty())
            return true;
        else
            return false;
    }

    /** @return the next smallest number */
    int next() {
        int result;
        TreeNode* node = nodes.top();
        nodes.pop();
        result = node->val;
        if(node->right != NULL) {
            node = node->right;
            nodes.push(node);
            while(node->left != NULL) {
                nodes.push(node->left);
                node = node->left;
            }
        }
        return result;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
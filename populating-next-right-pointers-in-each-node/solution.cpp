/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *node, *header;
        if(root == NULL)
            return;
        while(root->left != NULL) {
            header = root;
            node = root->left;
            while(root != NULL) {
                node->next = root->right;
                node = node->next;
                if(root->next == NULL)
                    break;
                root = root->next;
                node->next = root->left;
                node = node->next;
            }
            root = header->left;
        }
    }
};
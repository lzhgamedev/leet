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
        while(root->left != NULL || root->right != NULL || root->next != NULL) {
            while(root != NULL) {
                if(root->left != NULL) {
                    header = root->left;
                    break;
                }
                if(root->right != NULL) {
                    header = root->right;
                    break;
                }
                if(root->next == NULL)
                    break;
                root = root->next;
            }
            if(header == NULL)
                break;
            node = header;
            while(root != NULL) {
                if(root->right != NULL) {
                    if(root->right != header) {
                        node->next = root->right;
                        node = node->next;
                    }
                }
                if(root->next == NULL)
                    break;
                root = root->next;
                if(root->left != NULL) {
                    node->next = root->left;
                    node = node->next;
                }
            }
            root = header;
            header = NULL;
        }
    }
};
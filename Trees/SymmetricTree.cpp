class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->right = left;
        root->left = right;
        return root;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) {
            return (p == q);
        }
        return (p->val == q->val) && isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true; // An empty tree is symmetric
        TreeNode* invertedTree = invertTree(copyTree(root));
        return isSameTree(root, invertedTree);
        // invertTree(root->right);
        // return isSameTree(root->left, root->right);
    }

private:
    // Helper function to create a deep copy of the tree
    TreeNode* copyTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        TreeNode* newNode = new TreeNode(root->val);
        newNode->left = copyTree(root->left);
        newNode->right = copyTree(root->right);
        return newNode;
    }
};

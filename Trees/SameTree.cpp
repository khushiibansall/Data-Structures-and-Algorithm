class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL) {
            return false;
        }
        if (p->val != q->val)
            return false;
        bool checkLeft = isSameTree(p->left, q->left);
        bool checkRight = isSameTree(p->right, q->right);
        if (checkLeft && checkRight)
            return true;
        else
            return false;
    }
};

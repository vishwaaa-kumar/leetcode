/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    void inorder(TreeNode* root) {
        if (!root)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* balance(int l, int r) {
        if (l > r)
            return NULL;
        int m = (l + r) / 2;
        TreeNode* left = balance(l, m - 1);
        TreeNode* right = balance(m + 1, r);
        return new TreeNode(v[m], left, right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return balance(0, v.size() - 1);
    }
};
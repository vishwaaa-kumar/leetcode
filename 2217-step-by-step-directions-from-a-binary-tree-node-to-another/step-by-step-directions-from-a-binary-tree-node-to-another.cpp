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
    TreeNode* lowestCommonAncestorNode(TreeNode* root, int& startValue, int&
        destValue) {
            if (!root || root->val == startValue || root->val == destValue)
                return root;
            TreeNode* left = lowestCommonAncestorNode(root->left,
                startValue, destValue);
            TreeNode* right = lowestCommonAncestorNode(root->right,
                startValue, destValue);
            if (!left)
                return right;
            if (!right)
                return left;
            return root;
    }

    bool dfs(TreeNode* root, int x, string& path, bool r = 0) {
        if (!root)
            return 0;
        if (root->val == x)
            return 1;
        path += (r ? 'U' : 'L');
        if (dfs(root->left, x, path, r))
            return 1;
        path.pop_back();
        path += (r ? 'U' : 'R');
        if (dfs(root->right, x, path, r))
            return 1;
        path.pop_back();
        return 0;
    }

    /* string findPath(TreeNode* root, int& value, string s) {
        if (!root)
            return "";
        if (root->val == value)
            return s;
        string left = findPath(root->left, value, s + "U");
        string right = findPath(root->right, value, s + "U");
        if (left == "" && right != "")
            return right;
        if (right == "" && left != "")
            return left;
        return left.size() < right.size() ? left : right;
    }
    string findPath2(TreeNode* root, int& value, string s) {
        if (!root)
            return "";
        if (root->val == value)
            return s;
        string left = findPath2(root->left, value, s + "L");
        string right = findPath2(root->right, value, s + "R");
        if (left == "" && right != "")
            return right;
        if (right == "" && left != "")
            return left;
        return left.size() < right.size() ? left : right;
    } */
    string getDirections(TreeNode* root, int startValue, int destValue) {
        root = lowestCommonAncestorNode(root, 
            startValue, destValue);
        string lefty = "";
        dfs(root, startValue, lefty, 1);
        string righty = "";
        dfs(root, destValue, righty, 0);
        return lefty + righty;
    }
};
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> hasParent;
        int n = descriptions.size();
        for (int i = 0; i < n; i++) {
            if (mp.find(descriptions[i][0]) == mp.end())
                mp[descriptions[i][0]] = new TreeNode(descriptions[i][0]);
            if (mp.find(descriptions[i][1]) == mp.end())
                mp[descriptions[i][1]] = new TreeNode(descriptions[i][1]);
            hasParent.insert(descriptions[i][1]);
        }
        TreeNode* root;
        for (int i = 0; i < n; i++) {
            // left
            if (descriptions[i][2] == 1)
                mp[descriptions[i][0]]->left = mp[descriptions[i][1]];
            // right
            else
                mp[descriptions[i][0]]->right = mp[descriptions[i][1]];
            // to find the overall root, which will not have a parent
            if (hasParent.find(descriptions[i][0]) == hasParent.end())
                root = mp[descriptions[i][0]];
        }
        return root;
    }
};
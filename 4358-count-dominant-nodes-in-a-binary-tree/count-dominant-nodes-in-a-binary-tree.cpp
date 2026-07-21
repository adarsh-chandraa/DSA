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
    int cnt = 0;

    int solve(TreeNode* root) {
        if (root == nullptr)
            return INT_MIN;

        int left = solve(root->left);
        int right= solve(root->right);

        int maxi= max(root->val, max(left, right));

        if (root->val == maxi)
            cnt++;

        return maxi;
    }

    int countDominantNodes(TreeNode* root) {
        solve(root);
        return cnt;
    }
};
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
    int ans = 0;

    pair<int,int> solve(TreeNode* root) {
        if(root == NULL)
            return {0, 0};
        // sum aur cnt rkh rha hai 
        pair<int,int> l = solve(root->left);
        pair<int,int> r = solve(root->right);

        int sum = root->val + l.first + r.first;
        int cnt = 1 + l.second + r.second;

        if(sum / cnt == root->val)
            ans++;

        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};
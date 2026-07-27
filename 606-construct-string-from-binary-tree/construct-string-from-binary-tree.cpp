class Solution {
public:
    string ans;

    void solve(TreeNode* root) {
        if (root == NULL) return;

        ans += to_string(root->val);

        if (root->left || root->right) {
            ans += '(';
            solve(root->left);
            ans += ')';
        }

        if (root->right) {
            ans += '(';
            solve(root->right);
            ans += ')';
        }
    }

    string tree2str(TreeNode* root) {
        solve(root);
        return ans;
    }
};
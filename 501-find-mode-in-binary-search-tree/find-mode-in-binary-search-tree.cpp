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
  unordered_map<int,int>mp;
   void solve(TreeNode*root){
    if(root==NULL) return ;
    mp[root->val] ++;
    solve(root->left);
    solve(root->right);
   }
    vector<int> findMode(TreeNode* root) {
        solve(root);
        int mx = 0;
        for (auto &p : mp)
            mx = max(mx, p.second);

        vector<int> ans;
        for (auto &p : mp) {
            if (p.second == mx)
                ans.push_back(p.first);
        }
return ans;


    }
};
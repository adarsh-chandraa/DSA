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
       vector<int>ans;
    int  solve(TreeNode*root){
        if(root==NULL) return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        ans.push_back(abs(l-r));
        return l+r+root->val;
        
    }
    int findTilt(TreeNode* root) {
        solve(root);
        int sum = 0;
        for(int i = 0;i<ans.size();i++){
            sum = sum +ans[i];
        }
        return sum ;
    }
};
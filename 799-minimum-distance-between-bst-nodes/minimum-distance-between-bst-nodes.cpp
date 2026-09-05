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
    void solve1(TreeNode*root,int &mini,int &smini){
        if(root==NULL)return ;
        if(mini > root->val){
            smini = mini;
            mini = root->val;
        }
        else if(smini > mini && smini > root->val){
            smini = root->val;
        }
        solve1(root->left,mini,smini);
        solve1(root->right,mini,smini);

    }
    int par = -1;
    int ans = INT_MAX;
    void solve(TreeNode*root){
         if(root == NULL) return;
         
         solve(root->left);
         if(par!=-1) {
             ans = min(ans,abs(par-root->val));
         }
         par = root->val;
         solve(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        int mini = INT_MAX;
        int smini = INT_MAX;
        //int ans = 1e9;
        solve(root);
        return ans;
        // solve1(root,mini,smini);
        // return smini - mini;
    }
};
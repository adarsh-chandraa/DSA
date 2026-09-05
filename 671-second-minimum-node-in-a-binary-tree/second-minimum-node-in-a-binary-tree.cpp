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
   void solve(TreeNode*root,long long &mini,long long &smini){
    if(root==NULL) return ;
    if(mini > root->val ){
        smini = mini;
        mini = root->val;
    }
    else if(smini>root->val && mini!= root->val){
        smini = root->val;
    }
    solve(root->left,mini,smini);
    solve(root->right,mini,smini);
   }
    int findSecondMinimumValue(TreeNode* root) {
        long long mini = LONG_MAX;
        long long smini = LONG_MAX;
        solve(root,mini,smini);
        if(smini == LONG_MAX) return -1;
         return smini;
    }
};
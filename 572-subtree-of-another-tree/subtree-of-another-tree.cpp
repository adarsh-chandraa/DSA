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
    bool solve(TreeNode*root,TreeNode*subroot){
        if(root== NULL && subroot==NULL) return true;
        else if((root==NULL && subroot!=NULL )||(root!=NULL && subroot==NULL)) return false;
        return root->val == subroot->val &&
            
            solve(root->left,subroot->left) && solve(root->right,subroot->right);
            
        
       // return solve(root->left,subroot) || solve(root->right,subroot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(!root) return false;
       if( solve(root,subroot))return true;

        return isSubtree(root->left,subroot)|| isSubtree(root->right,subroot);
    }
};
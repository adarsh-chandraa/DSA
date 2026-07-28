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
   void solve(TreeNode*root,int val,int d,int l){
    if(root==NULL) return ;
    if(d-1==l){
        TreeNode* temp1 = new TreeNode(val);
          TreeNode* temp2 = new TreeNode(val);
        
            temp1->left = root->left;
            root->left = temp1;
        
    
            temp2->right = root->right;
            root->right = temp2;
        
        return;
    }
      
        solve(root->left,val,d,l+1);
        solve(root->right,val,d,l+1);



   }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* temp = new TreeNode(val);
            temp->left = root; 
            return temp;
        }
        int level = 1;
         solve(root,val,depth,level);
         return root;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode*bst(vector<int>nums ,int s,int e){
        if(s>e) return NULL;
        int mid = (s+e)/2;
        TreeNode* temp = new TreeNode(nums[mid]);
        temp->left = bst(nums,s,mid-1);
        temp->right = bst(nums,mid+1,e);
        return temp;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>ans;
        if(head==NULL) return NULL;
        ListNode* temp = head;
        while (temp!= NULL) {
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int s=0;
        int e= ans.size()-1;
        return bst(ans,s,e);
    }
};
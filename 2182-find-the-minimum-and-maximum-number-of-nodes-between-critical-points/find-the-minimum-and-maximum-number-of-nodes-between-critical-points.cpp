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
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode*prev = head;
        ListNode*curr = head;
        //ListNode*fast = head;
        int cnt = 1;
        vector<int>ans;
        while(curr->next!=NULL){
            if((curr->val > prev->val && curr->val > curr->next->val) ||
               (curr->val < prev->val && curr->val < curr->next->val)) {

                ans.push_back(cnt);
            }
            prev = curr;
            curr = curr ->next;
           cnt++;
             
        }
        if(ans.size()<2) return {-1,-1};
          sort(ans.begin(),ans.end());
          int maxi = ans.back() - ans.front();
          int mini = 1e9;
          for(int i = 1;i<ans.size();i++){
            mini = min(mini,ans[i]-ans[i-1]);
          }
        
        return {mini,maxi};
    }
};
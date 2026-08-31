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
        ListNode*prev = NULL;
        ListNode*curr = head;
        ListNode*fast = head;
        int cnt = 1;
        vector<int>ans;
        while(fast->next){
            fast = curr->next;
            if(prev ==NULL){
                prev = curr;
                curr = fast;
                continue;
            }
            else if((curr->val > prev->val && curr->val > fast->val) ||
               (curr->val < prev->val && curr->val < fast->val)) {

                ans.push_back(cnt);
            }
            prev = curr;
            curr = fast;
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
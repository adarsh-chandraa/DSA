#include<bits/stdc++.h>
class Solution {
public:
    int mins(vector<int>& arr, vector<int>& ans) {
        int n = arr.size();
        vector<pair<pair<int, int>, int>>temp;
        for (int i = 0; i < n; ++i){
            temp.push_back({{ans[i], arr[i]}, i});
        }
        sort(temp.begin(), temp.end()); 
        vector<bool> visited(n, false); 
        int swap = 0; 
        for (int i = 0; i < n; ++i) {
            if (visited[i] || temp[i].second == i) continue; 
            int cycle = 0; 
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = temp[j].second;
                cycle++;
            }
            if (cycle > 1)
                swap += (cycle - 1);
        }
        return swap;
    }
    int minSwaps(vector<int>& nums) {
        vector<int>ans;
        for(int i = 0;i<nums.size();i++){
            int sum = 0;
            int x = nums[i];
            while(x>0){
                int rem = x%10;
                sum = sum+ rem;
                x = x/10;
            }
            ans.push_back(sum);
        }
       
        return mins(nums,ans);
    }
};
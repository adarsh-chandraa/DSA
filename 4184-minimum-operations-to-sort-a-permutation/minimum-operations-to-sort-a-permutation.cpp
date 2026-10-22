class Solution {
public:
    int solve(vector<int>nums){
        int n = nums.size();
        // int ans = -1;
        for(int i = 0;i<n;i++){
            bool ok = true;
            for(int j = 0;j<n;j++){
                if(nums[(i+j)%n]!=j){
                    ok = false;
                    break;
                }
            }
            if(ok) return i;
        }
        return 1e9;
    }
    int minOperations(vector<int>& nums) {
        // int ans = solve(nums);
        // reverse(nums.begin(),nums.end());
        // int ans2 = solve(nums);

        // if(ans2 != 1e9) ans = min(ans,ans2+1);
        // if(ans ==1e9) return -1;
        // return ans;
        
        // // if(ans2 != -1) ans2 ++;
        // // if(ans == -1 && ans2 == -1 ) return -1;
        // // if(ans == -1) return ans2;
        // // if(ans2 == -1) return ans;
        // // return min(ans,ans2);

        int n = nums.size();
        int s  = find(nums.begin(),nums.end(),0) - nums.begin();
        bool asc = true;
        bool desc = true;
         for (int i = 1; i < n; i++) {
             int value = nums[(s + i) % n];

            if (value != i) {
                asc = false;
            }
            if (value != n - i) {
                desc = false;
            }

            if (!asc && !desc) {
                return -1;
            }
        }

        if (asc) {
            return min(s, n - s + 2);
        }

        return min(n - s, s + 2);
    }
};
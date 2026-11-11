class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = LLONG_MAX;
        // for(int i = 0;i<=min(need1,need2);i++){
        //     long long rem = max(0,need1-i);
        //     long long rem2 = max(0,need2-i);
        //     long long total = 1LL*i*costBoth + 1LL*rem*cost1 + 1LL*rem2*cost2;
        //     ans = min(ans,total);
        // }
        //int mini = max(need1,need2);
        long long rem1 = max(0,need1-0);
        long long rem2 = max(0,need2-0);
        long long total = 1LL*0*costBoth + 1LL*rem1*cost1 + 1LL*rem2*cost2;
        ans = min(ans,total);
        
        int mini = min(need1,need2);
        long long rem3 = max(0,need1-mini);
        long long rem4 = max(0,need2-mini);
        long long total1 = 1LL*mini*costBoth + 1LL*rem3*cost1 + 1LL*rem4*cost2;
        ans = min(ans,total1);
        
        int i = max(need1,need2);
        long long rem5 = max(0,need1-i);
        long long rem6 = max(0,need2-i);
        long long total2 = 1LL*i*costBoth + 1LL*rem5*cost1 + 1LL*rem6*cost2;
        ans = min(ans,total2);
        return ans;
    }
};
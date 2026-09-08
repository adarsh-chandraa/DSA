class Solution {
public:
    int countCommas(int n) {
        long long ans = 0;
        long long v = 1000;
        while(v <= n){
            ans = ans + n-v+1;
            v = v*1000;
        }
        return ans;
    }
};
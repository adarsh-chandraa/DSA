class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = 0;
        int maxi = 0;
        for(int i = 1;i<nums.size();i++){
            if(nums[mini]>nums[i]) mini = i;
            else if(nums[maxi]<nums[i])maxi = i;
        }
        if(mini == maxi ) return 1;
        int ldel = max(mini+1,maxi+1);
        int rdel = max(n-mini,n-maxi);
        mini = min(mini+1,n-mini);
        maxi = min(maxi+1,n-maxi);
        int mindel = min(ldel,min(rdel,mini+maxi));
        return mindel;

    }
};
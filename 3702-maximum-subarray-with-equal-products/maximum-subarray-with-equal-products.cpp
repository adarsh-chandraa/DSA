class Solution {
public:
    int maxLength(vector<int>& nums) {
        int res = 1;

        for (int i = 0; i < nums.size(); i++) {
            __int128 prodVal = nums[i];
            long long gcdVal = nums[i];
            long long lcmVal = nums[i];

            for (int j = i + 1; j < nums.size(); j++) {
                prodVal *= nums[j];

                gcdVal = gcd(gcdVal, (long long)nums[j]);
                lcmVal = lcm(lcmVal, (long long)nums[j]);

                if (prodVal > (__int128)gcdVal * lcmVal)
                    break;

                if (prodVal == (__int128)gcdVal * lcmVal)
                    res = max(res, j - i + 1);
            }
        }

        return res;
    }
};
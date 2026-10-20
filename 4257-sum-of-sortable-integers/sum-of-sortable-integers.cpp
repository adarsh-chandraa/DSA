// class Solution {
// public:
//     int sortableIntegers(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>temp = nums;
//         sort(temp.begin(),temp.end());

//         long long ans = 0;
//         vector<int>div;
//         map<int,int>pos;
//         for(int i = 0;i<n;i++){
//             pos[temp[i]] = i;
//         }
//         // for(int i = 1;i*i<=n;i++){
//         //     if(n%i == 0){
//         //         div.push_back(i);
//         //         if(i!=n/i) div.push_back(n/i);
//         //     }
//         // }
//         // sort(div.begin(),div.end());
//         // for(int k:div){
//         //     bool flag = true;
//         //     for(int i= 0;i<n;i +=k){
//         //         // multiset<int>s1,s2;
//         //         // set<int>s1;
//         //         // set<int>s2;
//         //         vector<int>s1;
//         //         vector<int>s2;
//         //         for(int j = i;j < i+k;j++){
//         //             s1.push_back(nums[j]);
//         //             s2.push_back(temp[j]);
//         //         }
//         //         sort(s1.begin(),s1.end());
//         //         sort(s2.begin(),s2.end());
//         //         if(s1!=s2){
//         //             flag = false;
//         //             break;
//         //         }
//         //     }
//         //     if(flag) ans = ans + k;
            
//         for(int k = 1;k<=n;k++){
//             if(n%k !=0) continue;
//             bool flag = 1;

//             for(int i = 0;i<n;i +=k){
//                 int cnt = 0;
//                 for(int j = i;j<i+k-1;j++){
//                     if(nums[j]<nums[j+1])cnt++;
//                 }
//                 if(nums[i+k-1]>nums[i])cnt++;
//                 if(cnt == 0){
//                     flag = 0;
//                     break;
//                 }
//                 // int c = pos[nums[i]];
//                 // if((i/k)!= c/k){
//                 //     flag = 0;
//                 //     break;
//                 // }
//             }
//             if(flag) ans = ans +k;
//         }
//         return ans-1;
//     }
// };

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> fac;

        for (int x = 1; x * x <= n; ++x) {
            if (n % x == 0) {
                fac.push_back(x);
                if (n / x != x) {
                    fac.push_back(n / x);
                }
            }
        }

        vector<int> target = nums;
        ranges::sort(target);

        // Check whether cyclic rotations of nums1 can produce nums2
        auto check = [](const vector<int>& nums1, const vector<int>& nums2) {
            int L = nums1.size();

            for (int i = 0; i < L - 1; ++i) {
                if (nums1[i] > nums1[i + 1]) {
                    vector<int> rotated;
                    rotated.insert(rotated.end(), nums1.begin() + i + 1,
                                   nums1.end());
                    rotated.insert(rotated.end(), nums1.begin(),
                                   nums1.begin() + i + 1);
                    return rotated == nums2;
                }
            }

            return nums1 == nums2;
        };

        int ans = 0;

        for (int d : fac) {
            bool allGood = true;
            for (int left = 0; left < n; left += d) {
                int right = left + d - 1;

                vector<int> sub1(nums.begin() + left, nums.begin() + right + 1);
                vector<int> sub2(target.begin() + left,
                                 target.begin() + right + 1);

                if (!check(sub1, sub2)) {
                    allGood = false;
                    break;
                }
            }
            if (allGood) {
                ans += d;
            }
        }

        return ans;
    }
};
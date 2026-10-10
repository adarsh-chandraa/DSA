
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff;
        for(int i = 0; i < nums1.size(); i++){
            diff.push_back(abs(nums1[i] - nums2[i]));
        }

        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mp;

        for(int i = 0; i < diff.size(); i++){
            mp[diff[i]]++;
        }

        for(auto &it : mp){
            pq.push({it.first, it.second});
        }

        long long k = 1LL * k1 + k2;

        while(k > 0 && !pq.empty()){
            auto it = pq.top();
            int d = it.first;
            int freq = it.second;
            pq.pop();

            if(d == 0) break;
            if(mp[d] != freq) continue;

            if(freq >= k){
                mp[d] -= k;
                mp[d-1] += k;
                k = 0;
                break;
            }
            else{
                mp[d] -= freq;
                mp[d-1] += freq;
                k -= freq;

                pq.push({d-1, mp[d-1]});
            }
        }

        long long ans = 0;

        for(auto &it : mp){
            long long d = it.first;
            long long freq = it.second;
            ans += d * d * freq;
        }

        return ans;
    }
};

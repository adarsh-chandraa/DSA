class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = *min_element(nums1.begin(),nums1.end());
        if(mini%2 != 0) return true;
        // minimum odd hoga toh sara odd bna denge
        //agar even hua toh sara element even hona chahiye kyu ki  
        // even agar sabse chota hoga togh odd nhi bna skte h sare kro agar rest element odd bhi hua toh bhi 7 9 5 2 ----> false 2- something will give -ve
        for(auto &it:nums1){
            if(it%2 !=0) return false;
        }
        return true;
    }
};
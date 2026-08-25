class Solution {
public:
    void solve(vector<int>& arr,int tar,vector<vector<int>>&ans,vector<int>&temp,int i,int sum){
        if(i>arr.size()) return ;
        if(tar == sum) {
            cout<<"->"<<sum;
            ans.push_back(temp);
            return;
        }
         if(sum > tar) return;
        for(int j= i;j<arr.size();j++){
            if(j>i && arr[j]==arr[j-1]) continue;
            sum = sum + arr[j];
           
            temp.push_back(arr[j]);
           // cout<<"->"<<sum;
            solve(arr,tar,ans,temp,j,sum);
            sum = sum - arr[j];
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int sum = 0;
        sort(cand.begin(),cand.end());
        solve(cand,target,ans,temp,0,sum);
        return ans;
    }
};
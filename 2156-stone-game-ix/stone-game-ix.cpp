class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for(auto &it:stones){
            if(int v= it%3; v==0)cnt0++;
            else if(v==1)cnt1++;
            else cnt2++;
        }
        //if(cnt1 == 0 || cnt2==0) return false;
        if(cnt0 %2 ==0) return cnt1>=1 && cnt2>=1;
        return abs(cnt1-cnt2)>2;
    }
};
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int x = 9*num;
        if(sum > x) return "";
        // int res = 0;
        string ans ;
        ans.reserve(num);
        for(int i = 0;i<num;i++){
            int v = min(sum,9);
            //res = res + pow(v,2);
            ans.push_back('0'+v);
           
            sum = sum - v;
        }
        if(sum >0) return "";
        //string m = to_string(res);
        return ans;
    }
};
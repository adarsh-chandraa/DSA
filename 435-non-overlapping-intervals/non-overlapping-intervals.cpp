class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                //if(a[1]==b[1]) return a[0]<b[0];
                 return a[1] < b[1];
             });
        for(auto &it:intervals){
            cout<<it[0]<<" "<<it[1]<<"\n";
        }
        int count = 0;
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < end) {
                count++;
            } 
            else {

                end = intervals[i][1];
            }
        }

        return count;
    }
};

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map<string,int>mp;
        while(n){
            string state ;
            for(auto &it:cells){
                state += char('0'+it);
            }
            if(mp.count(state)){
                int cycle = mp[state]-n;
                n = n%cycle;
            }
            mp[state] = n;
            if(n>0){
                vector<int>temp(8,0);
                for(int i = 1;i<7;i++){
                    temp[i] =(cells[i-1] == cells[i+1]);
                }
                cells = temp;
                n--;
            }
            
        }
        return cells;
    }
};
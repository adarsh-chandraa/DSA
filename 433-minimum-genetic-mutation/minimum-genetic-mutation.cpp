class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>st(bank.begin(),bank.end());
        queue<pair<string,int>>q;
        q.push({startGene,0});
         char d[4] = {'A','C','G','T'};
         while(!q.empty()){
            string v = q.front().first;
            int steps = q.front().second;
            cout<<steps;
            q.pop();
            if(v == endGene) return steps;
            for(int i = 0;i<v.size();i++){
                char c = v[i];
                for(int j = 0;j<4;j++){
                    v[i] = d[j];
                    if(st.find(v)!=st.end()){
                        q.push({v,steps+1});
                        st.erase(v);
                        cout<<steps;
                    }
                }
                v[i] = c;
            }
         }
         return -1;
    }
};
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st;
        for(auto it:wordList)st.insert(it);
        if(st.find(endWord)==st.end()) return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            string s = it.first;
            for(int i = 0;i<s.size();i++){
                for(int j = 0;j<26;j++){
                    s[i]=j+'a';
                    if(s==endWord) return it.second+1;
                    if(st.find(s)!=st.end()){
                        int cnt = it.second;
                        q.push({s,cnt+1});
                         st.erase(s);
                    }
                    s=it.first;
                }
            }
        }
        return 0;
    }
};
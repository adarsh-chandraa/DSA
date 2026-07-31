// class Solution {
//  public:
//      vector<vector<string>> findLadders(string beginWord, string endWord,
//                                         vector<string>& wordList) {
//          vector<vector<string>> ans; // ans store krega

//         vector<string> used; // track krega konsa used ho gya hai taki
//         dubra
//                              // same nhi bn pae like bat -> cat -> bat
//                              aisa nhi
//                              // ho isiliye used wale mein rkhenge aur
//                              level
//                              // chnge hone pr usko set se remove kr denge

//         unordered_set<string> st(wordList.begin(),
//                                  wordList.end()); // set taki easily khoj
//                                  pae

//         queue<vector<string>> q; // to store the sequence
//         q.push({beginWord});
//         used.push_back(beginWord); // first push
//         int level = 0;
//         while (!q.empty()) {

//             vector<string> vec = q.front();
//             q.pop();

//             if (vec.size() > level) {
//                 level++;
//                 for (auto& it : used) {
//                     st.erase(it);
//                 }
//                 used.clear();
//             }

//             string s = vec.back();
//             if (s == endWord) {
//                 if (ans.size() == 0)
//                     ans.push_back(vec);
//                 else if (ans[0].size() == vec.size())
//                     ans.push_back(vec);
//             }

//             for (int i = 0; i < s.size(); i++) {
//                 char original = s[i];
//                 for (char c = 'a'; c <= 'z'; c++) {
//                     s[i] = c;

//                     if (st.count(s) > 0) {
//                         vec.push_back(s);
//                         q.push(vec);
//                         used.push_back(s);
//                         vec.pop_back();
//                     }
//                     s[i] = original;
//                 }
//             }
//         }
//         return ans;
//     }
// };
class Solution {
    unordered_map<string, int> mp;
    string b;
    vector<vector<string>> ans;

    void dfs(string s, vector<string>& seq) { 
        if (s == b) {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
        }
        int steps = mp[s];
        for(int i = 0;i<s.size();i++){
           char temp =s[i];
        for(char ch = 'a';ch<='z';ch++){
            s[i] = ch;
            if(mp.find(s)!=mp.end() && mp[s]+1==steps){
                seq.push_back(s);
                dfs(s,seq);
                seq.pop_back();
            }
        }
          
           s[i] = temp;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
         b = beginWord;
        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 1;
        int sz = beginWord.size();
        while (!q.empty()) {
            string temp = q.front();
            int steps = mp[temp];
            q.pop();
            if(temp ==endWord) break;
            for (int i = 0; i < sz; i++) {
                char o = temp[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;
                    if (st.count(temp) > 0) {
                        q.push(temp);
                        if(mp.find(temp)==mp.end())mp[temp] = steps + 1;
                        st.erase(temp);
                    }
                }
                temp[i] = o;
            }
        }
        if (mp[endWord]) {

            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};
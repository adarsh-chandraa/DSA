class Solution {
public:
    int cnt = 0;
    set<string>ans;
    
    void solve(int idx,int n,string &s,int l,int r,string temp,int lo,int lc){
        if(idx>=n ){
            if(lo==0 && lc==0 && l==r){
                ans.insert(temp);   
                cout<<temp<<"\n";
            }
            return;
        }

        if(r>l) return;

        if(s[idx]=='(' ){
            if(lo>0)  solve(idx+1,n,s,l,r,temp,lo-1,lc);
            solve(idx+1,n,s,l+1,r,temp+s[idx],lo,lc);

        }
        else if(s[idx]==')'){ 
            if(lc>0)  solve(idx+1,n,s,l,r,temp,lo,lc-1);
            if(l>r)solve(idx+1,n,s,l,r+1,temp+s[idx],lo,lc);
        }
        
        else {
            solve(idx+1,n,s,l,r,temp+s[idx],lo,lc);
        }
    }

    vector<string> removeInvalidParentheses(string s) { 
        // s = "(a()" ; just for testing
        ans.clear();   
        int lo = 0;
        int lc = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='(') lo++;
            else if(s[i]==')'){
                if(lo>0) lo--;
                else lc++;
            }
        }
        solve(0,s.size(),s,0,0,"",lo,lc);
        return vector<string>(ans.begin(),ans.end());
    }
};
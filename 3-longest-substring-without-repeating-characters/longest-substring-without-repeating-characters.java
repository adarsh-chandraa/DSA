class Solution {
    public int lengthOfLongestSubstring(String s) {
        int l = 0;
        int r = 0;
        int ans = 0;
        HashMap<Character,Integer>mp = new HashMap<>();
        while(r<s.length()){
             while(mp.containsKey(s.charAt(r))){
                 mp.put( s.charAt(l), mp.get(s.charAt(l))-1) ;
                    if(mp.get(s.charAt(l))==0){
                        mp.remove(s.charAt(l));
                    }
                
                l++;
            }
            mp.put(s.charAt(r),mp.getOrDefault(s.charAt(r),0)+1);
             ans = Math.max(r-l+1,ans);
             r++;
        }
        return ans;
    }
}
class Solution {
    public int characterReplacement(String s, int k) {
        HashMap<Integer,Integer>mp = new HashMap<>();
        int l =0;
        int r = 0;
        int maxf = 0;
        int maxl = 0; 
        while(r<s.length()){
            mp.put(s.charAt(r)-'A',mp.getOrDefault(s.charAt(r)-'A',0)+1);
            maxf = Math.max(maxf,mp.get(s.charAt(r)-'A'));

            while((r-l+1)-maxf>k){
                mp.put(s.charAt(l)-'A',mp.get(s.charAt(l)-'A')-1);
                maxf = 0;
                for(int i = 0;i<26;i++){
                   if(mp.containsKey(i)) maxf = Math.max(maxf,mp.get(i));
                }
                l++;
            }
            maxl = Math.max(maxl,r-l+1);
            r++;
        }
        return maxl;
    }
}
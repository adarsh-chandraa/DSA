class Solution {
    public int numberOfSubstrings(String s) {
        int ans = 0;
        int []arr = {-1,-1,-1};
        for(int i =0;i<s.length();i++){
            arr[s.charAt(i)-'a'] = i;
            ans = ans + (1+Math.min(arr[0],Math.min(arr[1],arr[2])));
        }
        return ans;
    }
}
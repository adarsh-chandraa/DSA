class Solution {
    public String reverseWords(String s) {
        int i = s.length() - 1;
        
        StringBuilder ans = new StringBuilder();

        while(i >= 0) {
            while(i >= 0 && s.charAt(i) == ' ') {
                i--;
            }

            int end = i;

            while(i >= 0 && s.charAt(i) != ' ') {
                i--;
            }

            if(end >= 0) {
                String word = s.substring(i + 1, end + 1);

                if(ans.length() > 0) {
                    ans.append(" ");
                }

                ans.append(word);
            }
        }

        return ans.toString();
    }
}
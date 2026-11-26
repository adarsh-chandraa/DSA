class Solution {
public:
    bool canAliceWin(int n) {
        int val = 10;
        int k = 0;
        while(n>=val){
            n = n- val;
            val--;
            k++;
        }
        return k%2==1;
    }
};
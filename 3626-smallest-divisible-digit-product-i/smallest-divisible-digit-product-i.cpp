class Solution {
public:
    int smallestNumber(int n, int t) {
        int temp = n;
        while(true){
             n =temp;
             int pro = 1;
            while(n){
                int rem = n%10;
                pro *= rem;
                n /=10;
            }
            if(pro%t==0) return temp;
            temp = temp +1;
        }
        return -1;
    }
};
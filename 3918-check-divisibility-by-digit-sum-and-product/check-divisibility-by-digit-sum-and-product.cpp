class Solution {
public:
    bool checkDivisibility(int n) {
        int pro = 1;
        int sum  = 0;
        int temp = n;
        while(temp){
            int rem = temp%10;
            sum += rem;
            pro *= rem;
            temp =temp/10; 
        }
        cout<<sum<<" "<<pro;
        if(n%(pro+sum) ==0)return true;
        return false;
    }
};
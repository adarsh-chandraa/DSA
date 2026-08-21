class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int n = 0;
        while (n < bills.size()) {
            if (bills[n] < 5) {
                n++;
            }

            else if (bills[n] % 5 == 0) {

                if (bills[n] == 5)
                    five++;
                if (bills[n] == 10) {
                    if (five < 1)
                        return false;
                        ten++;
                        five--;
                }
                if (bills[n] == 20) {
                    if (five > 0 && ten > 0) {
                        ten--;
                        five--;

                    } 
                    else if (five > 2)
                        five = five - 3;
                    else
                        return false;
                }
                n++;
            }
        }
            return true;
    }
};
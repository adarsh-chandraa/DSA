class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arr[12] = {0,31,59,90,120,151,181,212,243,273,304,334};
        int sa = 0;
        int la = 0;
        int sb = 0;
        int lb = 0;
        int temp1 = 0;
        int temp2  =0;
        for(int i = 0;i<5;i++){
            if(arriveAlice[i]=='-'){
                sa = temp1;
                la = temp2;
                temp1 = 0;
                temp2 = 0;
                
            }
            else {
                temp1 = temp1*10+(arriveAlice[i]-'0');
                temp2 = temp2*10+(leaveAlice[i]-'0');
            
            }
        }
        int d1 = temp1;
        int d2 = temp2;
         temp1 = 0;
        temp2  =0;
          for(int i = 0;i<5;i++){
            if(arriveBob[i]=='-'){
                sb = temp1;
                lb = temp2;
                temp1 = 0;
                temp2 = 0;
                
            }
            else {
                temp1 = temp1*10+(arriveBob[i]-'0');
                temp2 = temp2*10+(leaveBob[i]-'0');
            
            }
        }
        int d3 = temp1;
        int d4 = temp2;
        int val1 = arr[sa-1] + d1;
        int val2 = arr[la-1] + d2;
        int val3 = arr[sb-1] + d3;
        int val4 = arr[lb-1] + d4;

        int sdate = max(val1,val3);
        int edate = min(val2,val4);
        return max(0,edate-sdate+1);


    }
};
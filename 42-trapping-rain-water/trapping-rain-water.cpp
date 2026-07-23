class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left(n);
        vector<int>right(n);
        int leftmaxi = 0;
        int rightmaxi = 0;
        
        for(int i = 0;i<height.size();i++){
            leftmaxi = max(leftmaxi,height[i]);
            left[i] = leftmaxi;
            rightmaxi = max(rightmaxi,height[n-i-1]);
            right[n-i-1] = rightmaxi;
        } 
        int watercap = 0;
          for(int i = 0;i<n;i++){
            watercap  +=  min(right[i],left[i]) -height[i];
          }
          return watercap;

     }    
};
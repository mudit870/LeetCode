class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftProd(n);
        vector<int>rightProd(n);
        int prod=1;
        int leftMax=INT_MIN,rightMax=INT_MIN;
        for(int i=0;i<n;i++){
            prod*=nums[i];
            leftProd[i]=prod;
            leftMax=max(leftMax,leftProd[i]);
            if(prod==0)
                prod=1;
        }
        prod=1;
        for(int i=n-1;i>=0;i--){
            prod*=nums[i];
            rightProd[i]=prod;
            rightMax=max(rightMax,rightProd[i]);
            if(prod==0)
                prod=1;
        }
        return max(leftMax,rightMax);
    }
};
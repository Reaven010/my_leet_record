class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size());
        int zero=0;
        int prod=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero++;
                continue;
            }
            prod*=nums[i];
        }     
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0 && zero==0){
                ans[i]=prod/nums[i];
            }
            else if(nums[i]==0 && zero==1){
                ans[i]=prod;
            }
            else if(nums[i]==0 && zero>1 ){
                ans[i]=0;
            }
        }
        return ans;
    }
};
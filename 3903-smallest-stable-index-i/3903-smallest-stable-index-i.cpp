class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        for(int i=0;i<nums.size();i++){
            int minimum=INT_MAX,maximum=INT_MIN;
            for(int j=0;j<=i;j++){
                maximum=max(nums[j],maximum);
            }
            for(int j=i;j<nums.size();j++){
                minimum=min(nums[j],minimum);
            }

            if(maximum-minimum<=k){
                return i;
            }
        }
        return -1;
    }
};
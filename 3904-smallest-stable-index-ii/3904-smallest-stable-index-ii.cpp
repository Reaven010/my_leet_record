class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>minval(nums.size());
        int minimum=INT_MAX;
        for(int i =nums.size()-1;i>=0;i--){
            minimum=min(minimum,nums[i]);
            minval[i]=minimum;
        }
        int maximum=INT_MIN;
        for(int i =0;i<nums.size();i++){
            maximum=max(maximum,nums[i]);
            if(maximum-minval[i]<=k){
                return i;
            }
        }
        return -1;

    }
};
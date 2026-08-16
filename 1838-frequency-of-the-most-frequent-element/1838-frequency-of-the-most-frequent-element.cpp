class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long start=0,end=0;
        long long sum=0;
        long long ans=1;

        while(end<nums.size()){
            sum+=nums[end];
            while(((end-start+1)*nums[end]-sum )>k){
                sum-=nums[start];
                start++;
            }
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};
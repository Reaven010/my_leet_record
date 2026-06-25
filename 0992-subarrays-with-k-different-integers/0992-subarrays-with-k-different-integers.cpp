class Solution {
public:

// atmost k

    int atmostkunique(vector<int>&nums,int k){
        unordered_map<int,int>m;
        int start=0,end=0,total=0,count=0;
        while(end<nums.size()){
            m[nums[end]]++;
            if(m[nums[end]]==1){
                count++;
            }
            while(count>=k){
                m[nums[start]]--;
                if(m[nums[start]]==0){
                    count--;
                }
                start++;
            }
            total+=end-start+1;
            end++;
        }
        return total;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostkunique(nums,k+1)-atmostkunique(nums,k);
    }
};
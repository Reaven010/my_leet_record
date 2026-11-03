class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int duplicates=0;
        int index=0;
        int i=1;
        while(i<nums.size()){
            if (nums[index]==nums[i]){
                i++;
            }
            else if(nums[index]!=nums[i]){
                index++;
                nums[index]=nums[i];
                i++;
            }
        }
        return index+1;
    }
};
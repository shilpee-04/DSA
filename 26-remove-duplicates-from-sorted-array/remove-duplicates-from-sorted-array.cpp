class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0, r=0;
        while(r<nums.size()){
            if(nums[r]>nums[l]){
                nums[l+1]=nums[r];
                l++;

            }
            r++;
        }
        return l+1;
        
    }
};
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,maxcount=0,zeroes=0;
        while(r<nums.size()){
            if(nums[r]==0) zeroes++;
            while(zeroes>k){
                if(nums[l]==0) zeroes--;
                l++;
            }
            if(zeroes<=k){
                int length=r-l+1;
                maxcount=max(length,maxcount);
            }
            r++;
        }
        return maxcount;
    }
};
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int> mpp;
        for(int i=0;i<n;i++){
            mpp.insert(nums[i]);
        }
        for(int i=1;i<=n;i++){
            if(mpp.count(i*k)){
                continue;
            }
            else{
                return i*k;
            }
        }
        if(n==1){
            return nums[0]*2;
        }
        else{
            return k*(n+1);
        } 
    }
};
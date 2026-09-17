class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp.find(nums[i]) != mp.end()){
                if(mp[nums[i]]>n/2) return nums[i];
            }
            
        }
        return -1;
    }
};
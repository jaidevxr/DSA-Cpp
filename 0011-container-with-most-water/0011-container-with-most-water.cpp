class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        int area=INT_MIN;
        while(right>=left){
            int width=right-left;
            int value = width * min(height[left], height[right]);
            area=max(area,value);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
            
        }
        return area;
    }
};
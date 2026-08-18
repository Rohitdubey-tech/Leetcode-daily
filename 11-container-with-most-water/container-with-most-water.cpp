class Solution {
public:
    int maxArea(vector<int>& height) {
        long long left = 0;
        long long right = height.size()-1;
        long long maxWater = 0;
        while(left < right){
            long long width  = right - left;
            long long minHeight = min(height[left], height[right]);
            long long area = width * minHeight;
            maxWater = max(area, maxWater);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxWater;
    }
};
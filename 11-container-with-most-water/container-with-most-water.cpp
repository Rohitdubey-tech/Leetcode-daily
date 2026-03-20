class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        long long maxWater = 0;
        while(left<right){
            long long width = right - left;
            long long currHeight = min(height[left], height[right]);
            long long area = width * currHeight;
            maxWater = max(maxWater, area);
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
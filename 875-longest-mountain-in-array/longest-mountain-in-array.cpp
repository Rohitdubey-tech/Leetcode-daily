class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n= arr.size();
        int ans = 0;
        int i=1;
        while(i < n-1){
            if(arr[i]>arr[i+1] && arr[i]>arr[i-1]){
                int left = i;
                int right = i;
                while(left >0 && arr[left]>arr[left-1]){
                    left--;
                }
                while(right<n-1 && arr[right]>arr[right+1]){
                    right++;
                }
                ans = max(ans, right-left+1);
                i=right;
            }
            i++;
        }
        return ans;
    }
};
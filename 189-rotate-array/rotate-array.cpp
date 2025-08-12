class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k=k%n;
        auto reverseRange=[&](int start, int end){
            while(start<end){
                swap(nums[start],nums[end]);
                start++;
                end--;
            }
        };
        reverseRange(0,n-1);
        reverseRange(0,k-1);
        reverseRange(k,n-1);
    }
};
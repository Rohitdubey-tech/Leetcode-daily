class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>st;
        int left = 0;
        int ans = 0;
        int sum = 0;
        for(int right=0; right<nums.size(); right++){
            while(st.find(nums[right]) != st.end()){
                st.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
            st.insert(nums[right]);
            sum += nums[right];
            ans = max(ans, sum);
        }
        return ans;
    }
};
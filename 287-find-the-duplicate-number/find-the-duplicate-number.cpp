class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0; i<nums.size(); i++){
            if(st.count(nums[i]) > 0){
                return nums[i];
            }
            st.insert(nums[i]);
        }
        return -1;
    }
};
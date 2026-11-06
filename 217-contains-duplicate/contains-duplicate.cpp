class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0; i<nums.size(); i++){
            if(st.count(nums[i]) >= 1){
                return true;
            }
            st.insert(nums[i]);
        }
        return false;
    }
};
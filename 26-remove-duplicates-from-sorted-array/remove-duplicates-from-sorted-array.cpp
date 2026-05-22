class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st;
        for(int num : nums){
            st.insert(num);
        }
        int i=0;
        for(int num : st){
            nums[i] = num;
            i++;
        }
        return st.size();
    }
};
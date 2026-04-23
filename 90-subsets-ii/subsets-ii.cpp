class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& curr, int index, vector<vector<int>>& ans){
       ans.push_back(curr);
       for(int i=index; i<nums.size(); i++){
        if(i>index && nums[i]==nums[i-1]) continue;
        curr.push_back(nums[i]);
        getAllSubsets(nums, curr, i+1, ans);
        curr.pop_back();
       }

        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        sort(nums.begin(), nums.end());
        getAllSubsets(nums, curr, 0, ans);
        return ans;
    }
};
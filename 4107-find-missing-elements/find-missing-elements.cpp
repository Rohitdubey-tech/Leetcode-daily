class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        unordered_set<int>s(nums.begin(),nums.end());
        vector<int>res;
        for(int x=mini;x<=maxi;x++){
            if(s.find(x)==s.end()){
                res.push_back(x);
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n,1);
        int prefix =1;
        for(int i=0; i<nums.size(); i++){
            answer[i] =prefix;
            prefix = prefix * nums[i];
        }
        int suffix =1;
        for(int i=nums.size()-1; i>=0; i--){
            answer[i] = answer[i] * suffix;
            suffix = suffix * nums[i];
        }
        return answer;
    }
};
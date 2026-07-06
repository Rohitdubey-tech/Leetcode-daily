class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int count = 0;
        for(int num : nums){
            int need = k-num;
            if(mp[need]>0){
                count++;
                mp[need]--;
            }
            else{
                mp[num]++;
            }
        }
        return count;

    }
};
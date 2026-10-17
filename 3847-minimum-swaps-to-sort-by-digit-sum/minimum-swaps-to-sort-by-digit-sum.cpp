class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<tuple<int,int,int>> vt;

        for(int i = 0; i < n; i++){
            string s = to_string(nums[i]);
            int sum = 0;
            for(int j = 0; j < s.size(); j++)
                sum += (s[j] - '0');
            vt.push_back({sum, nums[i], i});
        }

        sort(vt.begin(), vt.end());

        int swaps = 0;
        for(int i = 0; i < n; i++){
            while(get<2>(vt[i]) != i){
                swap(vt[i], vt[get<2>(vt[i])]);
                swaps++;
            }
        }
        return swaps;
    }
};
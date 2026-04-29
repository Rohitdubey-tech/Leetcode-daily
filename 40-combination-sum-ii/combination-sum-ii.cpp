class Solution {
private:
     vector<vector<int>> ans;

    void backtrack(vector<int> &arr, vector<int> &c, int target, int idx){

        if(target==0){
            ans.emplace_back(c);
            return;
        }

        if(target < 0 || idx==arr.size())return;

        c.push_back(arr[idx]);
        backtrack(arr,c,target-arr[idx],idx+1);
        c.pop_back();

        while(idx+1 < arr.size() && arr[idx]==arr[idx+1]){
            idx++;
        }
        idx++;
        backtrack(arr,c,target,idx);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<int> c;
        int idx=0;
        backtrack(arr,c,target,idx);
        return ans;
    }
};
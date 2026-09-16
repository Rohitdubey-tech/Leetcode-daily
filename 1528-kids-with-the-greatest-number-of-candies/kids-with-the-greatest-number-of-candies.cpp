class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxm = 0;
        for(int c : candies){
            maxm = max(maxm, c);
        }
        vector<bool>ans;
        for(int i=0; i<candies.size(); i++){
            if(candies[i]+extraCandies >= maxm){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
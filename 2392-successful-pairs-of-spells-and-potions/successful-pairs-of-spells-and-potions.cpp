class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        int n = potions.size();
        vector<int> ans;

        for(int spell : spells) {
            int low = 0, high = n - 1;
            int index = n;

            while(low <= high) {
                int mid = low + (high - low) / 2;

                if(1LL * spell * potions[mid] >= success) {
                    index = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            ans.push_back(n - index);
        }

        return ans;
    }
};
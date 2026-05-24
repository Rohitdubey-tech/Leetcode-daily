class Solution {
public:

    long long calculateHours(vector<int>& piles, int speed) {
        long long totalHours = 0;
        for(int pile : piles) {
            totalHours += ceil((double)pile / speed);
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long hours = calculateHours(piles, mid);
            if(hours <= h) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
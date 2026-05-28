class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n, 0);
        for(auto booking : bookings){
            int first = booking[0];
            int last = booking[1];
            int seats = booking[2];
            for(int i=first-1; i<=last-1; i++){
                ans[i] += seats;
            }
        }
        return ans;
    }
};
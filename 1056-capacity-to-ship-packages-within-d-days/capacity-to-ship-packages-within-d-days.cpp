class Solution {
public:
    int countDays(vector<int>& weights, int capacity){
        int days = 1;
        int load = 0;
        for(int weight : weights){
            if(load + weight > capacity){
                days++;
                load = weight;
            }
            else{
                load += weight;
            }
        }
        return days;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low <= high){
            int mid = low + (high - low ) / 2;
            int requireDays = countDays(weights, mid);
            if(requireDays <= days){
                high = mid -1;
            }
            else{
                low = mid + 1;

            }
        }
        return low;
    }
};
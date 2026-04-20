class Solution {
public:
    bool canEatAll(vector<int>piles, int mid, int h){
        int actualHours = 0;
        for(int &x : piles){
            actualHours += x/mid;
            if(x%mid != 0){
                actualHours++;
            }
        }
        return actualHours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while(low<high){
            int mid = low + (high-low)/2;
            if(canEatAll(piles, mid, h)){
                high = mid;
            }
            else{
                low = mid+1;
            }

        }
        return low;
    }
};
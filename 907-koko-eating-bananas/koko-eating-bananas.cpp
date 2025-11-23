class Solution {
public:
    bool canEat(vector<int> &piles, int H, int speed){
        long long hours = 0;
        for(int p:piles){
            hours += (p+speed-1)/speed;
            if(hours>H) return false;

        }
        return hours<=H;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(canEat(piles, H, mid)){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
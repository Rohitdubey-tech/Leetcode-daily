class Solution {
public:
    int largestAltitude(vector<int>& gain) {
 
        int altitude = 0;
        int maxmAltitude = 0;
        for(int g : gain){
            altitude += g;
            maxmAltitude = max(maxmAltitude, altitude);
        }
        return maxmAltitude;
    }
};
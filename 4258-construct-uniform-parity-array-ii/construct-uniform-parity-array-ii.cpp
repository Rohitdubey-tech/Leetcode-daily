class Solution {
public:
    bool uniformArray(vector<int>& nums) {  
        int minOddElement = INT_MAX;
        for(auto& it : nums) {
            if(it & 1) {
                if(minOddElement > it) {
                    minOddElement = it;
                }
            }
        }
        bool canBeConveretedToEven = true, canBeConveretedToOdd = true;
        for(auto &it : nums) {
            if(it & 1) {
                if(minOddElement >= it) {
                    canBeConveretedToEven = false;
                }
            }
            else {
                if(minOddElement > it) {
                    canBeConveretedToOdd = false;
                }
            }
        }
        return canBeConveretedToEven || canBeConveretedToOdd;
    }
};
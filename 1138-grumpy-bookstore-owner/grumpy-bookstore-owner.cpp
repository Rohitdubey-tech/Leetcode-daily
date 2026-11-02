class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int satisfied = 0;
        int windowSum = 0;
        int maxExtra = 0;
        for(int i=0; i<n; i++){
            if(grumpy[i] == 0){
                satisfied += customers[i];
            }
        }
        for(int i=0; i<minutes; i++){
            if(grumpy[i]==1){
                windowSum += customers[i];
            }
        }
        maxExtra = windowSum;
        for(int i=minutes; i<n; i++){
            if(grumpy[i]==1){
                windowSum += customers[i];
            }
            if(grumpy[i-minutes]==1){
                windowSum -= customers[i-minutes];
            }
            maxExtra = max(maxExtra, windowSum);
        }
        return satisfied + maxExtra;
    }
};
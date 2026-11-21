class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>>left, right;
        int l= 0;
        int r =costs.size()-1;
        for(int i=0; i<candidates && l <= r; i++){
            left.push(costs[l++]);
        }
        for(int i=0; i<candidates && l<= r; i++){
            right.push(costs[r--]);
        }
        long long ans = 0;
        while(k--){
            if(right.empty() || (!left.empty() && left.top() <= right.top())){
                ans += left.top();
                left.pop();
                if(l<=r){
                    left.push(costs[l++]);
                }
            }
            else{
                ans += right.top();
                right.pop();
                if(l <= r){
                    right.push(costs[r--]);
                }
            }
        }
        return ans;

    }
};
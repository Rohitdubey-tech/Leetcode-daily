class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>>v;
        int n = nums1.size();
        for(int i=0; i<n; i++){
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.rbegin(), v.rend());
        priority_queue<int, vector<int>, greater<int>>pq;
        long long sum = 0;
        long long ans = 0;
        for(auto it : v){
            pq.push(it.second);
            sum += it.second;
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k){
                ans = max(ans, sum*it.first);
            }
        }
        return ans;
    }
};
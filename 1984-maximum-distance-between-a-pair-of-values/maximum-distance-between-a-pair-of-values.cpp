class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        
        for(int j = 0; j < nums2.size(); j++){
            if(j < nums1.size())
                minHeap.push({j, nums1[j]});
            
            while(!minHeap.empty() && minHeap.top().second > nums2[j]){
                minHeap.pop();
            }
            
            if(!minHeap.empty())
                ans = max(ans, j - minHeap.top().first);
        }
        
        return ans;
    }
};
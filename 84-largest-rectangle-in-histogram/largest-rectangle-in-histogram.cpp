class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        long long maxArea = 0;
        stack<int>st;
        for(int i=0; i<=n; i++){
            int currHeight = (i == n) ? 0 : heights[i];
            while(!st.empty() && heights[st.top()] > currHeight){
                int h = heights[st.top()];
                st.pop();
                int right = i;
                int left = st.empty() ? -1 : st.top();
                long long width = right - left - 1;
                maxArea = max(maxArea, 1LL * h * width );
            }
            st.push(i);
        }
        return maxArea;

    }
};
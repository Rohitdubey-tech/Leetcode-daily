class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int>st;
        for(int i=0; i<=n; i++){
            int currHeight;
            if(i==n){
                currHeight = 0;
            }
            else{
                currHeight = heights[i];
            }
            while(!st.empty() && heights[st.top()]>currHeight){
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width = i;
                }
                else{
                   width = i - st.top() - 1;

                }
                int area = width * height;
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }
        return maxArea;
    }
};
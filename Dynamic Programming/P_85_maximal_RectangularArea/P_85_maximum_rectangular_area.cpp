class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() and heights[st.top()] > heights[i]) {
                int element = st.top();
                st.pop();
                int prevsmallerelement = (st.empty()) ? -1 : st.top();
                int nextsmallerelement = i;
                int currArea = heights[element] *
                               (nextsmallerelement - prevsmallerelement - 1);
                maxArea = max(maxArea, currArea);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int nse = n;
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            int currArea = heights[element] * (nse - pse - 1);
            maxArea = max(maxArea, currArea);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>currRow(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    currRow[j]+=1;
                }else{
                    currRow[j]=0;
                }
            }
            int currArea=largestRectangleArea(currRow);
            maxArea=max(maxArea,currArea);
        }
        return maxArea;
    }
};
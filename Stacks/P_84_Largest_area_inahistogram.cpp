class Solution {
public:
    vector<int> pse(vector<int>& heights, int n) {
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < n; i++) {
            while (st.top() != -1 and heights[i] <= heights[st.top()]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nse(vector<int>& heights, int n) {
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for (int i = n - 1; i >= 0; i--) {
            while (st.top() != -1 and heights[i] <= heights[st.top()]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nextsmallerelement(n);
        vector<int> prevsmallerelement(n);
        nextsmallerelement = nse(heights, n);
        prevsmallerelement = pse(heights, n);
        int area = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nextsmallerelement[i] == -1) {
                nextsmallerelement[i] = n;
            }
            int breadth = nextsmallerelement[i] - prevsmallerelement[i] - 1;
            int height = heights[i];
            int presentarea = breadth * height;
            area = max(area, presentarea);
        }
        return area;
    }
};

// Method 2 very intuitive 
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
};
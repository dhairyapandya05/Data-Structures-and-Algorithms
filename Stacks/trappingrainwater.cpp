class Solution {
public:
    vector<int> getleftmax(vector<int>& heights, int n) {
        vector<int> leftmax(n);
        leftmax[0] = heights[0];
        for (int i = 1; i < n; i++) {
            leftmax[i] = max(heights[i], leftmax[i - 1]);
        }
        return leftmax;
    }
    vector<int> getrightmax(vector<int>& heights, int n) {
        vector<int> rightmax(n);
        rightmax[n - 1] = heights[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightmax[i] = max(rightmax[i + 1], heights[i]);
        }
        return rightmax;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftmax = getleftmax(height, n);
        vector<int> rightmax = getrightmax(height, n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += min(leftmax[i], rightmax[i]) - height[i];
        }
        return sum;
    }
};
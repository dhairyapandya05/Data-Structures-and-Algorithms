class Solution {
public:
    int largestSubmatrix(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1 and i > 0) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
            vector<int> heights = matrix[i];
            sort(heights.begin(), heights.end(), greater<int>());
            for (int i = 0; i < m; i++) {
                int height = heights[i];
                int width = i + 1;
                int area = height * width;
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};

// Approach 2
class Solution {
public:
    int largestSubmatrix(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<int> prevHeights(m, 0);
        for (int i = 0; i < n; i++) {
            vector<int> currHeights = matrix[i];
            for (int j = 0; j < m; j++) {
                if (currHeights[j] == 1) {
                    currHeights[j] += prevHeights[j];
                }
            }
            vector<int> heights = currHeights;
            sort(heights.begin(), heights.end(), greater<int>());
            for (int i = 0; i < m; i++) {
                int height = heights[i];
                int width = i + 1;
                int area = height * width;
                maxArea = max(maxArea, area);
            }
            prevHeights = currHeights;
        }
        return maxArea;
    }
};

// Approach 3 without sorting
class Solution {
public:
    int largestSubmatrix(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<pair<int, int>> prevHeights; //<heights,column> for that particular column what was the cumulative height
        for (int i = 0; i < n; i++) {
            vector<pair<int, int>> currHeights;
            vector<bool> seen(n, false);
            for (auto it : prevHeights) {
                int height = it.first;
                int col = it.second;
                if (matrix[i][col] == 1) {
                    currHeights.push_back({height + 1, col});
                    seen[col] = true;
                }
            }
            for (int j = 0; j < m; j++) {

                if (seen[j] == false and matrix[i][j] == 1) {
                    currHeights.push_back({1, j});
                    seen[j] = true;
                }
            }
            for (int i = 0; i < currHeights.size(); i++) {
                int height = currHeights[i].first;
                int width = i + 1;
                int area = height * width;
                maxArea = max(maxArea, area);
            }
            prevHeights = currHeights;
        }
        return maxArea;
    }
};

// jiski height zyada hogi usko pahalae process kar laegae baki ka baad mae dhektae hai ... to aisa karnae sae hamae sorting nahi karni padti
class Solution {
public:
    int WIDTH;
    int HEIGHT;
    int solve(int idx, int remainingWidth, vector<vector<int>>& books,
              int maxHeight, vector<vector<int>>& dp) {
        if (idx >= books.size()) {
            return maxHeight;
        }
        if (dp[idx][remainingWidth] != -1) {
            return dp[idx][remainingWidth];
        }
        // keep and skip and take a minimum of both
        int keep = INT_MAX, skip = INT_MAX;
        int bookwidth = books[idx][0];
        int bookheight = books[idx][1];
        if (remainingWidth >= bookwidth) {
            keep = solve(idx + 1, remainingWidth - bookwidth, books,
                         max(maxHeight, bookheight),dp);
        }
        skip = maxHeight + solve(idx + 1, WIDTH - bookwidth, books, bookheight,dp);
        return dp[idx][remainingWidth] = min(skip, keep);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<vector<int>> dp(n + 1, vector<int>(shelfWidth + 1, -1));
        WIDTH = shelfWidth;
        int maxHeight = 0;
        int ans = solve(0, WIDTH, books, maxHeight,dp);
        return ans;
    }
};
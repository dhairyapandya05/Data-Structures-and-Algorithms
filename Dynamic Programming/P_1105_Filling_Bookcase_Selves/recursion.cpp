class Solution {
public:
    int WIDTH;
    int HEIGHT;
    int solve(int idx, int remainingWidth, vector<vector<int>>& books,
              int maxHeight) {
        if (idx >= books.size()) {
            return maxHeight;
        }
        // keep and skip and take a minimum of both
        int keep=INT_MAX, skip = INT_MAX;
        int bookwidth = books[idx][0];
        int bookheight = books[idx][1];
        if (remainingWidth >= bookwidth) {
            keep = solve(idx + 1, remainingWidth - bookwidth, books,
                         max(maxHeight, bookheight));
        }
        skip = maxHeight + solve(idx + 1, WIDTH-bookwidth, books, bookheight);
        return min(skip, keep);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        WIDTH = shelfWidth;
        int maxHeight = 0;
        int ans = solve(0, WIDTH, books, maxHeight);
        return ans;
    }
};
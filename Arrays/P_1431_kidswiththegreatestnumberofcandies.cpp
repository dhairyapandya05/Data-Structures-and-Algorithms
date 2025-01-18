class Solution {
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
        int maxcandieskid = *max_element(candies.begin(), candies.end());
        int n = candies.size();
        vector<bool> ans(n, false);
        for (int i = 0; i < n; i++) {
            if (candies[i] + extraCandies >= maxcandieskid) {
                ans[i] = true;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int> &nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> hash;
        // fill the hash map
        for (auto i : nums) {
            hash[i]++;
        }
        // now traverse through the hash map till we get an empty hash map
        //  now we will search for the maxi element in teh list
        int maxi = 0;
        for (auto i : hash) {
            maxi = max(maxi, i.second);
        }

        for (int i = 0; i < maxi; i++) {
            vector<int> temp;
            for (auto &j : hash) {
                if (j.second > 0) {
                    temp.push_back(j.first);
                    j.second--;
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<char, char> map;
        for (int i = 0; i < mapping.size(); i++) {
            map[i + '0'] = mapping[i] + '0';
        }
        // now the map is created now we convert the numbers as per the map
        vector<pair<int, int>> ans;
        for (auto it : nums) {
            string str_num = to_string(it);
            string mappedstr;
            for (auto itr : str_num) {
                mappedstr += map[itr];
            }
            int nummapped = stoi(mappedstr);
            ans.push_back({nummapped, it});
        }
        auto lambda = [&](pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second) {
                return a < b;
            }
            return a.first < b.first;
        };
        sort(ans.begin(), ans.end(), lambda);
        vector<int> finalans;
        for (int i = 0; i < ans.size(); i++) {
            finalans.push_back(ans[i].second);
        }
        return finalans;
    }
};
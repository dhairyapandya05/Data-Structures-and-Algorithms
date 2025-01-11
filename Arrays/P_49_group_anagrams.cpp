class Solution {
public:
    std::array<int, 256> hash(string s) {
    std:
        array<int, 256> ans = {0};
        for (int i = 0; i < s.size(); i++) {
            ans[s[i]]++;
        }
        return ans;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        // vector<vector<string>> ans;
        // unordered_map <string,vector<string>> mp;
        // for(auto str : strs){
        //     string s = str;
        //     sort(s.begin(),s.end());
        //     mp[s].push_back(str);
        // }

        // for(auto i = mp.begin();i != mp.end();i++){
        //     ans.push_back(i->second);
        // }
        // return ans;

        // Method 2
        //  using maps

        map<std::array<int, 256>, vector<string>> mp;
        for (auto str : strs) {
            // string s = str;
            // sort(s.begin(),s.end());
            mp[hash(str)].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto i = mp.begin(); i != mp.end(); i++) {
            ans.push_back(i->second);
        }
        return ans;
    }
};
TC : O(n *k * 26)
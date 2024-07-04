class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> map;
        int maxfreq = 0;
        int totalfreq = 0;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
            if (map[nums[i]] == maxfreq) {
                totalfreq+= maxfreq ;
            }
            if (map[nums[i]] > maxfreq) {
                maxfreq = map[nums[i]];
                totalfreq = maxfreq;
            }
        }
        return totalfreq;
    }
};
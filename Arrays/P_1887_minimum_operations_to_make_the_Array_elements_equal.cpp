class Solution {
public:
    int reductionOperations(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minele = nums[0];
        int operations = 0;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] == nums[i - 1])
                continue;
            operations += (n - i);
        }
        return operations;
    }
};

// So this was basically my approach
class Solution {
public:
    int reductionOperations(vector<int> &nums) {
        map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }
        int totaloperations = 0;
        int operations = 0;

        int n = mp.size();
        for (auto it = prev(mp.end()); it != mp.begin(); it--) {
            operations += it->second;
            totaloperations += operations;
        }
        return totaloperations;
    }
};
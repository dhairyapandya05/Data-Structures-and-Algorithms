class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }

        return{};
    }
};

// Hashing Method
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int moreneeded = target - nums[i];
            auto it=mp.find(moreneeded);
            if(it!=mp.end()){
                return {it->second,i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};
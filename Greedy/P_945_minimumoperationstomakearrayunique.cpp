class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                cnt+=nums[i-1]+1-nums[i];
                nums[i]=nums[i-1]+1;
            }
        }
        return cnt;
    }
};



// Counting Sort
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int size = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> freq(size + n, 0);
        int cnt = 0;
        for (auto it : nums) {
            freq[it]++;
        }
        for (int i = 0; i < n + size; i++) {
            if (freq[i] <= 1) {
                continue;
            } else {
                int extra = freq[i] - 1;
                freq[i] = 1;
                freq[i + 1] += extra;
                cnt += extra;
            }
        }
        return cnt;
    }
};
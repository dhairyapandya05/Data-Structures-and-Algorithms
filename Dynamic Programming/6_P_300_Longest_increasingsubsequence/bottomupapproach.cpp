class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1);
        int maxlis = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    t[i] = max(t[j] + 1, t[i]);
                    maxlis = max(maxlis, t[i]);
                }
            }
        }
        return maxlis;
    }
};
// 
// Printing the longest increasing subsequence
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
           vector<int>dp(n+1,1);
    vector<int>hash(n+1,-1);
    int maxi=1;
    int maxidx=0;
    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i] and 1+dp[j]>dp[i]){
                dp[i]=dp[j]+1;
                hash[i]=j;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            maxidx=i;
        }
    }
    vector<int> ans;
    while(maxidx!=hash[maxidx]){
        ans.push_back(nums[maxidx]);
        maxidx=hash[maxidx];
    }
    ans.push_back(nums[maxidx]);
    reverse(ans.begin(),ans.end());
    return ans;
    }
};
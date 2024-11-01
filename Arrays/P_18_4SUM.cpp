class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 and nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size();j++)
            {
                if(j>i+1 and nums[j]==nums[j-1]) continue;
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        vector<int> temp;
                        temp={nums[i],nums[j],nums[k],nums[l]}; //they are already in the sorted order 
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l and nums[k]==nums[k-1]) k++;
                        while(k<l and nums[l]==nums[l+1]) l--;
                    }
                    else if(sum<target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};
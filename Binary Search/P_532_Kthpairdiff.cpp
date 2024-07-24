class Solution {
public:

    int binarysearch(vector<int>& nums,int start, int x){
        int end = nums.size()-1;
        while(start<=end){
           int mid=start+(end-start)/2;
            if(nums[mid] ==x){
                return mid;
            }
            else if(nums[mid] > x){
                end = mid-1;
            }

            else{
                start = mid+1;
            }

        }
        return -1;
    }

    int findPairs(vector<int>& nums, int k) {
        set<pair<int,int>> ans;
        sort(nums.begin(),nums.end());

        
        return ans.size();
    }
};
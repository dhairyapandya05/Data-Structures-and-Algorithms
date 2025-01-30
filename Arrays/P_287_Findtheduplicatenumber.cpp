class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        // int ans=-1;
        // for(int i=0;i<nums.size();i++){
        //     int index=abs(nums[i]);
        //     if(nums[index]<0){
        //         return index;
        //         break;
        //     }

        //     //visited mark
        //     nums[index]*=-1;
        // }
        // return ans;
        while (nums[0] != nums[nums[0]]) {
            swap(nums[0], nums[nums[0]]);
        }
        return nums[0];
    }
};

// sum of first n natural numbers = n*(n+1)/2
// another approach using hare and tortoise technique(slow and fast technique)

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int slow = nums[0];
        int fast = nums[0];
        slow = nums[slow];
        fast = nums[nums[fast]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int ele;
        for(auto& it:nums){
            if(cnt==0){
                ele=it;
                cnt=1;
            }
            else if(it==ele){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        // now we will check that ele can be a majority element
        int threshold=nums.size()/2;
        for(auto& it:nums){
            if(it==ele){
                threshold--;
            }
            if(threshold<=0){
                return ele;
            }
        }
        return -1;
    }
};
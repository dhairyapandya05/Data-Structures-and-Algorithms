class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int k=0;k<=31;k++){
            int onecnt=0;
            int temp=(1<<k);
            for(auto& num:nums){
                if((num & temp)!=0){
                    onecnt++;
                }
            }
            if(onecnt%3==1){
                result=(result|temp);
            }
        }
        return result;
    }
};
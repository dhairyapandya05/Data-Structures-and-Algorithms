class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum=0;
        int result=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0){
                result=i+1;
            }
            else{
                if(mp.find(sum)!=mp.end()){
                    result=max(result,i-mp[sum]);
                }
                else{
                    mp[sum]=i;
                }
            }
            
        }
        return result;
    }
};
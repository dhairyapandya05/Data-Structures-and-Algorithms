
class Solution {
public:
    bool canweplacekcowsatkdistance(int mid,int& k,vector<int>& stalls){
        int noofcows=1;
        int lastpos=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(lastpos+mid<=stalls[i]){
                lastpos=stalls[i];
                noofcows++;
            }
            if(noofcows>=k){
                return true;
            }
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int s=0;
        int e=stalls[n-1]-stalls[0];
        int ans;
        while(s<=e){
        int mid=s+(e-s)/2;
            if(canweplacekcowsatkdistance(mid,k,stalls)==true){
                ans=mid;
                s=mid+1;
            } 
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};
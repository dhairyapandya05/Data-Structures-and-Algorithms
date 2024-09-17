class Solution {
public:
    int solve(int idx1,int idx2,int& n,int& m,vector<int>& nums1, vector<int>& nums2){
        if(idx1>=n or idx2>=m){
            return 0;
        }
        int matched=0,unmatched=0;
        if(nums1[idx1]==nums2[idx2]){
            matched=1+solve(idx1+1,idx2+1,n,m,nums1,nums2);
        }
        else{
        unmatched=max(solve(idx1+1,idx2,n,m,nums1,nums2),solve(idx1,idx2+1,n,m,nums1,nums2));
        }
        return max(matched,unmatched);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int idx1=0,idx2=0;
        return solve(idx1,idx2,n,m,nums1,nums2);
    }
};
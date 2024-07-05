class Solution {
public:
    int canbloom(int days,vector<int>& bloomDay,int k){
        int bouquescnt=0;
        int flowercollect=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=days){
                flowercollect++;
            }
            else if (bloomDay[i]>days){
                flowercollect=0;
            }
            if(flowercollect==k){
                bouquescnt++;
                flowercollect=0;//yaha par galti hui thi meri
            }
        }
        return bouquescnt;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int mindays=0;
        int maxdays=*max_element(bloomDay.begin(),bloomDay.end());
        int mid;
        int ans=-1;
        while(mindays<=maxdays){
            mid=mindays+(maxdays-mindays)/2;
            if(canbloom(mid,bloomDay,k)>=m){
                maxdays=mid-1;
                ans=mid;
            }
            else{
                mindays=mid+1;
            }
        }
        return ans;
    }
};
// link:https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
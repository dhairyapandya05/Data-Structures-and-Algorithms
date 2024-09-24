class Solution {
public:
// sort them based on the greater growth period
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({plantTime[i],growTime[i]});
        }
        auto cmp=[&](pair<int,int>&p1,pair<int,int>&p2){
            if(p1.second==p2.second){
                return p1.first>p2.first;
            }
            return p1.second>p2.second;
        };
        sort(vec.begin(),vec.end(),cmp);
        int time=-1;
        int bloomtime=0;
        for(int i=0;i<n;i++){
            int planttime=vec[i].first;
            int growtime=vec[i].second;
            time+=planttime;
            bloomtime=max(bloomtime,time+growtime+1);
        }
        return bloomtime;
    }
};
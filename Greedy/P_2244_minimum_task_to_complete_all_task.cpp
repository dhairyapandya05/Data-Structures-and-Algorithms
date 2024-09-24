class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(auto it:tasks){
            mp[it]++;
        }
        int cnt=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second==1){
                return -1;
            }
            cnt+=it->second/3;
            if(it->second%3!=0){
                cnt++;
            }
        }
        return cnt;
    }
};
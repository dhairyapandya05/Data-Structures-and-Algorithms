class Solution {
public:
    typedef pair<int,int> pp;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(auto& it:nums){
            map[it]++;
        }
        priority_queue<pp> pq;
        for(auto it=map.begin();it!=map.end();it++){
            pq.push({it->second,it->first});
        }
        vector<int> ans;
        while(k--){
            auto temp=pq.top();
            pq.pop();
            ans.push_back(temp.second);
        }
        return ans;
    }
};
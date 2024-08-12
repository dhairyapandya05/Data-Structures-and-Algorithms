class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> targetmap;
        unordered_map<int,int> arrmap;
        for(auto& it:target){
            targetmap[it]++;
        }
        for(auto& it:arr){
            arrmap[it]++;
        }
        return arrmap==targetmap;
    }
};
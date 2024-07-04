class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> sourcecities;
        for(auto& path:paths){
            sourcecities.insert(path[0]);
        }
        for(auto& path:paths){
            if(sourcecities.find(path[1])==sourcecities.end()){
                return path[1];
            }
        }
        return "";
    }
};
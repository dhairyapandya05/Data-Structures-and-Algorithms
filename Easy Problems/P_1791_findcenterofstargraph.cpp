class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        auto edge1=edges[0];
        auto edge2=edges[1];
        int u1=edge1[0];
        int v1=edge1[1];
        int u2=edge2[0];
        int v2=edge2[1];
        if(u1==u2 or u1==v2){
            return u1;
        }
        if(v1==u2 or v1==v2){
            return v1;
        }
        return NULL;
    }
};
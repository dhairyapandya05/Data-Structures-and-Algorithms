class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        priority_queue<pair<int,pair<int,int>>> pq;
        set<pair<int,int>> visited;
        sort(A.begin(),A.end(),greater<int>());
        sort(B.begin(),B.end(),greater<int>());
        visited.insert({0,0});
        vector<int> ans;
        int i=0,j=0;
        pq.push({A[0]+B[0],{0,0}});
        while(K--){
            auto it =pq.top();
            int sum=it.first;
            int i=it.second.first;
            int j=it.second.second;
            pq.pop();
            ans.push_back(sum);
            if(j+1<B.size() and visited.find({i,j+1})==visited.end()){
                pq.push({A[i]+B[j+1],{i,j+1}});
                visited.insert({i,j+1});
            }
            if(i+1<A.size() and visited.find({i+1,j})==visited.end()){
                pq.push({A[i+1]+B[j],{i+1,j}});
                visited.insert({i+1,j});
            }
        }
        return ans;
    }
};
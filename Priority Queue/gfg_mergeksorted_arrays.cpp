//User function Template for C++
class Solution
{
    public:
    //Function to merge k sorted arrays.
    typedef pair<int,int> pp;
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        vector<int>ptr(K,0);
        int n=arr.size();
        for(int i=0;i<K;i++){
            pq.push({arr[i][0],i});
        }
        vector<int> ans(n*n);
        for(int i=0;i<n*n;i++){
            auto it=pq.top();
            pq.pop();
            int element=it.first;
            int w_arr=it.second;
            ans[i]=element;
            ptr[w_arr]++;
            if(ptr[w_arr]<n){
            pq.push({arr[w_arr][ptr[w_arr]],w_arr});
            }

        }
        return ans;
    }
};
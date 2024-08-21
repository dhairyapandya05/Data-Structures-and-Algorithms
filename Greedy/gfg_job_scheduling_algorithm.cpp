class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        auto cmp=[&](Job& a,Job& b){
            return a.profit>b.profit;
        };
        sort(arr,arr+n,cmp);
        int maxdeadline=-1;
        for(int i=0;i<n;i++){
            maxdeadline=max(maxdeadline,arr[i].dead);
        }
        vector<int> deadlinelimit(maxdeadline+1,-1);
        int maxprofit=0;
        int noofjobs=0;
        for(int i=0;i<n;i++){
            int jobid=arr[i].id;
            int deadl=arr[i].dead;
            int profit=arr[i].profit;
            for(int j=deadl;j>0;j--){
                if(deadlinelimit[j]==-1){
                    deadlinelimit[j]=jobid;
                    maxprofit+=profit;
                    noofjobs+=1;
                    break;
                }
            }
        }
        return {noofjobs,maxprofit};
    } 
};
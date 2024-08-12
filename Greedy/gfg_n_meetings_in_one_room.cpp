class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<vector<int>> meetinginfo;
        for(int i=0;i<n;i++){
            meetinginfo.push_back({start[i],end[i],i});// we are storing the staritng_time  , ending_time,   idx
        }
        auto cmp=[&](vector<int>& a,vector<int>&b){
            if(a[1]==b[1]){
                return a[0]<b[0];
            }
            return a[1]<b[1];
        };
        sort(meetinginfo.begin(),meetinginfo.end(),cmp);
        vector<int>order;
        int endingtime=-1;
        for(auto it:meetinginfo){
            if(endingtime<it[0]){
                order.push_back(it[2]);
                endingtime=it[1];
            }
        }
        return order.size();
    }
};
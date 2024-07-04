// https://www.geeksforgeeks.org/problems/police-and-thieves--141631/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        // Code here 
        vector<int> police_vec;
        vector<int> thief_vec;
        for(int i=0;i<n;i++){
            if(arr[i]=='P')
            {
                police_vec.push_back(i);
            }
            else if(arr[i]=='T'){
                thief_vec.push_back(i);
            }
        }
        int pol_index=0;
        int thief_index=0;
        int ans=0;
        while(pol_index<police_vec.size() and thief_index<thief_vec.size()){
            if(abs(police_vec[pol_index]-thief_vec[thief_index])<=k){
                pol_index++;
                thief_index++;
                ans++;
            }
            else if (police_vec[pol_index]>thief_vec[thief_index]){
                thief_index++;
            }
            else{
                pol_index++;
            }
    
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 


// } Driver Code Ends
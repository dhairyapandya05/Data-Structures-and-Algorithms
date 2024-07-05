//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n=matrix.size();
	    for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                if(matrix[i][j]==-1){
	                    matrix[i][j]=10000;
	                }
	            }
	        }
	    
	    for(int via=0;via<n;via++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                matrix[i][j]=min(matrix[i][j],matrix[i][via]+matrix[via][j]);
	            }
	        }
	    }
	    for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                if(matrix[i][j]==10000){
	                    matrix[i][j]=-1;
	                }
	            }
	        }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
// O(n^3)
// how to detect a cycle 
// for(int i=0;i<n;i++){
//     if(grid[i][i]<0){
//         return 1;//cycle is present
//     }
// }
link:https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
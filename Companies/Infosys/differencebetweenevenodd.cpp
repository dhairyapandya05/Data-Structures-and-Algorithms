#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>& arr,int& n){
    int even=0,odd=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            even+=arr[i];
        }
        else{
            odd+=arr[i];
        }
    }
    return (even-odd);
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        arr[i]=ele;
    }
    for (auto it:arr){
        cout<<it<<" ";
    }
    int ans=solve(arr,n);
    cout<<ans;
    return 0;
}
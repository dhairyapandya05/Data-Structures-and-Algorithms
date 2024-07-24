class Solution {
public:
int lowerbound(vector<int> arr,int x){
    int s = 0;
    int e = arr.size() - 1;
    int mid;
    int ans = e;
    while(s<=e){
        mid = s+(e-s)/2;
        if(arr[mid] >= x){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]<x)
        {
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int h=lowerbound(arr,x);
        // vector<int> ans;
        int l=h-1;
        while(k--){
            if(l<=0){
                h++;
            }
            if(h>=arr.size()){
                l--;
            }
             if(x-arr[l] > arr[h]-x){
                h++;
                }

            else{
                l--;
            }
        }
       
    return vector <int>(arr.begin()+l+1,arr.begin()+h);
    }

};
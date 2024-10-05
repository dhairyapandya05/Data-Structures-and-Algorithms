// Correct method
class Solution{   
public:
    bool solve(int idx,vector<int>& arr, int sum){
        if(sum==0){
            return true;
        }
        if(idx==0){
            return arr[idx]==sum;
        }
        bool skip=false;
        bool take=false;
        skip=solve(idx-1,arr,sum);
        if(sum-arr[idx]>=0){
            take=solve(idx-1,arr,sum-arr[idx]);
        }
        return skip or take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size()-1;
        return solve(n,arr,sum);
    }
};

// Dhairya's method
class Solution{   
public:
    bool solve(int idx,vector<int>& arr, int sum){
        if(idx==arr.size()){
            if(sum==0){
                return true;
            }
            else{
                return false;
            }
        }
        bool skip=false;
        bool take=false;
        skip=solve(idx+1,arr,sum);
        take=solve(idx+1,arr,sum-arr[idx]);
        return skip or take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        return solve(0,arr,sum);
    }
};
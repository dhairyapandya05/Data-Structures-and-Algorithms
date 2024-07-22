https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int low=0;
        int high=arr.size()-1;
        int mid;
        while(high>=low){
            mid=low+(high-low)/2;
            if(key==arr[mid]){
                return mid;
            }
            // left part is sorted
            if(arr[mid]>=arr[low]){
                if(key<=arr[mid] and key>=arr[low]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            //right part is sorted
            else{
                if(key>=arr[mid] and key<=arr[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }

        }
        return -1;//if the element is not found
    }
};
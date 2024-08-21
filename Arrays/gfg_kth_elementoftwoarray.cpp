class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int i=0,j=0;
        while(i<arr1.size() and j<arr2.size()){
            if(arr1[i]<arr2[j]){
                k--;
                if(k==0){
                    return arr1[i];
                }
                i++;
            }
            else if(arr1[i]>=arr2[j]){
                k--;
                if(k==0){
                    return arr2[j];
                }
                j++;
            }
            // if(k==0){
            //     return (arr1[i]<arr2[j])?arr1[i]:arr2[j];
            // }
        }
        while(i<arr1.size()){
            k--;
            if(k==0){
                return arr1[i];
            }
            i++;
        }
        while(j<arr2.size()){
            k--;
            if(k==0){
                return arr2[j];
            }
            j++;
        }
    }
};
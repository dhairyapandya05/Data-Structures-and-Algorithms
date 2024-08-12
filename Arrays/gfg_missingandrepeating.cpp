vector<int> findTwoElement(vector<int> arr, int n) {
        int A,B;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            int ele=arr[i];
            if(map[ele]==0){
                map[ele]++;
            }
            else{
                B=ele;
            }
        }
        for(int i=1;i<=n;i++){
            if(map[i]==0){
                A=i;
                break;
            }
        }
        
        return {B,A};
    }
    // link:https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         int len1=m-l+1;
         int len2=r-m;
         
         int left[len1];
         int right[len2];
        //  copying the array into the newly formed left and right
        for(int i=0,k=l;i<len1;i++,k++){
            left[i]=arr[k];
        }
        
        for(int i=0,k=m+1;i<len2;i++,k++){
            right[i]=arr[k];
        }
        //logic
        int rightptr=0;
        int leftptr=0;
        int mainarrayindex=l;
        while(rightptr<len2 and leftptr<len1){
            if(left[leftptr]<right[rightptr]){
                arr[mainarrayindex++]=left[leftptr++];
            }
            else{
                arr[mainarrayindex++]=right[rightptr++];
            }
        }
        while(rightptr<len2){
            arr[mainarrayindex++]=right[rightptr++];
        }
        while(leftptr<len1){
            arr[mainarrayindex++]=left[leftptr++];
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r){
            return;
        }
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
        
    }
};
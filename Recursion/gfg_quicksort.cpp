class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low>=high){
            return;
        }
        int p=partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int partisionidx=low;
        int partisionele=arr[partisionidx];
        int cnt=0;
        for(int i=low+1;i<=high;i++){
            if(arr[i]<=partisionele){
                cnt++;
            }
        }
        int rightidx=low+cnt;
        swap(arr[partisionidx],arr[rightidx]);
        partisionidx=rightidx;
        
        int i=low;
        int j=high;
        while(i<partisionidx and j>partisionidx){
            while(arr[i]<=partisionele){
                i++;
            }
            while(arr[j]>partisionele){
                j--;
            }
            if(i<partisionidx and j>partisionidx){
                swap(arr[i],arr[j]);
            }
        }
        return partisionidx;
    }
};
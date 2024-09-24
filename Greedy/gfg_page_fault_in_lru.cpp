class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        int pagefault=0;
        vector<int> tray;
        int pageidx=0;
        for(int i=0;i<N;i++){
            auto it=find(tray.begin(),tray.end(),pages[i]);
            if(it==tray.end()){
                if(tray.size()>=C){
                    tray.erase(tray.begin());
                }
                
                pagefault++;
            }
            else{
                tray.erase(it);
                
            }
            tray.push_back(pages[i]);
            
        }
        return pagefault;
    }
};
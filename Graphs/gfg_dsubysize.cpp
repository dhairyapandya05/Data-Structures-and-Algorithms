class Solution
{
    public:
    vector<int> parent;
    vector<int> size;
    
    int find(int i){
        if(parent[i]==i){
            return i;
        }
        return parent[i]=find(parent[i]);
    }
    
    void unionSets(int u,int v){
        int x_parent=find(u);
        int y_parent=find(v);
        if(x_parent!=y_parent){
            if(size[x_parent]>size[y_parent]){
                parent[y_parent]=x_parent;
                size[x_parent]+=size[y_parent];
            }
            else if(size[x_parent] < size[y_parent]){
                parent[x_parent]=y_parent;
                size[y_parent]+=size[x_parent];

            }
            else{
                parent[x_parent]=y_parent;
                size[y_parent]+=size[x_parent];
            }
        }
    }
};
class MyHashSet {
public:
    vector<bool> vec;
    MyHashSet() {
        vec.resize(1000001,false);
    }
    
    void add(int key) {
        vec[key]=true;
    }
    
    void remove(int key) {
        vec[key]=false;
    }
    
    bool contains(int key) {
        return vec[key]==true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
class MyHashSet {
public:
    vector<list<int>> vec;
    int M;
    int getindex(int key){
        return key%M;
    }
    MyHashSet() {
        M=15000;
        vec.resize(M,list<int>{});
    }
    
    void add(int key) {
        int idx=getindex(key);
        auto itr=find(vec[idx].begin(),vec[idx].end(),key);
        if(itr==vec[idx].end()){
            vec[idx].push_back(key);
        }
    }
    
    void remove(int key) {
        int idx=getindex(key);
        auto itr=find(vec[idx].begin(),vec[idx].end(),key);
        if(itr!=vec[idx].end()){
            vec[idx].erase(itr);
        }
    }
    
    bool contains(int key) {
        int idx=getindex(key);
        auto itr=find(vec[idx].begin(),vec[idx].end(),key);
        return itr!=vec[idx].end();
    }
};
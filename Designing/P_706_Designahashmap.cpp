class MyHashMap {
public:
    vector<int> vec;
    MyHashMap() {
        vec.resize(1e6+1);
        fill(vec.begin(),vec.end(),-1);
    }
    
    void put(int key, int value) {
        vec[key]=value;
    }
    
    int get(int key) {
        return vec[key];
    }
    
    void remove(int key) {
        vec[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

class MyHashMap {
public:
vector<list<pair<int,int>>> buckets;
int size=1e4+1;
    MyHashMap() {
        buckets.resize(size);
    }
    
    void put(int key, int value) {
        int bucketNo=key%size;
        auto& chain=buckets[bucketNo];
        for(auto& it:chain){
            if(it.first==key){
                it.second=value;
                return;
            }
        }
        chain.emplace_back(key,value);
    }
    
    int get(int key) {
        int bucketNo=key%size;
        auto& chain=buckets[bucketNo];
        if(chain.empty()){
            return -1;
        }
        for(auto& it:chain){
            if(it.first==key){
                return it.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int bucketNo=key%size;
        auto& chain=buckets[bucketNo];
        for(auto it=chain.begin();it!=chain.end();it++){
            if(it->first==key){
                chain.erase(it);//erase funcion always taks a pointer to erase a value
                return;
            }
        }
    }
};
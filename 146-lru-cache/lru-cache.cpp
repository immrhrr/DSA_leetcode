class LRUCache {
public:
    unordered_map<int, pair<list<int>::iterator, int>> mp;
    //{key,{address,val}}
    list<int>lru;
    int curr=0;
    LRUCache(int capacity) {
        curr=capacity;
    }
    int get(int key) {
        //present hai
        if(mp.find(key)!=mp.end()){
            int val=mp[key].second;
            //ab usko waha se erase krna hai
            lru.erase(mp[key].first);
            mp.erase(key);
            lru.push_front(key);
            mp[key]={lru.begin(),val};
            return val;
            //usko ab front pe push krna hai
        }
        //not present hai
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        //already present hai
        if(mp.find(key)!=mp.end()){
            lru.erase(mp[key].first);
            mp.erase(key);
            lru.push_front(key);
            mp[key]={lru.begin(),value};
            return;
        }
        //present nhi hai
        curr--;
        lru.push_front(key);
        mp[key]={lru.begin(),value};
        //pecche wala ko delete krna hai ab
        if(curr<0){
        int key_table=lru.back();
        lru.pop_back();
        mp.erase(key_table);
        curr++;
        }
        return; 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
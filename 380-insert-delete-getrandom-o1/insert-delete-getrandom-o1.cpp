class RandomizedSet {
public:
    vector<int>arr;
    unordered_map<int,int>mp;
    //value,index in the arr
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        //not present
        if(mp.find(val)==mp.end()){
            arr.push_back(val);
            mp[val]=arr.size()-1;
            return true;
        }
        //already present
        else{
            return false;
        }
    }
    
    bool remove(int val) {
        //not present
        if(mp.find(val)==mp.end()){
            return false;
        }
        //present hai
        else{
            int idx=mp[val];
            int last=arr.back();
            arr[idx]=last;
            mp[last]=idx;
            arr.pop_back();
            mp.erase(val);
            return true;
        }
        
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
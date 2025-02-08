class NumberContainers {
public:
    unordered_map<int, int> idx_num;
    unordered_map<int, set<int>> num_idx;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (idx_num.find(index) != idx_num.end()) {
            int old_number = idx_num[index];
            num_idx[old_number].erase(index);
            if (num_idx[old_number].empty()) { // Use .empty() instead of .size() == 0
                num_idx.erase(old_number);
            }
        }
        idx_num[index] = number;
        num_idx[number].insert(index);  // Fixed error (was push_back)
    }
    
    int find(int number) {
        if (num_idx.find(number) != num_idx.end() && !num_idx[number].empty()) { 
            return *num_idx[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index, number);
 * int param_2 = obj->find(number);
 */

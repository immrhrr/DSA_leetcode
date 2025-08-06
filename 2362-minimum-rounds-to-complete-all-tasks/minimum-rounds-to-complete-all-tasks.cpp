class Solution {
public:
   
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        for (int i = 0; i < tasks.size(); i++) {
            mp[tasks[i]]++;
        }
        int temp = 0;
        for (auto it : mp) {
            int val = it.second;
            if(val==1)return -1;
            temp += (val + 2) / 3;
        }
        return temp;
       
    }
};
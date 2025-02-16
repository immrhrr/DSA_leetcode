class Solution {
public:
    bool func(int& n, vector<int>& ans, vector<bool>& used, int index) {
        //we got ans
        if (index >= 2 * n - 1) {
            return true;
        }
        //this index is filled
        if (ans[index] != -1) {
            return func(n, ans, used, index + 1);
        }
       //check which number we can use to fill this index
        for (int num = n; num > 0; num--) {
           //this num is already used
          
            if (used[num] == true) {
                continue;
            }
            //try
            used[num] = true;
            ans[index] = num;
            //if num is 1 only once to use
             //explore
            if (num == 1) {
                if (func(n, ans, used, index + 1) == true) {
                    return true;
                }
                
            } 
            //if it is other than 1 we have to use two times
            else {
                int second_index = index + num;
                //check if we can put at second_index
                if (second_index < 2 * n - 1 && ans[second_index] == -1) {
                    ans[second_index] = num;
                    if (func(n, ans, used, index + 1) == true) {
                        return true;
                    } else {
                        ans[second_index]= - 1;
                    }
                }
            }
            //undo
            ans[index] = -1;
            used[num] = false;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n -1, -1);
        vector<bool> used(n+1, false);
        int index = 0;
        func(n, ans, used, index);
        return ans;
    }
};
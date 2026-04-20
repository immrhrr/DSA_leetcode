class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int i = 0 , j = n - 1;
        int ans = -1;
        while(i < n && colors[i] == colors[n - 1])i++;
        while(j > 0 && colors[j] == colors[0])j--;
        if(i < n)
        {
            ans = max(ans , n - 1 - i);
        }
        if(j > 0)
        {
            ans = max(ans , j);
        }
        return ans;
    }
};


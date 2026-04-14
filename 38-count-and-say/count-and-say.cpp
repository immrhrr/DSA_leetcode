class Solution {
public:
    string countAndSay(int n) {
        vector<string> ans(n+1);
        ans[1] = "1";
        
        for(int i = 2; i <= n; i++){
            string temp = "";
            for(int j = 0; j < ans[i-1].size(); j++){
                int cnt = 1;
                
                // 1. Just count in this loop, then break when characters differ
                for(int k = j + 1; k < ans[i-1].size(); k++){
                    if(ans[i-1][j] == ans[i-1][k]){
                        cnt++;
                    }
                    else{
                        break; // Stop counting for this group
                    }
                }
                
                // 2. Move the appending logic OUTSIDE the inner loop
                temp = temp + to_string(cnt);
                temp += ans[i-1][j];
                
                // 3. Jump 'j' forward so we don't recount characters. 
                // We subtract 1 because the outer loop will do j++ automatically.
                j += cnt - 1; 
            }
            // 4. Store the result in ans[i], not ans[i-1]
            ans[i] = temp;
        }
        
        // 5. Return ans[n], not ans[n-1]
        return ans[n];
    }
};
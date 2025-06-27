class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        long long tot_sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                tot_sum+=grid[i][j];
            }
        }
        if(tot_sum%2==1)return false;
        vector<long long>h_cut(n,0);
        vector<long long>v_cut(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                h_cut[i]+=grid[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v_cut[i]+=grid[j][i];
            }
        }

        //now try to partition h_cut or v_cut in the two equal partitons
        //try horizontal cut
        long long upar=h_cut[0];
        long long neeche=tot_sum-upar;
        for(int i=1;i<n;i++){
            if(upar==neeche){
                return true;
            }
            upar+=h_cut[i];
            neeche-=h_cut[i];
        }
        //try vertical cut
        long long left=v_cut[0];
        long long right=tot_sum-left;
        for(int i=1;i<m;i++){
            if(left==right){
                return true;
            }
            left+=v_cut[i];
            right-=v_cut[i];
        }
        return false;
        
    }
};
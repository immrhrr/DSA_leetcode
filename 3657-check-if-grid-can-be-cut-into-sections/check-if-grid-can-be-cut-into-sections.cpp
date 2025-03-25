class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rect) {
        int m = rect.size();
        if (m == 0) return false; // No rectangles, no valid cuts.
        vector<vector<int>>v(m);
        vector<vector<int>>h(m);
        for(int i=0;i<m;i++){
            h[i]={rect[i][0],rect[i][2]};
            v[i]={rect[i][1],rect[i][3]};
        }
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());

        vector<pair<int, int>> vert, hor;

       
        vert.push_back({v[0][0],v[0][1]});
        hor.push_back({h[0][0],h[0][1]});

        int prev_end_v ;
            int curr_start_v ;
            int curr_end_v ;

             int prev_end_h ;
            int curr_start_h ;
            int curr_end_h ;


        for (int i = 1; i < m; i++) {
            // Process vertical cuts
        prev_end_v = vert.back().second;
           curr_start_v = v[i][0];
             curr_end_v = v[i][1];

            if (curr_start_v < prev_end_v) {
                vert.back().second = max(prev_end_v, curr_end_v);
            } else {
                vert.push_back({curr_start_v, curr_end_v});
            }

            // Process horizontal cuts
            prev_end_h = hor.back().second;
            curr_start_h = h[i][0];
           curr_end_h = h[i][1];

            if (curr_start_h < prev_end_h) {
                hor.back().second = max(prev_end_h, curr_end_h);
            } else {
                hor.push_back({curr_start_h, curr_end_h});
            }
        }
          
          int a=0;int b=0;
        //   if(hor[0].first!=0)a++;
        //   if(hor.back().second!=n)a++;
        //   if(vert[0].first!=0)b++;
        //   if(vert.back().second!=n)b++;

        
        return (vert.size()+b >= 3 || hor.size() +a>= 3);
    }
};

class Solution {
public:
    double area(vector<vector<int>>& squares, double mid) {
        int n = squares.size();
        double temp = 0.0;
        for (int i = 0; i < n; i++) {
            double x=squares[i][0];
            double y=squares[i][1];
            double l=squares[i][2];
            
            double up = y+l;

            // Calculate the area below 'mid'
            if (up >= mid) {
                double valid_width = mid - y;
                if (valid_width > 0) {  // Ensure valid width
                    temp += valid_width * (double)l;
                }
            } else {
                temp += (double)l* l;
            }
        }
        return temp;
    }

    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        double tot_area = 0.0;
        for (int i = 0; i < n; i++) {
            tot_area += (double)(squares[i][2] * (double)squares[i][2]);
        }

        double low = 0.0;
        double high = 2e9;
        double precision = 1e-5;

        while (high - low > precision) {
            double mid = low + (high - low) / 2.0;
            double below_area = area(squares, mid);

            if (2.0 * below_area >= tot_area) {
                high = mid;
            } else {
                low = mid;
            }
        }
        return low;
    }
};

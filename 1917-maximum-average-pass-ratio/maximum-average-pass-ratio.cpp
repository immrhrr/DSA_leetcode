#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
        int n = classes.size();

        // Define a max-heap to prioritize the class with the maximum marginal gain
        auto gain = [](const pair<int, int>& a) {
            double current = (double)a.first / a.second;
            double after = (double)(a.first + 1) / (a.second + 1);
            return after - current; // Marginal gain
        };

        priority_queue<pair<double, pair<int, int>>> pq;

        // Push all classes into the max-heap with their current marginal gain
        for (int i = 0; i < n; i++) {
            double marginal_gain = gain({classes[i][0], classes[i][1]});
            pq.push({marginal_gain, {classes[i][0], classes[i][1]}});
        }

        // Allocate extra students to maximize the overall pass ratio
        while (extra > 0) {
            auto it = pq.top();
            pq.pop();

            int pass = it.second.first;
            int total = it.second.second;

            // Update the class after adding one student
            pass++;
            total++;
            double new_marginal_gain = gain({pass, total});
            pq.push({new_marginal_gain, {pass, total}});

            extra--;
        }

        // Calculate the final average pass ratio
        double ans = 0.0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int pass = it.second.first;
            int total = it.second.second;
            ans += (double)pass / total;
        }

        return ans / n;
    }
};
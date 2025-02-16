class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        long long ans=0;
        int n=pizzas.size();
      // priority_queue<int>pq(pizzas.begin(),pizzas.end());
       sort(pizzas.begin(),pizzas.end());
       int idx=n-1;
        int days=n/4;
        int odd_days=(days+1)/2;
        int even_days=days-odd_days;
        for(int i=0;i<odd_days;i++){
            ans+=pizzas[idx];
            idx--;
            // ans+=pq.top();
            // pq.pop();
        }
        for(int i=0;i<even_days;i++){
            idx--;
            ans+=pizzas[idx--];
            // pq.pop();
            // ans+=pq.top();
            // pq.pop();
        }
        return ans;
    }
};
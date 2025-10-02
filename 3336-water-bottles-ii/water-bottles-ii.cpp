class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int empties = numBottles;
        
        while (empties >= numExchange) {
            // use exactly numExchange empties to get 1 full bottle
            empties -= numExchange;
            // you get 1 full bottle, drink it
            ans += 1;
            // that drinking gives you 1 empty bottle
            empties += 1;
            // cost increases for next time
            numExchange += 1;
        }
        
        return ans;
    }
};

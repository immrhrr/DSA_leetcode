class Solution {
public:
    bool isAvl(int seat, auto& bookedSeats){
         bool avl=true;
           if( bookedSeats.find(seat)!=bookedSeats.end())
           avl=false;
           return avl;

    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>>mp;
        for(auto it:reservedSeats){
            mp[it[0]].insert(it[1]);
        }
        int ans=(n-mp.size())*2;
        for(auto& [row,bookedSeats]:mp){
           if(isAvl(2,bookedSeats)&&isAvl(3,bookedSeats)&&isAvl(4,bookedSeats)&&isAvl(5,bookedSeats)&&isAvl(6,bookedSeats)&&isAvl(7,bookedSeats)&&isAvl(8,bookedSeats)&&isAvl(9,bookedSeats))
           ans+=2;
           else if(isAvl(2,bookedSeats)&&isAvl(3,bookedSeats)&&isAvl(4,bookedSeats)&&isAvl(5,bookedSeats))
           ans+=1;
           else if(isAvl(4,bookedSeats)&&isAvl(5,bookedSeats)&&isAvl(6,bookedSeats)&&isAvl(7,bookedSeats))
           ans+=1;
           else if(isAvl(6,bookedSeats)&&isAvl(7,bookedSeats)&&isAvl(8,bookedSeats)&&isAvl(9,bookedSeats))
           ans+=1;

        }
        return ans;
    }
};
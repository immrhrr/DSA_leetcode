class MyCalendarThree {
public:
    int maxi=0;
    map<int,int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;
        int temp=0;
        for(auto it:mp){
            temp+=it.second;
            maxi=max(maxi,temp);
        }
        return maxi;
        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
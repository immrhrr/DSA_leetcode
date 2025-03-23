class Solution {
public:
    long long minTime(vector<int>& skills, vector<int>& mana) {
        int s=skills.size();
        int m=mana.size();
        vector<pair<long long,long long>>temp(s);
        //first itteration
        temp[0]={0,mana[0]*skills[0]};
         for(int i=1;i<s;i++){
                long long start=temp[i-1].second;
                long long end=start+mana[0]*skills[i];
                 temp[i]={start,end};
            }

        for(int i=1;i<m;i++){
                long long start=temp[0].second;
                long long end=start+mana[i]*skills[0];
                temp[0]={start,end};
            for(int j=1;j<s;j++){
                 start=temp[j-1].second;
                 start=max(start,temp[j].second);
                 //start = max(0LL, end - mana[i] * skills[j]);  
                 end=start+mana[i]*skills[j];
                temp[j]={start,end};
                //forward
            }
            for(int j=s-2;j>=0;j--){
                end=temp[j+1].first;
                start=end-mana[i]*skills[j];
                temp[j]={start,end};
            }
        }
        return temp[s-1].second;
        
    }
};
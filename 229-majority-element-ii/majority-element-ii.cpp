class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0;
        int cnt2=0;
        int mj1=NULL,mj2=NULL;
        for(int i=0;i<n;i++){
           if(nums[i]==mj1){
            cnt1++;
           }
           else if(nums[i]==mj2){
            cnt2++;
           }
           else if(cnt1==0){
            mj1=nums[i];
            cnt1++;
           }
           else if(cnt2==0){
            mj2=nums[i];
            cnt2++;
           }
           else{
            cnt1--;
            cnt2--;
           }
        }
        vector<int>ans;
        int frq1=0;
        int frq2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==mj1){
                frq1++;
            }
            else if(nums[i]==mj2){
                frq2++;
            }
        }
        if(frq1>floor(n/3)){
            ans.push_back(mj1);
        }

          if(frq2>floor(n/3)){
            ans.push_back(mj2);
        }
        return ans;
    }
};

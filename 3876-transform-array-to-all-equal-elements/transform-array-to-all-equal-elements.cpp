class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n=nums.size();
       //check if all are equal
        int p=0;
        for(int i=0;i<n;i++){
            if(nums[i]>0)p++;
        }
        if(p==0||p==n)return true;
        //try making them as 1
        int ans1=0;
        vector<int>temp(n);
        temp=nums;
        for(int i=0;i<n-1;i++){
            if(nums[i]==-1){
                nums[i]==1;
                nums[i+1]=-nums[i+1];
                ans1++;
            }
        }
        if(nums[n-1]==1&&ans1<=k)return true;
        int ans2=0;
        for(int i=0;i<n-1;i++){
            if(temp[i]==1){
                temp[i]==-1;
                temp[i+1]=-temp[i+1];
                ans2++;
            }
        }
        if(temp[n-1]==-1&&ans2<=k)return true;
        return false;


        
    }
};
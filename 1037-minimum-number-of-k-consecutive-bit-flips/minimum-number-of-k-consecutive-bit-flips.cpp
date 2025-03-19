class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        vector<bool>flipped(n,false);
        int cnt=0;
        int temp=0;
        for(int i=0;i<n;i++){
            int last=i-k;
            if(last>=0&&flipped[last])temp--;
            if((temp%2==0&&nums[i]==0)||(temp%2==1&&nums[i]==1)){
                if(i+k>n){
                    return -1;
                }
                cnt++;
                flipped[i]=true;
                temp++;
            }
        }
        return cnt;
    }
};
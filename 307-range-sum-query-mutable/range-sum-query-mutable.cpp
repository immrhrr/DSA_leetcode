class NumArray {
public:
    vector<int>seg;
    vector<int>arr;
    int N;

    NumArray(vector<int>& nums) {
        arr=nums;
        int n=arr.size();
        N=n;
        seg.resize(4*n,0);
        build(0,0,N-1);
    }

    void build(int idx,int l,int r){
        if(l==r){
            seg[idx]=arr[l];
            return;
        }
        int mid=l+(r-l)/2;
        build(2*idx+1,l,mid);
        build(2*idx+2,mid+1,r);
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
        return;
    }


    void change(int idx,int l,int r,int index,int val){
        if(l==r){
            seg[idx]=val;
            return;
        }
       int mid=l+(r-l)/2;
       //go left
       if(mid>=index){
        change(2*idx+1,l,mid,index,val);
       }
       //go right
       else{
         change(2*idx+2,mid+1,r,index,val);
       }
       seg[idx]=seg[2*idx+1]+seg[2*idx+2];
       return;
    }
    void update(int index, int val) {
        change(0,0,N-1,index,val);
    }
    int find(int idx,int left,int right,int l,int r){
        if(l>right||r<left){
            return 0;
        }
        else if(l>=left&&r<=right){
            return seg[idx];
        }
        int mid=l+(r-l)/2;
        return find(2*idx+1,left,right,l,mid)+find(2*idx+2,left,right,mid+1,r);
    }
    int sumRange(int left, int right) {
        return find(0,left,right,0,N-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
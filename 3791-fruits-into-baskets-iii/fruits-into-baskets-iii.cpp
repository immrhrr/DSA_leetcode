class Solution {
public:
    vector<int> seg_tree;
    void build_seg_tree(vector<int>& baskets, int ind, int l, int r) {
        if (l == r) {
            seg_tree[ind] = baskets[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build_seg_tree(baskets, 2 * ind + 1, l, mid);
        build_seg_tree(baskets, 2 * ind + 2, mid + 1, r);
        seg_tree[ind] = max(seg_tree[2 * ind + 1], seg_tree[2 * ind + 2]);
        return;
    }
    bool query(int fruit, int ind, int l, int r) {
        if (seg_tree[ind] < fruit) {
            return false;
        }
        if(l==r){
            seg_tree[ind]=-1;
            return true;
        }
        int mid = l + (r - l) / 2;
        bool placed = false;
        if (seg_tree[2 * ind + 1] >= fruit) {
            placed = query(fruit, 2 * ind + 1, l, mid);
        }
        else{
            placed=query(fruit,2*ind+2,mid+1,r);
        }
        seg_tree[ind]=max(seg_tree[2*ind+1],seg_tree[2*ind+2]);
        return placed;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        seg_tree.resize(4*n, 0);
        build_seg_tree(baskets, 0, 0, n - 1);
        int un_placed = 0;
        for (int fruit : fruits) {
            if (query(fruit, 0, 0, n - 1) == false) {
                un_placed++;
            }
        }
        return un_placed;
    }
};
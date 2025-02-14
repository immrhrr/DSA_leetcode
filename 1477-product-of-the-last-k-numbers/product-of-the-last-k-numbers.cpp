
class ProductOfNumbers {
public:

    //int pref[1000000];
    vector<int>pref;
    int index=0;
    ProductOfNumbers() {
        
    }
    void add(int num) {
        if(num==0){
            index=0;
            pref={};
            return;
        }
        if(index==0){
            pref.push_back(num);
           //pref[index]=num;
            index++;
        }
        else{
            pref.push_back(pref[index-1]*num);
            //pref[index]=pref[index-1]*num;
            index++;
        }
        return;   
    }
    int getProduct(int k) {
        if(index-k<0||index==0){
            return 0;
        }
        int tot=pref[index-1];
        int divide=1;
        if(index-k-1>=0){
            divide=pref[index-k-1];
        }
        return tot/divide;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
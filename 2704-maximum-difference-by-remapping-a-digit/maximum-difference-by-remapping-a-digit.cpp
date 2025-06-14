class Solution {
public:
    int minMaxDifference(int num) {
        //how to make max->from left find the first digit which is not 9
        //how to make min->from the left find the first digit which is not 0
        //step1:
        int maxi=num;
        string s=to_string(num);
        char remap='#';
        int n=s.size();
        for(int i=0;i<s.size();i++){
            if(s[i]!='9'){
                remap=s[i];
                break;
            }
        }
        string temp=s;
        for(int i=0;i<n;i++){
            if(s[i]==remap){
                temp[i]='9';
            }
        }
        maxi=stoi(temp);
        //step2:
        int mini=num;
        s=to_string(num);
        remap='#';
        for(int i=0;i<n;i++){
            if(s[i]!='0'){
                remap=s[i];
                break;
            }
        }
        temp=s;
        for(int i=0;i<n;i++){
            if(s[i]==remap){
                temp[i]='0';
            }
        }
        mini=stoi(temp);
        return maxi-mini;

        
    }
};
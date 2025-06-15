class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int n = s.size();

        int maxi = num;
        int mini = num;
        // first char which is not 9 i will chosse that for maxi
        char max_ch = '#';
        for (int i = 0; i < n; i++) {
            if (s[i] != '9') {
                max_ch = s[i];
                break;
            }
        }
        if (max_ch != '#') {
            for (int i = 0; i < n; i++) {
                if (s[i] == max_ch) {
                    s[i] = '9';
                }
            }
            maxi=stoi(s);
        }
        //for making mini we can use zero only if that digit is not present at 0th index
        //if the oth digit is 1 then make some other digit as 0
        //if the 0th digit is not 1 then make it 1
        s=to_string(num);
        if(s[0]!='1'){
            char min_ch=s[0];
            for(int i=0;i<n;i++){
                if(s[i]==min_ch){
                    s[i]='1';
                }
            }
            mini=stoi(s);
        }
        else{
            char min_ch='#';
            for(int i=1;i<n;i++){
                if(s[i]!='1'&&s[i]!='0'){
                    min_ch=s[i];
                    break;
                }
            }
            for(int i=0;i<n;i++){
                if(s[i]==min_ch){
                    s[i]='0';
                }
            }
            mini=stoi(s);
        }
        return maxi-mini;
        

    }
};
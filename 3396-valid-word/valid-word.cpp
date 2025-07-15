class Solution {
public:
    bool isValid(string word) {
        int n=word.size();
        //step1
        if(n<3)return false;
        unordered_set<char>st;
        for(char ch='0';ch<='9';ch++){
            st.insert(ch);
        }
        for(char ch='a';ch<='z';ch++){
            st.insert(ch);
        }
        for(char ch='A';ch<='Z';ch++){
            st.insert(ch);
        }
        //step2
        for(int i=0;i<n;i++){
            if(st.find(word[i])==st.end()){
                return false;
            }
        }
        unordered_set<char>vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');
        vowels.insert('A');
        vowels.insert('E');
        vowels.insert('I');
        vowels.insert('O');
        vowels.insert('U');
        bool flag_vowel=false;
        for(int i=0;i<n;i++){
            if(vowels.find(word[i])!=vowels.end()){
                flag_vowel=true;
                break;
            }
        }
        if(!flag_vowel)return false;
        unordered_set<char>consonant;
        for(int i=0;i<26;i++){
            char ch1=('a'+i);
            char ch2=('A'+i);
            if(vowels.find(ch1)==vowels.end()){
                consonant.insert(ch1);
                consonant.insert(ch2);
            }
        }
        bool flag_consonant=false;
        for(int i=0;i<n;i++){
            if(consonant.find(word[i])!=consonant.end()){
                flag_consonant=true;
                break;
            }
        }
        return flag_consonant;
    }
};
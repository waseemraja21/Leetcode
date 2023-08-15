class Solution {
    bool func(int i, int j, string& nS){
        if(i >= j){
            return true;
        }
        
        if(nS[i] != nS[j]){
            return false;
        }
        return func(i+1, j-1, nS);
    }
public:
    bool isPalindrome(string s) {
        // converting it to a plain text
        string nS="";
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if(ch >= 'a' && ch <= 'z' || ch >='A' && ch <= 'Z' || ch >= '0' && ch <= '9'){
                if(ch >='A' && ch <= 'Z'){
                    ch = ch-'A'+'a';
                }
                nS += ch;
            }
        }
        int i=0, j=nS.size()-1;
        // checking recursively
        return func(i, j, nS);
        
    }
};
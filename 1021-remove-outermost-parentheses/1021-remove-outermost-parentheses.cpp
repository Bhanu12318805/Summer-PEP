class Solution {
public:
    string removeOuterParentheses(string s) {
        string r;
        int open =0;
        for(char a: s){
            if(a == '(' && open++ >0){
                r += a;
            }
            if(a == ')' && open-- >1){
                r += a;
            }
        }
        return r;
    }
};
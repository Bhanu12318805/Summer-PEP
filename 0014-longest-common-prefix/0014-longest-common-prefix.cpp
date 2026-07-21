class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int minlength = strs[0].size();
        for(int i = 1; i< strs.size();i++){
            minlength = min(minlength, int(strs[i].size()));
        }
        for(int i=0;i<minlength;i++){
            char ch = strs[0][i];
            for(int j = 1; j< strs.size(); j++){
                if(strs[j][i] != ch) return prefix;
            }

            prefix += ch;
        }
        return prefix;
    }
};
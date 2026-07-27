class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0){
            return {};
        }
        if(numRows == 1){
            return {{1}};
        }
        vector<vector<int>>previousrow = generate(numRows -1);
        vector<int>newrow(numRows, 1);
        for(int i=1;i < numRows -1;i++){
            newrow[i] = previousrow.back()[i] + previousrow.back()[i-1];
        }
        previousrow.push_back(newrow);
        return previousrow;
    }
};
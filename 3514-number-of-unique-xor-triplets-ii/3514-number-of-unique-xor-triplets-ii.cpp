class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int mx = (*max_element(nums.begin(), nums.end())) << 1;
        vector<bool>pairXor(mx, false);
        for(int x : nums){
            for(int y : nums){
                pairXor[x ^ y] = true;
            }
        }
        vector<int> seen(mx, 0);
        for(int a =0;a < mx;a++){
            if(pairXor[a]){
                for(int z : nums){
                    seen[a ^ z] =1;
                }
            }
        }
        return accumulate(seen.begin(), seen.end(), 0);
    }
};
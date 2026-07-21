class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int indx = 0;
        int b=0;
        for(int i=0;i<nums.size()-1;i++){
            b = max(b, i+ nums[i]);
        
            if(i ==indx){
                ans++;
                indx = b;
            }
        }
        return ans;
    }
};
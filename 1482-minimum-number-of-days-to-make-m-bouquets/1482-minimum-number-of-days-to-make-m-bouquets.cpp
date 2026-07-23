class Solution {
private:
    bool solve(vector<int>& bloomDay, int m, int k, int n){
        int guldasta =0, fool = 0;

        for(auto it: bloomDay){
            if(it <= n){
                fool++;
                if(fool == k){
                    guldasta++;
                    fool =0;
                }
                
            }else{
                fool =0;
            }
        }
        return (guldasta >= m);
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k > (long long)bloomDay.size()) return - 1;
        int n = bloomDay.size();
        int l = 1, h = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(l <= h){
            int mid = l + (h - l)/ 2;
            if(solve(bloomDay, m, k, mid)){
                ans = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};
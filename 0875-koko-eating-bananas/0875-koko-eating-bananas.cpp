class Solution {
private:
    bool canEat(vector<int> &piles, int h, int speed){
        double hrs = 0;
        cout<<"Speed: "<<speed<<endl;
        for(int i = 0; i<piles.size(); i++){
            hrs += ceil((double)piles[i] / (double)speed);
        }
        cout<<hrs<<endl;
        return (hrs <= h);
    }




public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, hi= *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while(l <= hi){
            int mid = l + (hi - l) / 2;
            if(canEat(piles, h, mid)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};
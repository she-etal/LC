class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int buy=0;
        sort(cost.begin(), cost.end());
        int ans=0;
        for(int i=n-1; i>=0; i--){
            if(buy==2){
                buy=0;
            }
            else{
                ans += cost[i];
                buy++;
            }
        }
        return ans;
    }
};
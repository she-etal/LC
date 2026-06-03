class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n1 = landStartTime.size();
        int land=1e9;
        for(int i=0; i<n1; i++){
            land = min(land, landStartTime[i]+landDuration[i]);
        }
        int n2 = waterStartTime.size();
        int ans=1e9;
        int water=1e9;

        for(int i=0; i<n2; i++){
            water = min(water, waterStartTime[i]+waterDuration[i]);
            ans = min(ans, max(land, waterStartTime[i])+waterDuration[i]);
        }

        for(int i=0; i<n1; i++){           
            ans = min(ans, max(water, landStartTime[i])+landDuration[i]);
        }
        return ans;
    }
};
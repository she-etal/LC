class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        // int n1 = landStartTime.size();
        // int n2 = waterStartTime.size();

        // vector<pair<int, int>> v1;
        // for(int i=0; i<n1; i++){
        //     v1.push_back({landStartTime[i], landDuration[i]});
        // }
        // sort(v1.begin(), v1.end(), compare);

        // vector<pair<int, int>> v2;
        // for(int i=0; i<n2; i++){
        //     v2.push_back({waterStartTime[i], waterDuration[i]});
        // }
        // sort(v1.begin(), v1.end(), compare);

        int ans=1e9;

        for(int i=0; i<landStartTime.size(); i++){
            int temp = landStartTime[i] + landDuration[i];
            for(int j=0; j<waterStartTime.size(); j++){
                int diff = temp - waterStartTime[j];
                int temp2=1e9;
                if(diff>=0){
                    temp2 = temp + waterDuration[j];
                }
                else{
                    temp2 = temp + abs(diff) + waterDuration[j];;
                }
                ans = min(ans, temp2);
            }
        }

        for(int i=0; i<waterStartTime.size(); i++){
            int temp = waterStartTime[i] + waterDuration[i];
            for(int j=0; j<landStartTime.size(); j++){
                int diff = temp - landStartTime[j];
                int temp2=1e9;
                if(diff>=0){
                    temp2 = temp + landDuration[j];
                }
                else{
                    temp2 = temp + abs(diff) + landDuration[j];;
                }
                ans = min(ans, temp2);
            }
        }
        return ans;
    }
};
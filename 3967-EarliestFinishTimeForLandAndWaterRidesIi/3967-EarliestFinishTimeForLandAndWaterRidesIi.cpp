// Last updated: 6/20/2026, 5:07:01 PM
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {

        vector<pair<int,int>> water, land;

        for(int i=0;i<waterStartTime.size();i++){
            water.push_back({waterStartTime[i], waterDuration[i]});
        }

        for(int i=0;i<landStartTime.size();i++){
            land.push_back({landStartTime[i], landDuration[i]});
        }

        sort(water.begin(), water.end());
        sort(land.begin(), land.end());

        int m = water.size();
        int n = land.size();

        vector<int> preWaterDur(m), sufWater(m);
        vector<int> preLandDur(n), sufLand(n);

        preWaterDur[0] = water[0].second;
        for(int i=1;i<m;i++){
            preWaterDur[i] = min(preWaterDur[i-1], water[i].second);
        }

        sufWater[m-1] = water[m-1].first + water[m-1].second;
        for(int i=m-2;i>=0;i--){
            sufWater[i] = min(sufWater[i+1],
                              water[i].first + water[i].second);
        }

        preLandDur[0] = land[0].second;
        for(int i=1;i<n;i++){
            preLandDur[i] = min(preLandDur[i-1], land[i].second);
        }

        sufLand[n-1] = land[n-1].first + land[n-1].second;
        for(int i=n-2;i>=0;i--){
            sufLand[i] = min(sufLand[i+1],
                             land[i].first + land[i].second);
        }

        long long ans = LLONG_MAX;

        for(int i=0;i<n;i++){

            long long landFinish = 1LL*land[i].first + land[i].second;

            int idx = upper_bound(water.begin(), water.end(),
                                  make_pair((int)landFinish, INT_MAX))
                                  - water.begin() - 1;

            if(idx>=0){
                ans = min(ans, landFinish + preWaterDur[idx]);
            }

            if(idx+1<m){
                ans = min(ans, (long long)sufWater[idx+1]);
            }
        }

        for(int i=0;i<m;i++){

            long long waterFinish = 1LL*water[i].first + water[i].second;

            int idx = upper_bound(land.begin(), land.end(),
                                  make_pair((int)waterFinish, INT_MAX))
                                  - land.begin() - 1;

            if(idx>=0){
                ans = min(ans, waterFinish + preLandDur[idx]);
            }

            if(idx+1<n){
                ans = min(ans, (long long)sufLand[idx+1]);
            }
        }

        return (int)ans;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxCur = 0, minUntil = INT_MAX;
       for(int i = 0; i<prices.size();i++){minUntil = min(minUntil,prices[i]);maxCur = max(maxCur,prices[i]-minUntil);}return maxCur;
    }
};
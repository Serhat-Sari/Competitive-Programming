class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<vector<int > > ans(rowIndex+1);

        if(rowIndex == 0){ ans[0].push_back(1);return ans[0];}

         for(int i = 0; i <= rowIndex; i++){
            ans[i].push_back(1);
        }
        ans[1].push_back(1);
        if(rowIndex == 1) return ans[1];

        for(int i = 2; i<=rowIndex;i++){
            for(int j = 0; j< i-1;j++){
                ans[i].push_back(ans[i-1][j] + ans[i-1][j+1]);
            }
            ans[i].push_back(1);
        }
        return ans[rowIndex];
    }
};
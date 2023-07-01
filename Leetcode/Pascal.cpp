#include <bits/stdc++.h>
using namespace std;

int main(){
    int numRows;cin>>numRows;
    vector<vector<int> > ans(numRows);

        for(int i = 0; i < numRows; i++){
            ans[i].push_back(1);
        }
        ans[1].push_back(1);
        for(int i = 2; i<numRows;i++){
            for(int j = 0; j< i-1;j++){
                ans[i].push_back(ans[i-1][j] + ans[i-1][j+1]);
            }
            ans[i].push_back(1);
        }
        for(int i = 0; i<numRows;i++){
            for(int j = 0; j<ans[i].size();j++){
                cout << ans[i][j] << " ";
            }
            cout << '\n';
        }
        return 0;
        
}
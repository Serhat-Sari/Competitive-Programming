#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i<n;i++){
        int input;
        cin >> input;
        arr[i] = input;
    }
    int windowSum = 0, maxSum = 0;
    for(int i = 0; i<k; i++){
        windowSum += arr[i];
    }
    for(int i = k; i < n;i++){
        windowSum += arr[i] - arr[i-k];
        maxSum = max(maxSum,windowSum);
    }
    cout << maxSum;
}
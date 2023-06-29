#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums;
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    int size = nums.size();
    int leftIndex = size/2, rightIndex = size/2;
    if(size == 1) return nums[0];
    else if( size == 2) return nums[0]>nums[1]?nums[1]:nums[0];
    else{
        while(true){

            if(nums[leftIndex-1] > nums[leftIndex]){
                cout << leftIndex ; return 0;}

            if(nums[rightIndex+1] < nums[rightIndex]){
                cout << rightIndex + 1; return 0;}

            if(leftIndex == 0 || rightIndex == size-1) break;

            leftIndex--;
            rightIndex++;
        }
        if(leftIndex == 0)
            cout << rightIndex + 1;

        else cout << leftIndex-1;
    }
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

void binary(int *arr ,int size, int key){

	int left = 0, right = size,mid;

	while(left < right ){
		
		mid = (left+right)/2;
		
		if(arr[mid] >= key){
			right = mid;
		}
		else{
			left = mid +1;
		}
	
		
		
	}
	if( arr[left] == key )
		cout << left<< endl;
	else
		cout << -1<<endl;
}


int main(){
	
	int n,i;
	cin >> n >> i;
	int arr[n];
	for(int i = 0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr,arr+n);
	
	
	binary(arr,n,i);
	
	
	
	
	
}
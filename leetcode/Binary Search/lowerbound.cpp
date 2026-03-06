
#include<iostream>
using namespace std;
#include<vector>
#include<climits>

int lowerBound(vector<int> arr, int n, int x) {
	int s = 0, e = n-1;
	int ans = n;
	while(s<=e) {
		int mid = s + (e-s)/2;
		if(arr[mid] >= x) {
			ans = mid;
			e = mid-1;
		}
		else{
			s = mid + 1;
		}
	}
	return ans;
}
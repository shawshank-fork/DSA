
#include<iostream>
using namespace std;
#include<vector>
#include<climits>

int numberOfGasStations(long double dist, vector<int> &arr) {
	int cnt = 0;
	int n = arr.size();
	for(int i = 1; i < n; i++) {
		int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
		if((arr[i] - arr[i - 1]) / dist == numberInBetween * dist) {
			numberInBetween--;
		}
		cnt += numberInBetween;
	}
	return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	long double s = 0;
	long double e = 0;
	for(int i = 0; i < n-1; i++) {
		e = max( e, (long double)(arr[i+1] - arr[i]));
	} 

	long double diff = 1e-6;
	while(e-s > diff) {
		long double mid = s + (e-s)/(2.0);
		int cnt = numberOfGasStations(mid, arr);
		if(cnt > k) {
			s = mid;
		}
		else{
			e = mid;
		}
	}
	return e;
}

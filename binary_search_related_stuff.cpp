#include <bits/stdc++.h>
#define ll long long
#define IO \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);
#define MOD 1000000007
using namespace std;

int bin_search(vector<int> &a, int e){
	int n = a.size(), lo = 0, hi = n-1;
	while(lo <= hi){
		int mid = lo + (hi-lo)/2;
		if(a[mid] == e) return mid+1;
		else if(a[mid] < e) lo = mid+1;
		else hi = mid-1;
	}
	return -1;
}

int perfect_square(int x){
	int lo = 0, hi = 1e9;
	while(lo <= hi){
		int mid = lo + (hi-lo)/2;
		ll sq = (ll)mid*mid;
		if(sq == x) return mid;
		else if(sq < x) lo = mid+1;
		else hi = mid-1;
	}
	return -1;
}

int lb(vector<int> &a, int x){
	int n = a.size(), lo = 0, hi = n-1, ans = -1;
	while(lo <= hi){
		int mid = lo + (hi-lo)/2;
		if(a[mid] >= x){
			ans = a[mid];
			hi = mid - 1;
		}
		else lo = mid+1;
	}
	return ans;
}

int find_in_rotated_array(vector<int> &a){
	int n = a.size(), lo = 0, hi = n-1;
	if(n==1 || a[0]<=a[n-1]) return a[0];
	if(n==2) return min(a[0], a[1]);
	while(lo <= hi){
		int mid = lo + (hi-lo)/2;
		if(a[mid]<a[(mid-1)%n] && a[mid]<a[(mid+1)%n]) return a[mid];
		else if(a[mid]>=a[0] && a[mid]>a[n-1]) lo = mid+1;
		else hi = mid-1;
	}
	return -1;
}

int max_in_increasing_then_decreasing_array(vector<int> &a){
	int n = a.size(), lo = 0, hi = n-1;
	while(lo <= hi){
		int mid = lo + (hi-lo)/2;
		if(a[mid]>a[(mid-1)%n] && a[mid]>a[(mid+1)%n]) return a[mid];
		else if(a[mid]<a[(mid+1)%n]) lo = mid+1;
		else hi = mid-1;
	}
}

double sqrt(int x){
	int poss_ans = perfect_square(x);
	if(poss_ans == -1){
		double lo = 0, hi = x, mid;
		while(hi-lo > 1e-9){
			mid = lo + (hi-lo)/2;
			double sq = mid*mid;
			if(sq > x) hi = mid;
			else lo = mid;
		}
		return (int)mid;
	}
	else return (int)poss_ans;
}

int ep(vector<int> &a, int x){
	int n = a.size(), lo = 0, hi = n-1, ans = -1;
	while(lo <= hi){
		int mid = lo + (hi-lo)/2;
		if(a[mid] == x){
			ans = mid;
			lo = mid+1;
		}
		else if(a[mid] < x) lo = mid+1;
		else hi = mid-1;
	}
	return ans;
}

int sp(vector<int> &a, int x){
	int n = a.size(), lo = 0, hi = n-1, ans = -1;
	while(lo <= hi){
		int mid = lo + (hi-lo)/2;
		if(a[mid] == x){
			ans = mid;
			hi = mid-1;
		}
		else if(a[mid] > x) hi = mid-1;
		else lo = mid+1;
	}
	return ans;
}

void solve(){
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin>>a[i];
	// sort(a.begin(), a.end());
	cout<<sqrt(n);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	IO;
	// cout<<fixed<<setprecision(10);
	int t = 1;
	//cin>>t;
	for(int i=1; i<=t; i++){
		//cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
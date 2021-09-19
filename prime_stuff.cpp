#include<bits/stdc++.h>
#define ll long long
#define IO \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);
#define CP \
	ios::sync_with_stdio(0); \
	cin.tie(0);
using namespace std;

float squareRoot(double n){
	double lo = 0, hi = INT_MAX, mid = -1;
	while((hi - lo) > 1e-4){
		mid = lo + (hi - lo)/2;
		if(mid*mid == n) return mid;
		else if(mid*mid > n) hi = mid;
		else lo = mid;
	}
	return mid;
}

vector<int> get_primeList(int n){
	vector<int> primeList;
	bool *isComposite = (bool*)malloc(sizeof(bool)*(n+1));
	isComposite[0] = isComposite[1] = 1;
	for(int i=2; i*i<=n; i++){
		if(!isComposite[i]){
			for(int j=i*i; j<=n; j+=i) isComposite[j] = 1;
		}
	}
	for(int i=2; i<=n; i++) if(!isComposite[i]) primeList.push_back(i);
	delete isComposite;
	return primeList;
}

int main(){
	IO;
	cout << fixed << setprecision(2);
	double value; cin >> value;
	cout << "Largest prime factor of " << (ll)value << " is ";
	vector<int> primeList = get_primeList((int)squareRoot(value));
	ll n = (ll)value;
	int p = 0, ans = 0;
	while(n != 1){
		while(n%primeList[p] == 0) n /= primeList[p], ans = primeList[p];
		p++;
	}
	cout << ans << "\n";
	return 0;
}
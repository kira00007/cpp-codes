#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

void CP(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

void LongestCommonSubstring(string &s1, string &s2){
    int l1 = s1.length(), l2 = s2.length();
    vector<vector<int>> dp(l1, vector<int>(l2));
    int ans = 0, st1 = 0, st2 = 0;
    string longest_common_substring; 
    for(int i=0; i<l1; i++) for(int j=0; j<l2; j++){
        if(!i && !j) continue;
        dp[i][j] = (s1[i]==s2[j]?((i&&j)?(dp[i-1][j-1]+1):1):0);
        if(dp[i][j] > ans){
            ans = dp[i][j];
            longest_common_substring = s1.substr(i - (ans-1), ans);
            st1 = i - (ans-1), st2 = j - (ans-1);
        }
    }
    cout << "Length of longest common substring: " << ans << "\n"
        << "Longest common substring: " << longest_common_substring << "\n"
        << "starting index in string1: " << st1 << "\nstarting index in string2: " << st2 << "\n";
}

void LongestCommonSubsequence(string &s1, string &s2){
    int l1 = s1.length(), l2 = s2.length();
    vector<vector<int>> dp(l1, vector<int>(l2));
    for(int i=0; i<l1; i++) for(int j=0; j<l2; j++){
        if(s1[i] == s2[j]) dp[i][j] = ((i&&j)?dp[i-1][j-1]:0) + 1;
        else dp[i][j] = max(i?dp[i-1][j]:0, j?dp[i][j-1]:0);
    }
    cout << "Length of longest common subsequence: " << dp[l1-1][l2-1] << "\n";
}

int main(){
    CP();
    string s1, s2; cin >> s1 >> s2;
    LongestCommonSubstring(s1, s2);
    LongestCommonSubsequence(s1, s2);
    return 0;
}
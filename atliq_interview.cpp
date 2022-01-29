#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <algorithm>

std::string remove_duplicate_in_order(const std::string &str) { // time_coplexity: O(nlogn) :: space_complexity: O(n) :: n -> str.size()
	std::string ans;
	std::set<char> seen;
	for(char ch : str) {
		char temp_ch = ((ch>='A' && ch<='Z') ? ch+32 : ch);
		if(seen.find(temp_ch) == seen.end()) {
			ans.push_back(ch);
			seen.insert(temp_ch);
		}
	}
	return ans;
}

std::vector<std::vector<int>> merge_intervals(std::vector<std::vector<int>> &intervals) { // time_complexity: O(nlogn) :: space_complexity: O(n) :: n -> intervals.size()
	sort(intervals.begin(), intervals.end());
	std::vector<std::vector<int>> ans;
	ans.push_back(intervals[0]);
	for(int i = 1; i < (int)intervals.size(); i++) {
		std::vector<int> &interval = ans.back();
		if(interval[1] >= intervals[i][0])
			interval[1] = std::max(interval[1], intervals[i][1]);
		else
			ans.push_back(intervals[i]);
	}
	return ans;
}

int main() {
	// std::vector<std::vector<int>> intervals = {
	// 	{0, 4},
	// 	{4, 10},
	// 	{11, 13},
	// 	{12, 15},
	// 	{15, 17},
	// };
	// std::vector<std::vector<int>> intervals = {
	// 	{0, 9},
	// 	{2, 4},
	// 	{0, 3},
	// };
	std::vector<std::vector<int>> intervals = {
		{1, 3},
		{2, 6},
		{8, 10},
		{9, 11},
		{10, 12},
		{2, 4},
		{15, 18},
	};
	std::vector<std::vector<int>> ans = merge_intervals(intervals);
	for(const auto &interval : ans)
		std::cout << interval[0] << ' ' << interval[1] << '\n';
	std::cout << remove_duplicate_in_order("sAmOSA") << '\n';
	std::cout << remove_duplicate_in_order("InFIniTy") << '\n';
	std::cout << remove_duplicate_in_order("WELcoMe") << '\n';
	return 0;
}

/*
Problem 2:
Given a collection of intervals, merge all overlapping intervals.

Input: [[1,3],[2,6],[8,10], [9,11] ,[10,12], [2,4] ,[15,18]]

Output: [[1,6],[8,12],[15,18]]
*/
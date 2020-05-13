// C++ program to show segment tree operations like construction, query
// and update
#include <bits/stdc++.h>
using namespace std;

// brute force : O(n^2)
int lengthOfLongestSubstringI(string s) {
	int n = s.length();

	int maxSize = 0;
	for(int i = 0; i < n; i++){
		unordered_set<char> visited{};

		int j = i;
		while(!visited.count(s[j]) && j < n){
			visited.insert(s[j]);
			j++;
		}

		int temp = visited.size();
		maxSize = max(maxSize, temp);
	}

	return maxSize;
}

// using sliding window technique : O(n)
int lengthOfLongestSubstringII(string s) {
	int n = s.length();
	int ptr_1 = 0, ptr_2 = 0;

	unordered_set<char> visited;
	int maxLen = 0;
	while(ptr_2 < n){
		if(ptr_1 == ptr_2){
			ptr_2++;
			continue;
		}

		if(s[ptr_1] != s[ptr_2] && !visited.count(s[ptr_2])){
			visited.insert(s[ptr_2]);
			ptr_2++;
		}
		else{
			maxLen = max(maxLen, ptr_2 - ptr_1);
			visited.erase(s[ptr_1]);
			ptr_1++;
		}
	}

	maxLen = max(maxLen, ptr_2 - ptr_1);
	return maxLen;
}

// efficient solution
int lengthOfLongestSubstringIII(string s){
	vector<int> visited(256, -1);

	int maxLength = 0, start = -1;
	for(int i = 0; i < s.length(); i++){
		if(visited[s[i]] > start)
			start = visited[s[i]];

		visited[s[i]] = i;
		maxLength = max(maxLength, i - start);
	}

	return maxLength;
}

// Driver functions
int main(){
	// string str = "abcabcbb";
	string str = "";
	// string str = " ";
    // string str = "aab";
    // string str = "bbbbb";
    // string str = "pwwkew";
    // string str = "dvdf";

	cout << lengthOfLongestSubstringIII(str) << endl;

	return 0;
}

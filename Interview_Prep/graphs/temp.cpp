// C++ program to print DFS traversal for a given given graph
#include<bits/stdc++.h>
using namespace std;

int main(){
	set<pair<int, int>> st;
	st.insert({1, 2});
	// st.insert({2, 1});
	// st.insert({3, 4});
	// st.insert({8, 3});
	// st.insert({9, 1});

	// auto it = st.find({2, 1});
	if(st.find({2, 1}) != st.end())
		cout << 1 << endl;
	return 0;
}

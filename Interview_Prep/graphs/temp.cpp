/*
    Topological sort
    https://www.geeksforgeeks.org/topological-sorting/

    tc : O(V + E)
    sc : O(V), stack
*/
#include <bits/stdc++.h>
using namespace std;

// Driver function
int main(){
	list<pair<int, int>> *st = new list<pair<int, int>>[2];

	st[0].push_back({1, 2});
	st[0].push_back({3, 6});
	st[0].push_back({7, 2});

	st[1].push_back({2, 3});

	for(int i = 0; i < 2; i++){
		for(auto j:st[i])
			cout << j.first << " " << j.second << ", ";
		cout << endl;
	}

    return 0;
}

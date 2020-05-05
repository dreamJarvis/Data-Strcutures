#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
	int testCases = 0;
    cin >> testCases ;

    for(int i = 0; i < testCases; i++){
        int noOfMembers = 0;
        cin >> noOfMembers ;

        vector<int> teamG;
        vector<int> opponent;

        // team g input
        ll temp = 0;
        for(int j = 0; j < noOfMembers; j++){
            cin >> temp;
            teamG.push_back(temp);
        }

        // opponent input
        for(int j = 0; j < noOfMembers; j++){
            cin >> temp;
            opponent.push_back(temp);
        }

        sort(teamG.begin(), teamG.end());
        sort(opponent.begin(), opponent.end());

        int k = noOfMembers-1, l = noOfMembers-1;
        int count = 0;
        while(k >= 0 && l >= 0){
            if(teamG[k] > opponent[l]){
                count++;
                k--;
                l--;
            }else if(teamG[k] <= opponent[l]){
                l--;
            }
        }

        cout << count << endl;
    }

	return 0;
}

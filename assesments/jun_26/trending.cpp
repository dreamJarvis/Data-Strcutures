#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<string, int> &a, const pair<string, int> &b){
    if(a.second > b.second){
        return true;
    }
    else if(a.second == b.second){
        if(a.first > b.first)
            return true;
    }

    return false;
}

void topHashTags(vector<string> str){
    unordered_map<string, int> freq;

    for(auto i:str){
        int j = 0;
        int len = i.length();
        while( j < len){
            string temp="";
            if(i[j] == '#'){
                while(j < len && i[j] != ' '){
                    temp += i[j];
                    j++;
                }
            }

            if(!temp.empty()){
                if(freq.count(temp))
                    freq[temp]++;
                else
                    freq[temp]=1;
            }

            j++;
        }
    }

    vector<pair<string, int>> res;
    for(auto i:freq){
        res.push_back(make_pair(i.first, i.second));
    }

    sort(res.begin(), res.end(), compare);

    int count = 1;
    for(auto i:res){
        cout << i.first << " --> " << i.second << endl;
        if(count == 5)
            break;
    }
}

// Driver function
int main(){
    // int n;
    // cin >> n;
    //
    // vector<string> str;
    //
    // for(int i = 0; i <= n; i++){
    //     string temp;
    //     getline(cin, temp);
    //     str.push_back(temp);
    // }
    //
    // for(auto i:str)
    //     cout << i << endl;
    // cout << endl;

    vector<string> str{
        "Barack Obama becomes the 44th #US President",
        "Potentially habitable exoplanet #ProximaB  has been discovered",
        "#RogerFederer wins #US Open for 5th time",
        "#GravitationalWaves detection has been successful",
        "Life Could Survive on Exoplanet #ProximaB",
        "Go go #RogerFederer",
        "Ten ways #ProximaB is different from Earth",
        "#RogerFederer beats #Nadal"
    };

    topHashTags(str);

    return 0;
}

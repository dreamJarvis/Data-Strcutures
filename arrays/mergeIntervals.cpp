// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
#include <bits/stdc++.h>
using namespace std;

// stores every interval
struct Interval{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// comparator : send true id a.start < b.start
bool myCompare(const Interval a, const Interval b){
    return a.start < b.start;
}

vector<Interval> mergeOverlappingIntervals(vector<Interval> &Intervals){
    // sorts the Interval array in ascending order
    sort(Intervals.begin(), Intervals.end(), myCompare);

    int n = Intervals.size();
    vector<Interval> result;
    result.push_back(Intervals[0]);

    for(int i = 0; i < n; i++){
        if(Intervals[i].start <= result[result.size()-1].end)
            result[result.size()-1].end = max(result[result.size()-1].end, Intervals[i].end);
        else
            result.push_back(Intervals[i]);
    }

    return result;
}

// Driver function
int main(){
    vector<Interval> ranges;
    ranges.push_back(Interval(1, 3));
    ranges.push_back(Interval(6, 9));
    ranges.push_back(Interval(2, 8));

    for(auto values:mergeOverlappingIntervals(ranges))
        cout <<"["<< values.start << ", " << values.end << "], ";

    return 0;
}

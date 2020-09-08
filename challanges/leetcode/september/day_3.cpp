/*
    220. Contains Duplicate III
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();

        if(n == 0 || k < 0  || t < 0) return false;

        unordered_map<int,int> buckets;

        // cout << buckets[0] << endl;

        for(int i=0; i<n; ++i) {
            int bucket = nums[i] / ((long)t + 1);

			// For negative numbers, we need to decrement bucket by 1
			// to ensure floor division.
			// For example, -1/2 = 0 but -1 should be put in Bucket[-1].
			// Therefore, decrement by 1.
            if(nums[i] < 0) --bucket;

            /* if the bucket already exists the return true, becase as given in the question we should have atmost
            diff of t i.e. <= t, so if the bucket for nums[i] already exist that means we already have a diff of <=t,
            as each bucket consist's of number with max diff in-btw them of t
            */
            if(buckets.find(bucket) != buckets.end()){
                return true;
            }

            /* if we dont have the bucket for the number, it means we are getting numbers's whose difference
            btw them is > t,
            ex : if t = 2, then 1, 4, 15, 19 .... these are nubers which have diff btw then > t,
            so they will exist in different buckets

            as we have already discussed that if the bucket already existed we wont have come to this point, i.e.
            if we are looking for lesser bucket and greater bucket, we  can be sure of that those are the only numbers in that bucket,
            i.e. it unnecessay for any bucket to have more than 1 value

            for ex if t = 2, k = 4, the [1, 4, 5, 2]
            now in this as we get to 5 , we will already have an bucket .'. we will return true

            if t = 2, k = 4, [12, 4, 27, 2], buckets for each number --> [4, 1, 9, 0]
            then buckets for each number is different,
            so now we will look fir numbers in lesser and greater buckets, here
            when we come across number 2 (bucket = 0), we find that we have a greater bucket i.e. 4(bucket = 1)
            and 4 - 2 == 2 .'. return true

            but we can have a lesser / greater bucket , but not have the required difference btw them,
            as the in each bucket will have max difference of t, but different buckets can have any number of difference btw them,
            we only check for just lesser/just greater becase those are the only numbers whcih are whitin our reach of t difference, for ex :

            if t = 3,
            the bucket[0] = [0 --> 3],
                bucket[1] = [4 --> 7],
                bucket[2] = [8 --> 11]

                in the above example we can hope that if the just smaller/just greater bucket exist ,
                there might exist a number whose difference with our's will give <= t
            */
            else {
                buckets[bucket] = nums[i];
                if(buckets.find(bucket-1) != buckets.end() && (long) nums[i] - buckets[bucket-1] <= t){
                    return true;
                }
                if(buckets.find(bucket+1) != buckets.end() && (long) buckets[bucket+1] - nums[i] <= t){
                    return true;
                }

                // each bucket is maintained within the boundaries of k length
                if(buckets.size() > k) {
                    int key_to_remove = nums[i-k] / ((long)t + 1);

                    if(nums[i-k] < 0) --key_to_remove;

                    buckets.erase(key_to_remove);
                }
            }
        }

        return false;
    }
};

// Driver function
int main(){
    vector<int> arr({1, 2, 3, 1});
    int k = 3, t = 0;
    // vector<int> arr({1, 0, 1, 1});
    // int k = 1, t = 2;
    // vector<int> arr({1, 5, 9, 1, 5, 9});
    // int k = 2, t = 3;
    // vector<int> arr({0});
    // int k = 0, t = 0;
    // vector<int> arr({1});
    // int k = 1, t = 1;
    // vector<int> arr({-1, -1});
    // int k = 1, t = 0;
    // vector<int> arr({1, 0, 1, 1});
    // int k = 1, t = 2;
    // vector<int> arr({2, 1});
    // int k = 1, t = 1;
    // vector<int> arr({-1, -1});
    // int k = 1, t = -1;
    // vector<int> arr({1, 2});
    // int k = 1, t = -1;
    // vector<int> arr({1,5,9,1,5,9});
    // int k = 2, t = 3;

    Solution s;
    cout << s.containsNearbyAlmostDuplicate(arr, k, t) << endl;

    return 0;
}
/*
[1,5,9,1,5,9]
2
3
*/

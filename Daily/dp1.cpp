#include <bits/stdc++.h>
using namespace std;

// 452 Minimun Arrows to Burst Balloons
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end());
    int lastpoint = points[0][1];
    int ans = 1;
    for(auto p: points){
        if(p[0] > lastpoint){
            ans++;
            lastpoint = p[1];
        }
        lastpoint = min(p[1], lastpoint);
    }
    return ans;
}

// 435 Erase Overlapping Intervals
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int ans = 0;
    int lastpoint = intervals[0][1];

    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < lastpoint) {
            ans++;
            lastpoint = min(lastpoint, intervals[i][1]);
        } else {
            lastpoint = intervals[i][1];
        }
    }
    return ans;
}

// Sort Characters by Frequency
string frequencySort(string s) {
    unordered_map<char, int> freq;
    for(char c:s){
        freq[c]++;
    }

    priority_queue<pair<int, char>> maxHeap;
    for(auto& [ch,f]: freq){
        maxHeap.push({f, ch});
    }

    string result;
    while(!maxHeap.empty()){
        auto [count, ch] = maxHeap.top();
        maxHeap.pop();
        result += string(count, ch);
    }
    return result;
}

// 1636 Sort Array by frequency
vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    // Custom Sort
    sort(nums.begin(), nums.end(), [&](int a, int b) {
        if (freq[a] != freq[b]) return freq[a] < freq[b];
        return a > b;
    });

    return nums;
}

// Hand Of Straights
bool isNStraightHand(vector<int>& hand, int groupSize) {
    int n = hand.size();
    if(n % groupSize != 0) {
        return false;
    }

    map<int,int> mp;
    for(int &handNum : hand){
        mp[handNum]++;
    }

    while(!mp.empty()){
        int curr = mp.begin()->first;
        for(int i=0; i<groupSize; i++){
            if(mp[curr + i] == 0){
                return false;
            }
            mp[curr + i]--;
            if(mp[curr + i] == 0){
                mp.erase(curr + i);
            }
        }
    }
    return true;
}
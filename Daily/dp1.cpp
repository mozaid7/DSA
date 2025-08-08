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

// 846 Hand Of Straights
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

// Reduce the Array to Half
int minSetSize(vector<int>& arr) {
    int n = arr.size();
    int half = n/2;

    unordered_map<int, int> mp;
    for(int &num : arr){
        mp[num]++;
    }

    vector<int> freq;
    for(auto [_, cnt] : mp) freq.push_back(cnt);
    sort(freq.begin(), freq.end());

    int ans = 0, removed = 0, i = freq.size() - 1;
    while(removed < half){
        ans+=1;
        removed += freq[i--];
    }
    return ans;
}

// 767 Reorganizing String
string reorganizeString(string s) {
    unordered_map<char, int>mp;
    for(auto st : s){
        mp[st]++;
    }

    priority_queue<pair<int, char>> maxHeap;
    for(auto &[ch, fr] : mp){
        maxHeap.push({fr, ch});
    }

    string res;
    while(maxHeap.size() >= 2){
        auto [freq1, char1] = maxHeap.top(); maxHeap.pop();
        auto [freq2, char2] = maxHeap.top(); maxHeap.pop();

        res += char1;
        res += char2;

        if(--freq1 > 0) maxHeap.push({freq1, char1});
        if(--freq2 > 0) maxHeap.push({freq2, char2});
    }

    if(!maxHeap.empty()){
        auto [freq, ch] = maxHeap.top();
        if(freq > 1) return "";
        res += ch;
    }

    return res;
    
}
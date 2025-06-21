#include<bits/stdc++.h>
using namespace std;

// Starting with a 1-indexed array of zeros and a list of operations, for each operation add a value to each array element between two given indices, inclusive. Once all operations have been performed, return the maximum value in the array.
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n + 2, 0);

    for (const auto& q : queries) {
        int a = q[0];
        int b = q[1];
        int k = q[2];

        arr[a] += k;
        arr[b + 1] -= k;
    }

    long maxVal = 0, current = 0;
    for (int i = 1; i <= n; i++) {
        current += arr[i];
        maxVal = max(maxVal, current);
    }

    return maxVal;
}

// There is a collection of input strings and a collection of query strings. For each query string, determine how many times it occurs in the list of input strings. Return an array of the results.
vector<int> matchingStrings(vector<string> stringList, vector<string> queries) {
    vector<int> ans;
    int m = stringList.size();
    int n = queries.size();
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<m; j++){
            if(queries[i] == stringList[j]){
                cnt++;
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}

// Sherlock and Valid String
string isValid(string s) {
    unordered_map<char, int> freq;

    for (char c : s) {
        freq[c]++;
    }

    unordered_map<int, int> freqCount;
    for (auto pair : freq) {
        freqCount[pair.second]++;
    }

    if (freqCount.size() == 1) {
        return "YES";
    } else if (freqCount.size() == 2) {
        auto it = freqCount.begin();
        int f1 = it->first, c1 = it->second;
        it++;
        int f2 = it->first, c2 = it->second;

        if ((c1 == 1 && (f1 - 1 == f2 || f1 == 1)) ||
            (c2 == 1 && (f2 - 1 == f1 || f2 == 1))) {
            return "YES";
        }
    }

    return "NO";
}

// There is a string, , of lowercase English letters that is repeated infinitely many times. Given an integer, , find and print the number of letter a's in the first  letters of the infinite string.
long repeatedString(string s, long n) {
    long long cnt_a = 0;
    
    for(char ch: s){
        if(ch == 'a') cnt_a++;
    }
    
    long long full_repeats = n / s.length();
    long long remainder = n % s.length();
    
    long long cnt_rem = 0;
    for(int i=0; i<remainder; i++){
        if(s[i] == 'a') cnt_rem++;
    }
    
    return full_repeats * cnt_a + cnt_rem;
}


// Sean invented a game involving a 2n*2n matrix where each cell of the matrix contains an integer. He can reverse any of its rows or columns any number of times. The goal of the game is to maximize the sum of the elements in the n*n submatrix located in the upper-left quadrant of the matrix.
int flippingMatrix(vector<vector<int>> matrix) {
    int n = matrix.size() / 2;
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int a = matrix[i][j];
            int b = matrix[i][2*n - 1 - j];
            int c = matrix[2*n - 1 - i][j];
            int d = matrix[2*n - 1 - i][2*n - 1 - j];
            sum += max({a, b, c, d});
        }
    }

    return sum;
}

// Two strings are anagrams of each other if the letters of one string can be rearranged to form the other string. Given a string, find the number of pairs of substrings of the string that are anagrams of each other.
int sherlockAndAnagrams(string s) {
    unordered_map<string, int> substrFreq;
    int n = s.length();

    for (int i = 0; i < n; ++i) {
        string substr = "";
        for (int j = i; j < n; ++j) {
            substr += s[j];
            string sorted_substr = substr;
            sort(sorted_substr.begin(), sorted_substr.end());
            substrFreq[sorted_substr]++;
        }
    }

    int count = 0;
    for (auto& p : substrFreq) {
        int freq = p.second;
        count += (freq * (freq - 1)) / 2;
    }

    return count;

}

// There are a number of people who will be attending ACM-ICPC World Finals. Each of them may be well versed in a number of topics. Given a list of topics known by each attendee, presented as binary strings, determine the maximum number of topics a 2-person team can know. Each subject has a column in the binary string, and a '1' means the subject is known while '0' means it is not. Also determine the number of teams that know the maximum number of topics. Return an integer array with two elements. The first is the maximum number of topics known, and the second is the number of teams that know that number of topics.
vector<int> acmTeam(const vector<string>& topics) {
    int maxTopics = 0;
    int teamCount = 0;
    int n = topics.size();
    int m = topics[0].size(); // Number of topics

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int topicsKnown = 0;
            for (int k = 0; k < m; ++k) {
                if (topics[i][k] == '1' || topics[j][k] == '1') {
                    topicsKnown++;
                }
            }

            if (topicsKnown > maxTopics) {
                maxTopics = topicsKnown;
                teamCount = 1;
            } else if (topicsKnown == maxTopics) {
                teamCount++;
            }
        }
    }

    return {maxTopics, teamCount};
}

// Alice is a kindergarten teacher. She wants to give some candies to the children in her class.  All the children sit in a line and each of them has a rating score according to his or her performance in the class.  Alice wants to give at least 1 candy to each child. If two children sit next to each other, then the one with the higher rating must get more candies. Alice wants to minimize the total number of candies she must buy.
long candies(int n, vector<int> arr) {
    vector<int> candy(n, 1);

    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i - 1]) {
            candy[i] = candy[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] > arr[i + 1]) {
            candy[i] = max(candy[i], candy[i + 1] + 1);
        }
    }

    long totalCandies = 0;
    for (int i = 0; i < n; ++i) {
        totalCandies += candy[i];
    }

    return totalCandies;
}

// Encryption - An English text needs to be encrypted using the following encryption scheme.First, the spaces are removed from the text. Let  be the length of this text. Then, characters are written into a grid, whose rows and columns have the following constraints:
string encryption(string s) {
    string clean = "";
    for (char c : s) {
        if (c != ' ')
            clean += c;
    }

    int L = clean.size();
    int row = floor(sqrt(L));
    int col = ceil(sqrt(L));
    if (row * col < L) row++;

    vector<string> grid(row);
    for (int i = 0; i < L; i++) {
        grid[i / col] += clean[i];
    }

    string result = "";
    for (int c = 0; c < col; c++) {
        for (int r = 0; r < row; r++) {
            if (c < grid[r].size())
                result += grid[r][c];
        }
        result += ' ';
    }

    return result;
}

// Lexicographical order is often known as alphabetical order when dealing with strings. A string is greater than another string if it comes later in a lexicographically sorted list.Given a word, create a new word by swapping some or all of its characters. This new word must meet two criteria: 1)It must be greater than the original word. 2)It must be the smallest word that meets the first condition
string biggerIsGreater(string w) {
    int n = w.length();
    
    int i = n - 2;
    while (i >= 0 && w[i] >= w[i + 1]) {
        i--;
    }

    if (i < 0) {
        return "no answer";
    }

    int j = n - 1;
    while (w[j] <= w[i]) {
        j--;
    }

    swap(w[i], w[j]);

    reverse(w.begin() + i + 1, w.end());

    return w;
}
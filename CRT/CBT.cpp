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

// Kangaroo Jumps - Number Line Jumps
string kangaroo(int x1, int v1, int x2, int v2) {
    if (v1 == v2) {
        return (x1 == x2) ? "YES" : "NO";
    }

    if ((x2 - x1) % (v1 - v2) == 0 && ((v1 > v2 && x1 < x2) || (v2 > v1 && x2 < x1))) {
        return "YES";
    }

    return "NO";
}

// Hackerland is a one-dimensional city with houses aligned at integral locations along a road. The Mayor wants to install radio transmitters on the roofs of the city's houses. Each transmitter has a fixed range meaning it can transmit a signal to all houses within that number of units distance away.Given a map of Hackerland and the transmission range, determine the minimum number of transmitters so that every house is within range of at least one transmitter. Each transmitter must be installed on top of an existing house.
int hackerlandRadioTransmitters(vector<int> x, int k) {
    sort(x.begin(), x.end());

    int n = x.size();
    int i = 0, count = 0;

    while (i < n) {
        count++;

        int loc = x[i] + k;
        while (i < n && x[i] <= loc) i++;

        int transmitter = x[i - 1];

        loc = transmitter + k;
        while (i < n && x[i] <= loc) i++;
    }

    return count;
}

// Poisonous Plants -There are a number of plants in a garden. Each of the plants has been treated with some amount of pesticide. After each day, if any plant has more pesticide than the plant on its left, being weaker than the left one, it dies.You are given the initial values of the pesticide in each of the plants. Determine the number of days after which no plant dies, i.e. the time after which there is no plant with more pesticide content than the plant to its left.
int poisonousPlants(vector<int> p) {
    int n = p.size();
    stack<pair<int, int>> st; // {pesticide, daysToDie}
    vector<int> days(n, 0);   // stores days to die for each plant
    int maxDays = 0;

    for (int i = 0; i < n; ++i) {
        int day = 0;

        // Remove plants from the stack which have pesticide >= current
        while (!st.empty() && p[i] <= st.top().first) {
            day = max(day, st.top().second);
            st.pop();
        }

        // If stack is not empty, plant will die
        if (!st.empty()) day++;

        // Update days and push this plant to the stack
        st.push({p[i], day});
        maxDays = max(maxDays, day);
    }

    return maxDays;
}

// Largest Rectangle
long largestRectangle(vector<int> h) {
    int n = h.size();
    vector<int> left(n), right(n);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && h[st.top()] >= h[i]) {
            st.pop();
        }
        if (st.empty()) {
            left[i] = -1; 
        } else {
            left[i] = st.top(); 
        }
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && h[st.top()] >= h[i]) {
            st.pop();
        }
        if (st.empty()) {
            right[i] = n; 
        } else {
            right[i] = st.top(); 
        }
        st.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; ++i) {
        int width = right[i] - left[i] - 1;
        int area = h[i] * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

// Valid Parenthesis
string isBalanced(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return "NO";
            char top = st.top();
            if ((c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{')) {
                st.pop();
            } else {
                return "NO";
            }
        }
    }
    return st.empty() ? "YES" : "NO";
}

// Game of two stacks
int twoStacks(int maxSum, vector<int> a, vector<int> b) {
    int sum = 0, count = 0, i = 0, j = 0;

    while (i < a.size() && sum + a[i] <= maxSum) {
        sum += a[i];
        i++;
    }
    count = i;

    while (j < b.size() && i >= 0) {
        sum += b[j];
        j++;

        while (sum > maxSum && i > 0) {
            i--;
            sum -= a[i];
        }

        if (sum <= maxSum) {
            count = max(count, i + j);
        }
    }

    return count;
}

// Priority Queue
int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> maxHeap(stones.begin(), stones.end());

    while (maxHeap.size() > 1) {
        int stone1 = maxHeap.top(); maxHeap.pop();
        int stone2 = maxHeap.top(); maxHeap.pop();

        if (stone1 != stone2) {
            maxHeap.push(stone1 - stone2);
        }
    }
    return maxHeap.empty() ? 0 : maxHeap.top();
}

// Kth largest element
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> maxHeap(nums.begin(), nums.end());

    for (int i = 0; i < k - 1; i++) {
        maxHeap.pop();
    }
    return maxHeap.top();
}

// Max Element is Stack
// 1 x  -Push the element x into the stack.
// 2    -Delete the element present at the top of the stack.
// 3    -Print the maximum element in the stack.
vector<int> getMax(vector<string> operations) {
    stack<int> mainStack;
    stack<int> maxStack;
    vector<int> result;

    for (const string& op : operations) {
        if (op[0] == '1') {
            int x = stoi(op.substr(2));
            mainStack.push(x);

            if (maxStack.empty() || x >= maxStack.top()) {
                maxStack.push(x);
            }
        } else if (op[0] == '2') {
            if (!mainStack.empty()) {
                if (mainStack.top() == maxStack.top()) {
                    maxStack.pop();
                }
                mainStack.pop();
            }
        } else if (op[0] == '3') {
            if (!maxStack.empty()) {
                result.push_back(maxStack.top());
            }
        }
    }

    return result;
}

// Queue using Two Stacks
int main() {
    int q;
    cin >> q;

    stack<int> inStack, outStack;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            inStack.push(x);
        } else {
            if (outStack.empty()) {
                while (!inStack.empty()) {
                    outStack.push(inStack.top());
                    inStack.pop();
                }
            }

            if (type == 2 && !outStack.empty()) {
                outStack.pop();
            } else if (type == 3 && !outStack.empty()) {
                cout << outStack.top() << endl;
            }
        }
    }

    return 0;
}

// Simple Text Editor
int main() {
    int Q;
    cin >> Q;

    string S = "";              
    stack<string> history;       

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            string W;
            cin >> W;
            history.push(S);    
            S += W;
        } else if (type == 2) {
            int k;
            cin >> k;
            history.push(S);    
            S.erase(S.size() - k);
        } else if (type == 3) {
            int k;
            cin >> k;
            cout << S[k - 1] << endl;
        } else if (type == 4) {
            if (!history.empty()) {
                S = history.top();
                history.pop();
            }
        }
    }

    return 0;
}
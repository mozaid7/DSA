#include <bits/stdc++.h>
using namespace std;

// 1. String Compression
string compressString(const string& input) {
    if(input.empty()) return "";

    string result = "";
    int count = 1;
    char current = input[0];
    
    for(int i=1; i<input.length(); i++){
        if(input[i] == current){
            count++;
        } else {
            result += current;
            if(count > 1){
                result += to_string(count);
            }
            current = input[i];
            count = 1;
        }
    }
    result += current;
    if(count > 1) {
        result += to_string(count);
    }
    return result;
}

// 2. Freqency Counter
string countFrequency(const vector<int>& arr) {
    vector<int> freq(10,0);
    string result = "";

    for (int num : arr){
        if(num >= 0 && num <= 9){
            freq[num]++;
        }
    }

    for(int i=0; i<10; i++){
        if(freq[i] > 0){
            result += to_string(i) + "occurs" + to_string(freq[i]) + "times\n";
        }
    }

    return result;
}

// 3. Calculate no of tyres in a Dealership
vector<int> calculateTyres(const vector<pair<int, int>>& dealerships) {
    vector<int> tyreCounts;

    for(auto dealership : dealerships){
        int cars = dealership.first;
        int bikes = dealership.second;
        int tyre = (bikes * 2) + (cars * 4);
        tyreCounts.push_back(tyre);
    }
    return tyreCounts;
}

// 4. Spiral Matrix Traversal
string spiralTraversal(const vector<vector<int>>& matrix){
    if(matrix.empty()) return "";

    int rows = matrix.size();
    int cols = matrix[0].size();
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    string result = "";

    while(top <= bottom && left <= right){
        // Left to Right
        for(int i = left; i<= right; i++){
            result += to_string(matrix[top][i]) + "";
        }
        top++;

        // Top to Bottom
        for(int i = top; i<= bottom; i++){
            result += to_string(matrix[i][right]) + "";
        }
        right--;

        // Right to Left
        if(top <= bottom){
            for(int i=right; i>= left; i--){
                result += to_string(matrix[bottom][i]) + "";
            }
            bottom--;
        }

        // Bottom to Top
        if(left <= right){
            for(int i=bottom; i>= top; i--){
                result += to_string(matrix[i][left]) + "";
            }
            left++;
        }
    }
    return result;
}

// Find Factors
string findFactors(int n){
    if(n == 0){
        return "No Factors";
    }

    n = abs(n);
    vector<int> factors;

    for(int i=1; i<=n; i++){
        if(n % i == 0){
            factors.push_back(i);
        }
    }

    string result = "";
    for(int i=0; i<factors.size(); i++){
        result += to_string(factors[i]);
        if(i != factors.size() - 1){
            result += ",";
        }
    }
    return result;
}

// Max Marks
string findMaxMarksPerSemester(const vector<vector<int>>& semesterMarks){
    string result = "";

    for(int i=0; i< semesterMarks.size(); i++){
        int maxMarks = 0;
        bool valid = true;

        for(int mark : semesterMarks[i]){
            if(mark < 0 || mark > 100){
                return "You have entered invalid marks";
            }
            if(mark > maxMarks){
                maxMarks = mark;
            }
        }
        result += "Maximum mark in semester " + to_string(i + 1) + ": " + to_string(maxMarks) + "\n";
    }
    return result;
}

// Minimum Discount
string findMinDiscountItems(const vector<pair<string, pair<int, int>>>& products){
    if(products.empty()) return "No Products to Display";

    int minDis = INT_MAX;

    for(auto& product : products){
        int discount = product.second.second;
        if(discount < minDis){
            minDis = discount;
        }
    }
    
    string result = "Items with minimum discount (" + to_string(minDis) + "%):\n";
    for(auto& product : products){
        if(product.second.second == minDis){
            result += product.first + "\n";
        }
    }
    return result;
}

// Move Hash to the Front
string moveHash(const string& str){
    string hashes, nonHash;
    
    for(char c : str){
        if(c == '#'){
            hashes += c;
        } else {
            nonHash += c;
        }
    }
    
    return hashes + nonHash;
}

// Season Finder
string getSeason(int month){
    if(month < 1 || month > 12) return "Invalid Month";

    if (month >= 3 && month <= 5) {
        return "Spring Season";
    } else if (month >= 6 && month <= 8) {
        return "Summer Season";
    } else if (month >= 9 && month <= 11) {
        return "Autumn Season";
    } else {
        return "Winter Season";
    }
}

// Valley Count
int countingValleys(const string& path){
    int altitude = 0;
    int valleyCount = 0;
    bool inValley = false;

    for(char c : path){
        if(c == 'U'){
            altitude++;
        } else if(c == 'D'){
            altitude--;
        }
    }

    if(altitude < 0 && !inValley){
        valleyCount++;
        inValley = true;
    } else if (altitude >=0 ) {
        inValley = false;
    }

    return valleyCount;
}

// Matrix Identity Check
bool areMatricesIdentical(const vector<vector<int>>& A, const vector<vector<int>>& B){
    int rowsA = A.size();
    int rowsB = B.size();

    int colsA = A[0].size();
    int colsB = B[0].size();

    if(rowsA == 0) return B.empty();
    if(rowsB == 0) return false;

    if (rowsA != rowsB || colsA != colsB) {
        return false;
    }

    for(int i=0; i<rowsA; i++){
        for(int j=0; j<rowsB; j++){
            if(A[i][j] != B[i][j]){
                return false;
            }
        }
    }
    return true;
}

// Pythogorean Triplet
string findPythagoreanTriplets(int limit){
    string result = "";

    for(int a = 1; a<= limit; a++){
        for(int b = a+1; b<= limit; b++){
            int c_sq = a*a + b*b;
            int c = sqrt(c_sq);

            if(c*c == c_sq && c<=limit){
                result += to_string(a) + " " + to_string(b) + " " + to_string(c) + "\n";
            }
        }
    }
    return result;
}

// Binary Search
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

// String Rotation
bool isRotation(const string& A, const string& B) {
    if (A.length() != B.length()) {
        return false;
    }
    
    string combined = A + A;
    return combined.find(B) != string::npos;
}

// Find Missing Number
int findMissingNumber(const vector<int>& nums){
    int n = nums.size() + 1;
    int expectedSum = n * (n+1) / 2;
    int actualSum = 0;

    for(int num : nums){
        actualSum += num;
    }

    return expectedSum - actualSum;
}

// Reverse a Linked List
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseLinkedList(ListNode* head){
    ListNode* prev = NULL;
    ListNode* current = head;
    ListNode* next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Longest Substring without repeating characters
int lengthOfLongestSubstring(const string& s) {
    unordered_set<char> charset;
    int left = 0, maxLength = 0;

    for(int right = 0; right < s.length(); right++){
        if(charset.find(s[right]) != charset.end()){
            charset.erase(s[left]);
            left++;
        }
        charset.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
}

// Find Duplicate Number
int findDuplicate(const vector<int>& nums){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i=1; i<n; i++){
        if(nums[i] == nums[i-1]){
            return nums[i];
        }
    }
    return n;
}

// Find Duplicates in an Array
vector<int> findDuplicates(const vector<int>& nums) {
    unordered_map<int, int> frequency;
    vector<int> duplicates;
    
    for (int num : nums) {
        frequency[num]++;
    }
    
    for (const auto& pair : frequency) {
        if (pair.second > 1) {
            duplicates.push_back(pair.first);
        }
    }
    
    return duplicates;
}

// Check for Prime No
bool isPrime(int n){
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    for(int i=3; i<=sqrt(n); i+=2){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

// Merge Two Sorted Arrays
vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2){
    vector<int> result;
    int n = arr1.size();
    int m = arr2.size();
    int i=0, j=0;

    while(i<n && j<m){
        if(arr1[i] <= arr2[j]){
            result.push_back(arr1[i]);
            i++;
        } else {
            result.push_back(arr2[j]);
            j++;
        }
    }
    if(i < n){
        result.push_back(arr1[i]);
        i++;
    }
    if(j < m){
        result.push_back(arr2[j]);
        j++;
    }
    return result;
}

// Rotate Array
vector<int> rotateArray(const vector<int>& nums, int k){
    if(nums.empty()) return nums;
    int n = nums.size();
    int rotations = k % n;
    vector<int> result = nums;

    reverse(result.begin(), result.end());
    reverse(result.begin(), result.begin() + rotations);
    reverse(result.begin() + rotations, result.end());
    return result;
}

// Valid Parenthesis
bool isValid(string s){
    stack<char> st;
    for(char ch : s){
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        } else {
            if(st.empty()) return false;
            char top = st.top();
            if((ch == ')' && top == '(') ||
               (ch == '}' && top == '{') ||
               (ch == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

// Intersection of two arrays
vector<int> findIntersection(const vector<int>& nums1, const vector<int>& nums2){
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> intersection;

    for(int num : nums2){
        if(set1.find(num) != set1.end()){
            intersection.insert(num);
        }
    }

    return vector<int>(intersection.begin(), intersection.end());
}

// Check Palindrome
bool isPalindrome(const string& s){
    int left = 0, right = s.length() - 1;

    while(left < right){
        while(left < right && !isalnum(s[left])) left++;
        while(left < right && !isalnum(s[right])) right --;

        if(tolower(s[left]) != tolower(s[right])){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Matrix Rotation by 90 degress
void rotateMatrix90InPlace(vector<vector<int>>& matrix){
    int n = matrix.size();

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// Majority Element n/2 by Boyre Moore Algorithm in O(1) or O(n) TC
int findMajorityElement(const vector<int>& nums){
    int n = nums.size();
    int candidate = nums[0];
    int count = 1;

    for(int i=1; i<n; i++){
        if(count == 0){
            candidate = nums[i];
            count = 1;
        } else if(nums[i] == candidate){
            count++;
        } else {
            count--;
        }
    }

    count = 0;
    for(int num : nums){
        if(num == candidate) count++;
    }

    return (count > n/2) ? candidate : -1;
}

// Find Non Repeated Character
char firstNonRepeatedChar(const string& s){
    unordered_map<char, int> frequency;

    for(char c : s){
        frequency[c]++;
    }

    for(char c : s){
        if(frequency[c] == 1){
            return c;
        }
    }
    return '\0';
}

// Merge Overlapping Intervals
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals){
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;

    for(int i=0; i<n; i++){
        if(ans.empty() || intervals[i][0] > ans.back()[1]){
            ans.push_back(intervals[i]);
        } else {
            ans.back()[1] = max(ans.back()[i], intervals[i][1]);
        }
    }
    return ans;
}

// Largest Sum Contiguous Sub-Array
int maxSubArray(vector<int>& nums){
    int n = nums.size();
    long long sum = 0, maxi = LONG_MIN;
    for(int i=0; i<n; i++){
        sum += nums[i];
        if(sum > maxi) maxi = sum;
        if(sum < 0) sum = 0;
    }
    return maxi;
}

// Longest even substring
int longestEvenLengthSubstring(string s){
    int n = s.length();
    int maxLen = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j+=2){
            int len = j - i + 1;
            int mid = i + len/2;
            int leftsum = 0, rightsum = 0;

            for (int k = i; k < mid; k++) {
                leftsum += (s[k] - '0'); 
            }

            for (int k = mid; k <= j; k++) {
                rightsum += (s[k] - '0');    // Convert char to int
            }

            if(leftsum == rightsum && len > maxLen){
                maxLen = len;
            }
        }
    }
    return maxLen;
}

// Valid Pairs
int countValidPairs(vector<int>& arr, int k){
    unordered_set<int> numSet(arr.begin(), arr.end());
    int count  =0;

    for(int num : arr){
        if(numSet.find(num + k) != numSet.end()){
            count++;
        }
    }
    return count;
}

// Min Cost to traverse
int minCostToTraverse(vector<int>& arr, int k){
    int n = arr.size();
    if(n ==0) return 0;

    vector<int> dp(n, INT_MAX);
    dp[0] = arr[0];

    for(int i=0; i<n; i++){
        for(int j=1; j<=k && i + j < n; j++){
            dp[i + j] = min(dp[i+j], dp[i] + arr[i+j]);
        }
    }
    return dp[n-1];
}

// String conversion with circular alphabet
int minConversionCostOptimized(string S, string T){
    int s = S.length();
    int t = T.length();
    int total = 0;

    for(int i=0; i<s; i++){
        int minCost = INT_MAX;

        for(int j=0; j<t; j++){
            int diff = abs(S[i] - T[j]);
            int cost = min(diff, 26-diff);
            minCost = min(minCost, cost);
        }
        total += minCost;
    }
    return total; 
}

// Check for Nth Prime No.
int check_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int find_nth_prime(int n) {
    if (n == 0) {
        return 1;
    }
    
    int ans = 0;
    int i = 2;
    
    while (true) {
        if (check_prime(i)) {
            ans++;
        }
        if (ans == n) {
            break;
        }
        i++;
    }
    
    return i;
}

// Distinct Permutations of a String
long long find_fact(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

long long countDistinctPermutations(const string& s) {
    int n = s.size();
    vector<int> fre(256, 0);  // Frequency array for all ASCII characters
    
    int i = 0;
    while (i < n) {
        int index = s[i];  // ASCII value of character
        fre[index] += 1;
        i += 1;
    }
    
    long long total = find_fact(n);
    
    for (int i = 0; i < 256; i++) {
        if (fre[i] > 1) {
            total /= find_fact(fre[i]);
        }
    }
    
    return total;
}

// Query Solver
int solveQueries(const vector<int>& arr, const vector<pair<int, int>>& queries){
    int n = arr.size();
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    for(const auto& query : queries){
        int u = query.first;
        int v = query.second;
        int count = 0;

        int maxi = max(u,v);
        int mini = min(u,v);

        for(int i=0; i<n; i++){
            if(i > 0 && sortedArr[i] == sortedArr[i-1]) continue;
            for(int j=i+1; j<n; j++){
                int prod = sortedArr[i] * sortedArr[j];
                int sum = sortedArr[i] + sortedArr[j];

                if(prod == maxi && sum == mini){
                    count++;
                }
            }
        }
        cout << count << endl;
    }
}

// Max Product SubArray
int maxProductSubarray(int arr[], int n) {
    int maxProduct = arr[0], minProduct = arr[0], result = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] < 0) {
            swap(maxProduct, minProduct);  // Handle negative multiplication
        }
        
        maxProduct = max(arr[i], maxProduct * arr[i]);
        minProduct = min(arr[i], minProduct * arr[i]);
        
        result = max(result, maxProduct);
    }
    return result;
}

// Reverse Words in a String
string reverseWords(string s) {
    int n = s.size();
    string temp = "";
    vector<string> res;

    for (int i = 0; i < n; i++) {
        if (s[i] != ' ') {
            temp += s[i];
        } else {
            if (!temp.empty()) {
                res.push_back(temp);
                temp = "";
            }
        }
    }

    if (!temp.empty()) {
        res.push_back(temp);
    }
    
    reverse(res.begin(), res.end());
    string result = "";
    for (int i = 0; i < res.size(); i++) {
        result += res[i];
        if (i < res.size() - 1) result += ' ';
    }

    return result;
}

// Sum of Diagonals of Array
int sumOfDiagonals(int arr[][1000], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i][i]; // Primary diagonal
        sum += arr[i][n - 1 - i]; // Secondary diagonal
    }
    return sum;
}

// Count Set Bits
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

// Sub Array Sum equals K
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    map<int, int>mpp;
    mpp[0] = 1;
    int preSum = 0; int cnt = 0;
    for(int i=0; i<n; i++) {
        preSum += nums[i];
        int rem = preSum - k;
        cnt += mpp[rem];
        mpp[preSum] += 1;
    }
    return cnt;
}

// Move Zeroes
void moveZeroes(vector<int>& nums) {
    int index = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
        nums[index++] = nums[i];
        }
    }

    for (int i = index; i < nums.size(); i++) {
        nums[i] = 0;
    }
}

// Top K Frequent Elements
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;

    priority_queue<pair<int, int>> pq;
    for (auto& [num, count] : freq)
        pq.push({count, num});

    vector<int> res;
    while (k--) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}

// Group Anagrams
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    
    for(auto& str : strs){
        string word = str;
        sort(word.begin(), word.end());
        mp[word].push_back(str);
    }

    vector<vector<string>> ans;
    for(auto x: mp){
        ans.push_back(x.second);
    }
    return ans;
}

// Best Time to Buy and Sell Stock
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX, maxProfit = 0;

    for (int price : prices) {
        if (price < minPrice) {
            minPrice = price;
        } else {
            maxProfit = max(maxProfit, price - minPrice);
        }
    }

    return maxProfit;
}
// Question Link: https://leetcode.com/problems/two-sum

// Brute Force Solution

int numIdenticalPairs(vector<int>& nums) {
    int res = 0, size = nums.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (nums[i] == nums[j]) {
                res++;
            }
        }        
    }
    return res;
}
// O(N) Unordered Map Solution
// The basic idea is;
// Assume we have an array of this:
// 1 1
// Here, NGP (Number Of Good Pairs) is: 1 right?
// What if we add one more '1' to the above list? See the following to see the pattern:
// 1 1 NGP: 1
// 1 1 1 NGP: 3
// 1 1 1 1 NGP: 6
// 1 1 1 1 1 NGP: 10
// As you can see, once we add 1 to the current array, to find the new NGP;
// We do the following;
// 1 1 -> Here the Number of Occurences: 2, once we add new '1'
// 2 + previousNGP = 3

// 1 1 1 -> Here the Number of Occurences: 3, once we add new '1'
// 3 + previousNGP = 6

// 1 1 1 1 -> Here the Number of Occurences: 4, once we add new '1'
// 4 + previousNGP = 10

// You see the pattern? So the point is:

// Whenever we add a new '1' to the array, Actually we know we will have "Number of Occurences" times new good pairs in which the new '1' will have with the each of the value in the array.

int numIdenticalPairs(vector<int>& nums) {
    unordered_map<int, int> countMap;
    int pairs = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (countMap.find(nums[i]) != countMap.end()) {
            pairs += countMap[nums[i]];                
        }
        countMap[nums[i]]++;
    }
    return pairs;
}
// O(N) Counting Array Map Solution
// Since we know the range, the max element, we can use a counting array rather than using hashing as we did above, this will decrease the time complexity overall:
// 1 <= nums[i] <= 100

int numIdenticalPairs(vector<int>& nums) {
    vector<int> countMap(101, 0);
    int pairs = 0;
    for (int i = 0; i < nums.size(); i++) {
        pairs += countMap[nums[i]];                
        countMap[nums[i]]++;
    }
    return pairs;
}
// Question Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array

// Trie Solution
struct TrieNode {
    TrieNode* children[2] = { NULL, NULL };
    int bit;
    TrieNode(int b) : bit(b) {};
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode *root = new TrieNode(-1);
        // Insert all numbers to Trie
        for (int &num : nums) {
            string bin = bitset<32>(num).to_string();
            insert(root, bin);
        }
        // Find max XOR result
        int result = 0;
        for (int &num : nums) {
            string bin = bitset<32>(num).to_string();
            XOR(root, bin, result);
        }
        return result;
    }
    
    void XOR(TrieNode *root, string &binaryNum, int &result) {
        TrieNode *walk = root;
        string xorNum = "";
        for (char bit : binaryNum) {
            // Check if opposite bit exists
            if (walk->children[!(bit - '0')]) {
                walk = walk->children[!(bit - '0')];
                xorNum += '1';
            }
            else {
                walk = walk->children[bit - '0'];
                xorNum += '0';
            }
        }
        int decimal = binToInt(xorNum);
        result = max(result, decimal);
    }
    
    int binToInt(string &binary) {
        int num = 0;
        for (int i = 0; i < 32; i++) {
            num += (binary[i] - '0') * pow(2, 32 - i - 1);
        }
        return num;
    }
    
    void insert(TrieNode *root, string &binaryNum) {
        TrieNode *walk = root;
        for (char bit : binaryNum) {
            if (walk->children[bit - '0'] == NULL) {
                walk->children[bit - '0'] = new TrieNode(bit - '0');
            }
            walk = walk->children[bit - '0'];
        }
    }
};

// Initial Solution
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int result = 0, n = nums.size();
        if (n == 1) {
            return nums[0] ^ nums[0];
        }
        
        // Max binary numbers according to the left most bit
        queue<int> possibleAnswers;
        int greatestNum = *max_element(begin(nums), end(nums));
        int maxBits = bitCount(greatestNum);
        int desiredBinaryNumber = greatestNum;
        vector<int> others(n, -1);
        
        // Get number of bits for each number 
        int ith = 0, bitCnt;
        bool allHaveSameBitCount = true;
        for (int i = 0; i < n; i++) {
            bitCnt = bitCount(nums[i]);
            if (bitCnt == maxBits) {
                possibleAnswers.push(nums[i]);
            } else {
                allHaveSameBitCount = false;
                others[ith++] = nums[i];
            }
            // In case of all number have same bits
            if (maxBits == bitCount(nums[i])) {
                desiredBinaryNumber = min(desiredBinaryNumber, nums[i]);
            }
        }
        
        // Check if all numbers have same bit count
        if (allHaveSameBitCount == true) {
            // Then XOR all with desired
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    result = max(result, nums[j] ^ nums[i]);
                }
            }
            return result;
        }
        
        while (!possibleAnswers.empty()) {
            int cur = possibleAnswers.front();
            possibleAnswers.pop();
            for (int i = 0; i < ith; i++) {
                result = max(result, cur ^ others[i]);
            }
        }
        
        return result;
    }
    
    // Return number of bits of integer, uses cache for numbers like 5, 25
    int bitCount(int num) {
        int count = 0;
        while (num > 0) {
            num >>= 1; // Equivalent to num /= 2;
            count++;
        }
        return count;
    }
};
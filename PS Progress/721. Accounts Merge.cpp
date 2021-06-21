// Question Link: https://leetcode.com/problems/accounts-merge/

class Solution {
    public:
        vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
            int len = accounts.size();
            // Build the graph
            unordered_map<string, vector<vector<string>>> graph;
            for (vector<string> &account : accounts) {
                graph[account[0]].push_back(account);
            }
            // For each account, run DFS and merge them
            vector<vector<string>> mergedAccounts;
            for (auto &it : graph) {
                for (vector<string> &account : it.second) {
                    // If the account is not merged
                    if (account[0] != "*") {
                        // Create emails sorted set for the current account
                        set<string> currentEmails;
                        currentEmails.insert(account.begin() + 1, account.end());
                        // Mark the start node as visited
                        account[0] = "*";
                        // Run DFS
                        string currentAccountName = it.first;
                        mergeAccounts(currentAccountName, currentEmails, graph);
                        // Save result
                        vector<string> tmpAccount = { currentAccountName };
                        tmpAccount.insert(tmpAccount.end(), currentEmails.begin(), currentEmails.end());
                        mergedAccounts.push_back(tmpAccount);
                    }
                }
            }
            return mergedAccounts;
        }

    void mergeAccounts(string &name, set<string> &currentEmails, unordered_map<string, vector<vector<string>>> &graph) {
        for (vector<string> &account : graph[name]) {
            if (account[0] != "*") {
                // Check if they have any common email
                for (int e = 1; e < account.size(); e++) {
                    // If common email found
                    if(currentEmails.find(account[e]) != currentEmails.end()) {
                        // Mark this account as merged
                        account[0] = "*";
                        // Push all emails
                        currentEmails.insert(account.begin() + 1, account.end());
                        // Check the other account recursively
                        mergeAccounts(name, currentEmails, graph);
                    }
                }
            }
        }
    }
};
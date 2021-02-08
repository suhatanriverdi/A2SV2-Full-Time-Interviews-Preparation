// Question Link: https://leetcode.com/problems/employee-importance

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, int> empIdxMap; // {employee, its index on employees array}
        for (int i = 0; i < employees.size(); i++) {
            empIdxMap[employees[i]->id] = i;
        }
        // Start DFS
        int result = 0;
        helper(empIdxMap, employees, id, result);
        return result;
    }
    
    void helper(unordered_map<int, int> &empIdxMap, vector<Employee*> &employees, int id, int &result) {
        result += employees[empIdxMap[id]]->importance;
        for (int &employee : employees[empIdxMap[id]]->subordinates) {
            helper(empIdxMap, employees, employee, result);
        }
    }
};
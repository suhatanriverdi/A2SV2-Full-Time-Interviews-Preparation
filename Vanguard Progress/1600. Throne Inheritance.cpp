// Question https://leetcode.com/problems/throne-inheritance

struct TrieNode {
    string name;
    vector<TrieNode*> kids;
    TrieNode(string name) {
        this->name = name;
    }
};

class ThroneInheritance {
private:
    TrieNode *root = NULL;
    unordered_map<string, TrieNode*> nodesMap;
    
public:
    ThroneInheritance(string kingName) {
        root = new TrieNode(kingName);
        nodesMap[kingName] = root;
    }
    
    void birth(string parentName, string childName) {
        TrieNode* newChild = new TrieNode(childName);
        // cout << "parentName: " << parentName << " childName: " << childName << endl;
        nodesMap[parentName]->kids.push_back(newChild);
        nodesMap[childName] = newChild;
    }
    
    void death(string deadName) {
        // Mark the person as dead by "-"
        nodesMap[deadName]->name = "-";
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> inheritanceOrder;
        dfs(root, inheritanceOrder);
        return inheritanceOrder;
    }
    
    void dfs(TrieNode *cur, vector<string> &order) {
        if (cur == NULL) {
            return;
        }
        if (cur->name != "-") {
            order.push_back(cur->name);
        }
        for (TrieNode* &kid : cur->kids) {
            dfs(kid, order);
        } 
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
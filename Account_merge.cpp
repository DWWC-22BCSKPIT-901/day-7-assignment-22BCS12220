//Account merge(Hard).
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n);
                for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); 
            }
            return parent[x];
        };
        auto unionSets = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                parent[rootX] = rootY;
            }
        };

        unordered_map<string, int> emailToIndex;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                const string& email = accounts[i][j];
                if (emailToIndex.count(email)) {
                    unionSets(i, emailToIndex[email]);
                } else {
                    emailToIndex[email] = i;
                }
            }
        }
        unordered_map<int, unordered_set<string>> groups;
        for (const auto& [email, index] : emailToIndex) {
            int root = find(index);
            groups[root].insert(email);
        }
        vector<vector<string>> result;
        for (const auto& [index, emails] : groups) {
            vector<string> mergedAccount;
            mergedAccount.push_back(accounts[index][0]); // Add name
            mergedAccount.insert(mergedAccount.end(), emails.begin(), emails.end());
            sort(mergedAccount.begin() + 1, mergedAccount.end()); // Sort emails
            result.push_back(mergedAccount);
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<vector<string>> accounts1 = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}
    };
    vector<vector<string>> result1 = solution.accountsMerge(accounts1);
    cout << "Example 1 Output:\n";
    for (const auto& account : result1) {
        for (const auto& entry : account) {
            cout << entry << " ";
        }
        cout << endl;
    }

    // Example 2
    vector<vector<string>> accounts2 = {
        {"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"},
        {"Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"},
        {"Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"},
        {"Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"},
        {"Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"}
    };
    vector<vector<string>> result2 = solution.accountsMerge(accounts2);
    cout << "\nExample 2 Output:\n";
    for (const auto& account : result2) {
        for (const auto& entry : account) {
            cout << entry << " ";
        }
        cout << endl;
    }

    return 0;
}

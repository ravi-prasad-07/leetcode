class unionSet {
    vector<int> parent, size;

public:
    unionSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int parent_u = findPar(u);
        int parent_v = findPar(v);

        if (parent_u == parent_v) {
            return;
        }

        if (size[parent_u] < size[parent_v]) {
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
        else {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        unionSet ds(n);

        unordered_map<string, int> emailToAccount;

        // Step 1: Union accounts having common emails
        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                if (emailToAccount.find(email) == emailToAccount.end()) {
                    emailToAccount[email] = i;
                }
                else {
                    ds.unionBySize(i, emailToAccount[email]);
                }
            }
        }

        // Step 2: Group emails according to their DSU parent
        vector<vector<string>> mergedEmails(n);

        for (auto it : emailToAccount) {

            string email = it.first;
            int accountIndex = it.second;

            int parent = ds.findPar(accountIndex);

            mergedEmails[parent].push_back(email);
        }

        // Step 3: Create answer
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {

            if (mergedEmails[i].empty()) {
                continue;
            }

            sort(mergedEmails[i].begin(), mergedEmails[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for (string email : mergedEmails[i]) {
                temp.push_back(email);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};

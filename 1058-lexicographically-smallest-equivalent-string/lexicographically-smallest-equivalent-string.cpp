class Solution {
public:
    char DFS(unordered_map<char, vector<char>> &adj, char curr,
             vector<int> &visited, vector<char> &component) {

        visited[curr - 'a'] = 1;
        component.push_back(curr);

        char minChar = curr;

        for (char &v : adj[curr]) {
            if (!visited[v - 'a']) {
                minChar = min(minChar, DFS(adj, v, visited, component));
            }
        }

        return minChar;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {

        unordered_map<char, vector<char>> adj;

        // Build graph
        for (int i = 0; i < s1.size(); i++) {
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }

        vector<int> visited(26, 0);
        vector<char> smallest(26);

        // Initialize each character to itself
        for (int i = 0; i < 26; i++)
            smallest[i] = 'a' + i;

        // Find the smallest character for every connected component
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (!visited[ch - 'a']) {
                vector<char> component;

                char minChar = DFS(adj, ch, visited, component);

                for (char c : component)
                    smallest[c - 'a'] = minChar;
            }
        }

        // Build answer
        string result;
        for (char ch : baseStr) {
            result.push_back(smallest[ch - 'a']);
        }

        return result;
    }
};
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        unordered_set<string> bankset(bank.begin(), bank.end());

        if (bankset.find(end) == bankset.end())
            return -1;

        unordered_set<string> visited;
        queue<string> que;

        que.push(start);
        visited.insert(start);

        int level = 0;

        while (!que.empty()) {
            int n = que.size();

            while (n--) {
                string curr = que.front();
                que.pop();

                if (curr == end)
                    return level;

                string genes = "ACGT";

                for (int i = 0; i < curr.length(); i++) {
                    char original = curr[i];

                    for (char ch : genes) {
                        if (ch == original)
                            continue;

                        string neighbour = curr;
                        neighbour[i] = ch;

                        if (visited.find(neighbour) == visited.end() &&
                            bankset.find(neighbour) != bankset.end()) {

                            visited.insert(neighbour);
                            que.push(neighbour);
                        }
                    }
                }
            }

            level++;
        }

        return -1;
    }
};
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        int idx_b = -1, idx_e = -1;
        for (int i = 0; i < wordList.size(); i ++) {
            if (wordList[i] == beginWord) idx_b = i;
            if (wordList[i] == endWord) idx_e = i;
        }
        if (idx_e == -1) return 0;
        if (idx_b == -1) {
            wordList.push_back(beginWord);
            idx_b = wordList.size() - 1;
        }
        int n = wordList.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int cnt = 0;
                for (int k = 0; k  < beginWord.size(); k ++) {
                    if (wordList[i][k] != wordList[j][k]) cnt ++;
                    if (cnt > 1) break;
                }
                if (cnt == 1) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        queue<pair<int, int>> qe;
        qe.push({idx_b, 1});
        vector<bool> st(n, false);
        st[idx_b] = true;
        while (qe.size()) {
            auto ele = qe.front();
            qe.pop();
            int node = ele.first, dis = ele.second;
            for (auto x : g[node] ) {
                if (st[x]) continue;
                if (x == idx_e) return dis + 1;
                qe.push({x, dis + 1});
                st[x] = true;
            }
        }
        return 0;
    }
};

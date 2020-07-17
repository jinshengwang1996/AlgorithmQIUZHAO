class Solution {
public:
    bool isAnagram(string s, string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        // return !s.compare(t);
        return s == t;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        int flag = true;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};

// 辅助构造hashmap
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> hash(26);
        for (int i = 0; i < s.size(); ++i) {
            ++hash[s[i] - 'a'];
        }
        for (int i = 0; i < t.size(); ++i) {
            if (--hash[t[i] - 'a'] < 0) return false;
        }
        return true;
    }
};

// 真正利用hashmap解决问题
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> hashmap;
        for (char ch : s) {
            ++hashmap[ch];
        } 
        for (char ch : t) {
            if (--hashmap[ch] < 0) return false;
        }
        return true;
    }
};
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        if(!n) return s;
        int left = 0, right = 0;
        while(right < n){
            while(right < n && s[right] != ' ') right++; 
            int next = right-- + 1; 
            while(left < right) swap(s[left++],s[right--]); 
            left = next; right = next; 
        }
        return s;
    }
};
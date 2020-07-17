class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        for (int i = digits.size() - 1; i >= 0 && carry; --i) {
            carry = (++digits[i] %= 10) == 0;
        }
        if (carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            ++digits[i];
            if (digits[i] % 10 == 0) digits[i] = 0;
            else break;
            
        }

        // if (digits[0] == 0) digits.insert(digits.begin(), 1);        
        if (digits[0] == 0) {
            digits[0] = 1;
            digits.push_back(0);
        } 
        return digits;
    }
};
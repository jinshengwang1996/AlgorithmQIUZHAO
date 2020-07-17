class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for (int i = 0; i < k; ++i) {
            int previous = nums[nums.size() - 1];
            for (int j = 0; j < nums.size(); ++j) {
                int tmp = nums[j];
                nums[j] = previous;
                previous = tmp;
            }
        }
    }
};


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::rotate(nums.begin(), nums.end() - k % nums.size(), nums.end() );
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        vector<int> res(nums.end() - k, nums.end());
        nums.erase(nums.end() - k, nums.end());
        nums.insert(nums.begin(), res.begin(), res.end());
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        vector<int> res(nums.end() - k, nums.end());
        res.insert(res.end(), nums.begin(), nums.end() - k);
        nums = res;
    }
};



class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size());
        reverse(nums, 0, k);
        reverse(nums, k, nums.size());
    }

    void reverse(vector<int>& nums, int fir, int snd) {
        while (fir < snd) {
            // swap(nums[fir++], nums[--snd]);
            // 也可以使用如下代码代替
            int tmp = nums[snd - 1];
            nums[snd - 1] = nums[fir];
            nums[fir] = tmp;

            fir++;
            snd--;
        }
    }
};
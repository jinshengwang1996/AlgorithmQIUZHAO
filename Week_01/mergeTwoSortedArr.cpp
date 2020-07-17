// 空间大小为m+n
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        while(n) A[m + n] = (!m || A[m - 1] < B[n - 1]) ? B[--n] : A[--m];
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::copy(nums2.begin(), nums2.end(), nums1.begin() + m);
        std::sort(nums1.begin(), nums1.end());
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m; i < m + n; ++i) nums1[i] = nums2[i - m];
        std::sort(nums1.begin(), nums1.end());
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int s1 = 0, s2 = 0, i = 0;
        vector<int> num(nums1);

        while (s1 < m && s2 < n) {
            nums1[i++] = num[s1] < nums2[s2] ? num[s1++] : nums2[s2++];
        }
        while (s1 < m) nums1[i++] = num[s1++];
        while (s2 < n) nums1[i++] = nums2[s2++];

    }
};

// 空间复杂度为m
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, s = 0;
        vector<int> num(m); 
        copy(nums1.begin(), nums1.begin() + m, num.begin());
        while (i < m && j < n) {
            nums1[s++] = num[i] < nums2[j] ? num[i++] : nums2[j++];
        }

        while (j < n ) nums1[s++] = nums2[j++];
        while (i < m ) nums1[s++] = num[i++];

    }
};

// 没有开辟新的空间
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, ptr = nums1.size() - 1;

        while (i >= 0 && j >= 0) {
            nums1[ptr--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }

        while (j >= 0 ) nums1[ptr--] = nums2[j--];
        while (i >= 0 ) nums1[ptr--] = nums1[i--];

    }
};


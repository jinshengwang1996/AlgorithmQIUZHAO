// solve by recursion
// class Solution {
// public:
//     double myPow(double x, int n) {
//         long long N = n;
//         return N >= 0 ? quick_pow(x, N) : 1.0 / quick_pow(x, -N);
//     }
//     double quick_pow(double x, long long N) {
//         if (N == 0) return 1.0;
//         double y = quick_pow(x, N / 2);
//         return (N %2 == 1) ? y * y * x : y * y;
//     }
// };

// solve by iteration
// class Solution {
// public:
//     double myPow(double x, int n) {
//         long long N = n;
//         return N >= 0 ? quick_pow(x, N) : 1.0 / quick_pow(x, -N);
//     }
//     double quick_pow(double x, long long N) {
//         double ans = 1.0, x_candidate = x;
//         while (N > 0) {
//             if (N % 2 == 1) ans *= x_candidate;

//             x_candidate *= x_candidate;

//             N /= 2;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     double myPow(double x, int n) {
//         double res = 1.0;
//         for (int i = n; i; i/=2) {
//             if (i&1) res *= x;
//             x *= x;
//         }
//         return n > 0 ? res : 1.0 / res;
//     }
// };

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        for (int i = n; i; i/=2) {
            if (i&1) res = n > 0 ? res * x : res / x;
            x *= x;
        }
        return res;
    }
};
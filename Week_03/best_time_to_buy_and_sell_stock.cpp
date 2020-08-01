// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if(prices.empty()) return 0;
//         int lowprices=prices[0];
//         int bestRes=0;
//         int res=0;
//         int len=prices.size();
//         for(int i=1;i<len;i++)
//         {
//              if(prices[i]<lowprices || prices[i]-lowprices<bestRes) 
//                     {res+=bestRes; bestRes=0; lowprices=prices[i];}
//              else if(prices[i]-lowprices>bestRes) bestRes=prices[i]-lowprices;
//         }
//         res+=bestRes;
//         return res;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int maxprofit = 0;
        for (int i=1;i<prices.size();++i) {
            maxprofit += max(prices[i]-prices[i-1], 0);
        }
        return maxprofit;
    }
};
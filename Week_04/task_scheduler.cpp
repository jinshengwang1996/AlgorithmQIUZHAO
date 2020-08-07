// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         int len=tasks.size();
//         vector<int> vec(26);
//         for(char c:tasks) ++vec[c-'A'];
//         sort(vec.begin(),vec.end(),[](int& x,int&y){return x>y;});
//         int cnt=1;
//         while(cnt<vec.size()&&vec[cnt]==vec[0]) cnt++;
//         return max(len,cnt+(n+1)*(vec[0]-1) );
//     }
// };

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int num[26];
        for(int i=0;i<26;i++){
            num[i]=0;
        }
        for(int i=0;i<tasks.size();i++){
            num[tasks[i]-'A']+=1;//计数每个任务出现次数
        }
        int max=0;
        int sum=0;
        int count=1;
        for(int i=0;i<26;i++){
            //找到执行次数最多的任务，和执行次数最多的任务数量
            if(num[i]>max){
                max=num[i];count=1;
            }else if(num[i]==max){
                count++;
            }
            sum+=num[i];//计算所有任务需要的执行时间
        }
        return (max*(n+1)-n+(count-1))>sum?(max*(n+1)-n+(count-1)):sum;//比较大小返回更大
    }
};





// dfs
//  class Solution {
//  public:
//      void dfs(vector<vector<int>>& M,vector<int> &visit,int n){
//          visit[n]=1;
//          for(int j=0;j<M.size();++j)
//              if(M[n][j] && !visit[j])
//                  dfs(M,visit,j);
//      }
//      int findCircleNum(vector<vector<int>>& M) {
//          int N=M.size();
//          vector<int> visit(M.size(),0);
//          int count=0;
//          for(int i=0;i<N;++i){
//              if(!visit[i]){
//                  dfs(M,visit,i);
//                  count++;
//              }
//          }
//          return count;
//      }
//  };
// bfs
//  class Solution {
//  public:
//      int findCircleNum(vector<vector<int>>& M) {
//          int N=M.size();
//          vector<int> visit(N,0);
//          int count=0,temp;
//          queue<int> Que;
//          for(int i=0;i<N;++i){
//              if(!visit[i]){
//                  count++;
//                  Que.push(i);
//                  while(!Que.empty()){
//                      temp=Que.front();
//                      Que.pop();
//                      visit[temp]=1;
//                      for(int j=0;j<N;++j)
//                          if(M[temp][j] && !visit[j])
//                              Que.push(j);
//                  }
//              }
//          }
//          return count;
//      }
//  };

class Solution {
public:
    int find(vector<int> &Vec,int n){
        if(Vec[n]==-1)
            return n;
        return find(Vec,Vec[n]);
    }

    void Union(vector<int> &Vec,int m,int n){
        int parent_m=find(Vec,m);
        int parent_n=find(Vec,n);
        if(parent_m!=parent_n)
            Vec[parent_m]=parent_n;
    }

    int findCircleNum(vector<vector<int>>& M) {
        int N=M.size();
        vector<int> parent(N,-1);
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(M[i][j]==1 && i!=j)
                    Union(parent,i,j);
            }
        }
        int count=0;
        for(int i=0;i<N;++i)
            if(parent[i]==-1)
                count++;
        return count;
    }
};

/*
 * ====================== leet_323.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 323. 无向图中连通分量的数目
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_323 {//~




// bfs
//   30%   57%
class S{
public:
    // 编号从 0 到 n-1 的 n 个节点
    // 在 edges 中不会出现重复的边
    // 所以的边都是无向边，[0, 1] 与 [1, 0]  相同，所以它们不会同时在 edges 中出现
    int countComponents(int n, std::vector<std::vector<int>>& edges ){


        std::vector<std::vector<int>> adjs (n, std::vector<int>{});
        for( auto &e : edges ){
            adjs[e[0]].push_back( e[1] );
            adjs[e[1]].push_back( e[0] );
        }

        std::vector<char> vis (n, 0);

        std::deque<int> que {};

        int count = 0;
        for( int i=0; i<n; i++ ){
            if( vis[i]==1 ){ continue; }
            count++;
            que.clear();
            que.push_back(i);
            while( !que.empty() ){
                int node = que.front();
                que.pop_front();
                vis[node]=1;

                for( int j : adjs[node] ){
                    if( vis[j]==1 ){ continue; }
                    que.push_back( j );
                }
            }
        }
        return count;
    }
};




// 并查集  89%  100%
class S2{

class MergeSeach{

    std::vector<int> st {};
    int N {};
    // 递归版的 路径压缩
    int findRoot( int a ){
        if( st[a]==a ){ return a; }
        st[a] = findRoot(st[a]);
        return st[a];
    }
public:
    void init( int N_ ){
        N = N_;
        st.resize(N,0);
        for( int i=0; i<N; i++ ){
            st[i] = i;
        }
    }
    void merge( int a, int b ){
        int roota = findRoot(a);
        int rootb = findRoot(b);
        if( roota==rootb ){ return; }
        st[rootb] = roota;// 让 rootb 成为 roota 的一个子
    }
    int get_rootNum()const{
        int ans = 0;
        for( int i=0; i<N; i++ ){
            if( st[i]==i ){ ans++; }
        }
        return ans;
    }
};

public:
    // 编号从 0 到 n-1 的 n 个节点
    // 在 edges 中不会出现重复的边
    // 所以的边都是无向边，[0, 1] 与 [1, 0]  相同，所以它们不会同时在 edges 中出现
    int countComponents(int n, std::vector<std::vector<int>>& edges ){

        MergeSeach ms {};
        ms.init(n);
        for( auto &e : edges ){
            ms.merge( e[0], e[1] );
        }
        return ms.get_rootNum();

    }
};



//=========================================================//
void main_(){

    

    



    debug::log( "\n~~~~ leet: 323 :end ~~~~\n" );
}
}//~

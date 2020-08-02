/*
 * ====================== leet_261.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 261. 以图判树
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_261 {//~


// 树：
// -1- 连通分量为1
// -2- 无环

// 另一种思路是
// -1- 连通分量为1
// -2- 有效边数为 n-1, 如果大于这个值，一定存在环


// 并查集
// 既能判断 是否有环，还能判断 有几个 连通分量
// 思路清奇

//   94%   87%
class S2{

class UnionFindSet{
    std::vector<int> st {};
    int N {};

    int find( int a ){
        if( st[a]==a ){ return a; }
        st[a] = find(st[a]);
        return st[a];
    }
public:
    explicit UnionFindSet( int N_ ):N(N_){
        st.resize(N,0);
        for( int i=0; i<N; i++ ){
            st[i]=i;
        }
    }
    void merge( int a, int b ){
        int ra = find(a);
        int rb = find(b);
        if(ra==rb){ return; }
        st[rb]=ra;
    }
    bool isSameRoot( int a, int b ){
        return find(a)==find(b);
    }
    int rootSize()const{
        int num = 0;
        for( int i=0; i<N; i++ ){
            if( st[i]==i ){ num++; }
        }
        return num;
    }
};


public:
    // 从 0 到 n-1 标号的 n 个结点
    // edges 中不会出现重复的边
    // 由于所有的边是无向边，边 [0,1] 和边 [1,0] 是相同的，
    // 因此不会同时出现在边列表 edges 中
    bool validTree(int n, std::vector<std::vector<int>>& edges ){

        UnionFindSet ufs {n};

        for( auto &e : edges ){
            int a=e[0];
            int b=e[1];
            if( ufs.isSameRoot(a,b) ){ return false; }
            ufs.merge( a,b );
        }
        return ufs.rootSize()==1;

    }
};






// 检查边数 是否为 n-1, 来确认是否存在环 
//   bfs  判断 连通分量个数

//   76%   87%
class S{
public:
    // 从 0 到 n-1 标号的 n 个结点
    // edges 中不会出现重复的边
    // 由于所有的边是无向边，边 [0,1] 和边 [1,0] 是相同的，
    // 因此不会同时出现在边列表 edges 中
    bool validTree(int n, std::vector<std::vector<int>>& edges ){

        int N = static_cast<int>(edges.size());
        if( n-1!=N ){ return false; }

        std::vector<char> vis (n,0);
        std::vector<std::vector<int>> adjs (n, std::vector<int>{});
        std::deque<int> que {};

        for( auto &e : edges ){
            int a=e[0];
            int b=e[1];
            adjs[a].push_back(b);
            adjs[b].push_back(a);
        }


        int count = 0;
        for( int a=0; a<n; a++ ){
            if( vis[a]==1 ){ continue; }
            count++;
            if( count>1 ){ return false; }// 多于一个 连通分量

            que.push_back(a);
            while( !que.empty() ){
                int e = que.front();
                que.pop_front();
                //--//
                if( vis[e]==1 ){ continue; }
                vis[e]=1;
                for( int b : adjs[e] ){
                    if( vis[b]==0 ){ que.push_back(b); }
                }
            }
        }
        return true;

    }
};



//=========================================================//
void main_(){

    
    

    debug::log( "\n~~~~ leet: 261 :end ~~~~\n" );
}
}//~

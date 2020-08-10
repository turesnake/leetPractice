/*
 * ====================== leet_886.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.10
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 886. 可能的二分法
 */
#include "innLeet.h"
#include "GraphNode1.h"


namespace leet_886 {//~


// 核心思想：根据数据，建立 邻接表
// 这样反向获得了很多组 “应该出现在一个集合中的元素”

// 遍历每个元素的 邻接表，
// -1- 保证元素 a 和所有邻接元素 b 不同集
// -2- 将 a 的所有邻接元素 merge

// 最后检测，图中的 连通分量个数

//   72%   96%
class S{

class UnionFindSet{
    std::vector<int> st {};
    int N {};
    int find( int a ){
        if( st[a]==a ){ return a; }
        st[a] = find(st[a]);
        return st[a];
    }
public:
    explicit UnionFindSet(int N_):N(N_){
        st.assign(N,0);
        for( int i=0; i<N; i++ ){
            st[i]=i;
        }
    }   
    void merge( int a, int b ){
        int ra = find(a);
        int rb = find(b);
        if( ra==rb ){ return; }
        st[rb] = ra;
    }
    bool isSameRoot( int a, int b ){
        return find(a)==find(b);
    }
    int rootSize()const{
        int ans = 0;
        for( int i=1; i<N; i++ ){
            if( st[i]==i ){ ans++; }
        }
        return ans;
    }
};

public:
    // N个元素，{1,...N}
    // 1 <= N <= 2000
    // 0 <= dislikes.length <= 10000
    // dislikes[i].length == 2
    // 1 <= dislikes[i][j] <= N
    // dislikes[i][0] < dislikes[i][1]
    // 对于dislikes[i] == dislikes[j] 不存在 i != j
    bool possibleBipartition( int N, std::vector<std::vector<int>>& dislikes ){

        if( dislikes.empty() ){ return true; }

        std::vector<std::vector<int>> adjs (N+1, std::vector<int>{});
        UnionFindSet ufs {N+1};

        for( auto &e : dislikes ){
            adjs[e[0]].push_back( e[1] );
            adjs[e[1]].push_back( e[0] );
        }

        for( int a=1; a<=N; a++ ){
            if( adjs[a].empty() ){ continue; }
            for( int b : adjs[a] ){
                if( ufs.isSameRoot(a,b) ){ return false; }
                ufs.merge( b, adjs[a][0] );
            }
        }
        return ufs.rootSize()>1;

    }
};


//=========================================================//
void main_(){

    



    

    debug::log( "\n~~~~ leet: 886 :end ~~~~\n" );
}
}//~

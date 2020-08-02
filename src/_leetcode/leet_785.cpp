/*
 * ====================== leet_785.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 785. 判断二分图
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_785 {//~


// 自创的 链式染色法  
// 取一个 未被访问的值，为其染任意色，然后将其 邻接元素，染对立色，并放入 队列

//     5%   11%
class S{
public:
    // graph 的长度范围为 [1, 100]。
    // graph[i] 中的元素的范围为 [0, graph.length-1]。
    // graph[i] 不会包含 i 或者有重复的值。
    // 图是无向的: 如果j 在 graph[i]里边, 那么 i 也会在 graph[j]里边。
    bool isBipartite( std::vector<std::vector<int>>& graph ){


        int N = static_cast<int>(graph.size());
        std::vector<char> vis    (N, 0);
        std::vector<char> colors (N, 0);//0:未上色, 1:白色, 2:黑色
        std::deque<int> que {};

        for( int l=0; l<N; l++ ){
            if( vis[l]==1 ){ continue; }
            if( colors[l]==0 ){ colors[l]=1; }
            que.clear();
            que.push_back(l);

            while( !que.empty() ){
                int a = que.front();
                que.pop_front();
                vis[a] = 1;
                int antiColor = colors[a]==1 ? 2 : 1;

                for( int b : graph[a] ){
                    if( colors[b]==colors[a] ){ return false; }// 
                    if( vis[b]==1 ){ continue; }
                    //--//
                    if( colors[b]==0 ){
                        colors[b] = antiColor;
                    }
                    que.push_back(b);
                }
            }
        }
        return true;


    }
};




// 并查集   (灵活用法)
// 元素 a 的邻接表元素 {b1,b2...bn} 
// 将这些 bn 元素 合并为 同一集合，同时检测 它们是否与a 处于 不同集合

//      10%   83%
class S2{

class UnionFindSet{
    std::vector<int> st {};
    int N {};
    int find( int a ){
        if( st[a]==a ){ return a; }
        st[a] = find(st[a]);// 路径压缩
        return st[a];
    }
public:
    explicit UnionFindSet( int N_ ){
        N = N_;
        st.resize(N,0);
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
};

public:
    // graph 的长度范围为 [1, 100]。
    // graph[i] 中的元素的范围为 [0, graph.length-1]。
    // graph[i] 不会包含 i 或者有重复的值。
    // 图是无向的: 如果j 在 graph[i]里边, 那么 i 也会在 graph[j]里边。
    bool isBipartite( std::vector<std::vector<int>>& graph ){

        int N = static_cast<int>(graph.size());
        UnionFindSet ufs {N};

        for( int a=0; a<N; a++ ){
            int Nb = static_cast<int>(graph[a].size());
            for( int b=1; b<Nb; b++ ){//[b-1],[b]
                ufs.merge( graph[a][b-1], graph[a][b] );
            }
            for( int b : graph[a] ){
                if( ufs.isSameRoot(a,b) ){ return false; }
            }
        }
        return true;

    }
};





//=========================================================//
void main_(){

    
    

    debug::log( "\n~~~~ leet: 785 :end ~~~~\n" );
}
}//~

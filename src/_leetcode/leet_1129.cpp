/*
 * ====================== leet_1129.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.03
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1129. 颜色交替的最短路径
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_1129 {//~


// 有向无权图，存在环，存在平行边

// 此题的难点在于，不能单纯地用 vis 来消除 环
// 因为有些情况下，适当走一下环路，是获得解的 唯一方式

// 但是环会导致 遍历陷入无限循环

// 此题中的环存在一个特征，第一次使用环，从而到达某点时
// 这可能是 这点的 最优解
// 之后的环 再次来到这个点时，获得的解 会变大

// 所以，一种检测方式是：
// 为每个点的 解，都区分 red 解 和 blue 解



// 这道题的核心就是 如何 可控地利用 环路
// 而不是用 vis[] 一律屏蔽 环



//   bfs   100%   66%
class SB{

struct Elem{
    bool isRed  {false};
    bool isBlue {false};
};

struct QE{
    int  idx    {};
    int  deep   {};// based on 0
    bool isRed  {false};
    bool isBlue {false};
};

struct AE{
    int red  {INT_MAX};
    int blue {INT_MAX};
};

public:
    // 1 <= n <= 100
    // red_edges.length <= 400
    // blue_edges.length <= 400
    // red_edges[i].length == blue_edges[i].length == 2
    // 0 <= red_edges[i][j], blue_edges[i][j] < n
    std::vector<int> shortestAlternatingPaths( int n, 
        std::vector<std::vector<int>>& red_edges, 
        std::vector<std::vector<int>>& blue_edges) {

        
        std::vector<std::unordered_map<int,Elem>> adjs (n, std::unordered_map<int,Elem>{});
        for( auto &e : red_edges ){
            adjs[e[0]].emplace( e[1], Elem{true,false} );
        }
        for( auto &e : blue_edges ){
            if( adjs[e[0]].count(e[1])==0 ){
                adjs[e[0]].emplace( e[1], Elem{false,true} );
            }else{// 已经存在 红边了
                adjs[e[0]].at(e[1]).isBlue = true;
            }
        }

        std::vector<AE> ans (n, AE{});
        ans[0].red = 0;
        ans[0].blue = 0;

        std::deque<QE> que { QE{0,0,true,true} };

        while( !que.empty() ){
            QE a = que.front();
            que.pop_front();

            for( auto &[b,be] : adjs[a.idx] ){
                bool isFind = false;
                QE   bqe { b, a.deep+1, false, false };
                if( a.isRed && be.isBlue ){
                    bqe.isBlue = true;
                    if( a.deep+1 < ans[b].blue ){// 核心，只使用最小限度的环
                        ans[b].blue = a.deep+1;
                        isFind = true;
                    }
                }
                if( a.isBlue && be.isRed ){
                    bqe.isRed = true;
                    if( a.deep+1 < ans[b].red ){// 核心，只使用最小限度的环
                        ans[b].red = a.deep+1;
                        isFind = true;
                    }
                }
                if( isFind ){
                    que.push_back(bqe);
                }
            }
        }

        std::vector<int> outs (n,0);
        for( int i=0; i<n; i++ ){
            outs[i] = std::min( ans[i].red, ans[i].blue );
            if( outs[i]==INT_MAX ){ outs[i]=-1; }
        }
        return outs;
    }
};


// 细节处理，和 bfs 类似

//   dfs    48%   75%
class SD{

struct Elem{
    bool isRed  {false};
    bool isBlue {false};
};

struct AE{
    int red  {INT_MAX};
    int blue {INT_MAX};
};

    std::vector<std::unordered_map<int,Elem>> adjs {};
    std::vector<AE>   ans {};


    void rec( int a, int deep, bool isRed_a, bool isBlue_a ){

        for( auto &[b,be] : adjs[a] ){
            bool isFind = false;
            bool isRed_b = false;
            bool isBlue_b = false;
            if( isRed_a && be.isBlue ){
                isBlue_b = true;
                if( deep+1 < ans[b].blue ){// 核心，只使用最小限度的环
                    ans[b].blue = deep+1;
                    isFind = true;
                }
            }
            if( isBlue_a && be.isRed ){
                isRed_b = true;
                if( deep+1 < ans[b].red ){// 核心，只使用最小限度的环
                    ans[b].red = deep+1;
                    isFind = true;
                }
            }
            if( isFind ){
                rec( b, deep+1, isRed_b, isBlue_b );
            }  
        }
    }

public:
    // 1 <= n <= 100
    // red_edges.length <= 400
    // blue_edges.length <= 400
    // red_edges[i].length == blue_edges[i].length == 2
    // 0 <= red_edges[i][j], blue_edges[i][j] < n
    std::vector<int> shortestAlternatingPaths( int n, 
        std::vector<std::vector<int>>& red_edges, 
        std::vector<std::vector<int>>& blue_edges) {

        
        adjs.resize(n, std::unordered_map<int,Elem>{});
        for( auto &e : red_edges ){
            adjs[e[0]].emplace( e[1], Elem{true,false} );
        }
        for( auto &e : blue_edges ){
            if( adjs[e[0]].count(e[1])==0 ){
                adjs[e[0]].emplace( e[1], Elem{false,true} );
            }else{// 已经存在 红边了
                adjs[e[0]].at(e[1]).isBlue = true;
            }
        }

        ans.resize(n, AE{});
        ans[0].red = 0;
        ans[0].blue = 0;

        rec( 0, 0, true, true );

        std::vector<int> outs (n,0);
        for( int i=0; i<n; i++ ){
            outs[i] = std::min( ans[i].red, ans[i].blue );
            if( outs[i]==INT_MAX ){ outs[i]=-1; }
        }
        return outs;


    }
};




//=========================================================//
void main_(){

    std::vector<std::vector<int>> reds {
        {0,1},{1,2}
    };
    std::vector<std::vector<int>> blues {
        
    };

    auto ret = SD{}.shortestAlternatingPaths( 3, reds, blues );

    cout<<"ret:"<<endl;
    for( int i : ret ){
        cout<<i<<", ";
    }cout<<endl;


   


 
    

    debug::log( "\n~~~~ leet: 1129 :end ~~~~\n" );
}
}//~

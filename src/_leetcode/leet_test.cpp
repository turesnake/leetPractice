/*
 * ====================== leet_test.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 复习用 测试台
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_test {//~




class FF{

    std::vector<std::unordered_map<int,int>> adjs {};
    std::vector<char> vis {};
    int N   {};
    int tgt {};

    int dfs( int from, int flow ){

        if( from==tgt ){ return flow; }
        vis[from] = 1;

        for( auto [to,w] : adjs[from] ){
            if( w<=0 || vis[to]==1 ){ continue; }
            int c = dfs( to, std::min(flow,w) );
            if( c==-1 ){ continue; }
            adjs[from][to] -= c;
            adjs[to][from] += c;
            return c;
        }
        return -1;
    }


public:
    // edges_[i]: { 边起点，边尾点，边容量 }
    // N_: 一共 N_ 条边，{ 0,...N_-1 }
    int ff( std::vector<std::vector<int>> edges_, int N_, int start_, int target_ ){

        N = N_;
        tgt = target_;

        adjs.assign( N, std::unordered_map<int,int>{} );
        for( auto &e : edges_ ){
            int from = e[0];
            int to = e[1];
            int w = e[2];
            adjs[from].emplace( to, w );//正向
            adjs[to].emplace( from, 0 );//反向
        }

        int ans = 0;
        while( true ){
            int c = dfs(start_, INT_MAX);
            if( c==-1 ){ break; }
            ans += c;
        }
        return ans;

    }


};



//=========================================================//
void main_(){

    
    


    debug::log( "\n~~~~ leet: test :end ~~~~\n" );
}
}//~

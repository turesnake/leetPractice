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

    std::vector<std::unordered_map<int,int>> adjs {};// <to,w>
    std::vector<char> vis {};
    int N {};
    int tgt {};

    // 只要随便找到 一条 完整的路径，就会从整个 递归中 彻底返回
    int dfs( int from, int minFlow ){

        if( from==tgt ){ return minFlow; }// 一条路径完整获得
        vis[from] = 1;
        for( auto [to,w] : adjs[from] ){
            if( w<=0 || vis[to]==1 ){ continue; }
            int c = dfs( to, std::min(w,minFlow) );
            if( c==-1 ){ continue; }// 此分支 找不到完整路径
            //-- find --//
            adjs[from][to] -= c;// 当前方向边 减少容量
            adjs[to][from] += c;// 反向边 增加容量
            return c;
        }
        vis[from] = 0;
        return -1; // 未能找到 完整路径
    }

public:
    // edges_[i]: { 边起点，边尾点，边容量 }
    // N_: 一共 N_ 条边，{ 0,...N_-1 }
    int ff( std::vector<std::vector<int>> edges_, int N_, int start_, int target_ ){

        N = N_;
        tgt = target_;
        adjs.resize(N,std::unordered_map<int,int>{});
        for( auto &e : edges_ ){
            int head = e[0];
            int tail = e[1];
            adjs[head].emplace( tail, e[2] );// 正向边
            adjs[tail].emplace( head, 0 );   // 反向边
        } 

        int ans = 0;
        while( true ){
            vis.assign(N,0);
            int c = dfs( start_, INT_MAX );
            cout<<"c:"<<c<<endl;
            if( c==-1 ){ break; }// 再也找不到 增广路径了
            ans += c;
        }
        return ans;
    }

};












//=========================================================//
void main_(){

    std::vector<std::vector<int>> edges {
        {0,1,6},
        {1,3,8},
        {0,2,6},
        {2,1,2},
        {2,3,3}
    };

    auto ret = FF{}.ff( edges, 4, 0, 3 );

    cout<<"ff: ret:"<<ret<<endl;
    


    debug::log( "\n~~~~ leet: test :end ~~~~\n" );
}
}//~

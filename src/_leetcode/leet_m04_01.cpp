/*
 * ====================== leet_m04_01.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 04.01. 节点间通路
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_m04_01 {//~

// 有向无权图，



// 朴素法   64%  14%
class S{
public:
    // 节点数量n在[0, 1e5]范围内。
    // 节点编号大于等于 0 小于 n。
    // 图中可能存在自环和平行边。
    bool findWhetherExistsPath( int n, std::vector<std::vector<int>>& graph, int start, int target ){

        std::vector<char> vis (n,0);// 用来过滤环路
        std::vector<std::unordered_set<int>> nexts (n, std::unordered_set<int>{});
        for( auto &e : graph ){
            nexts[e[0]].insert( e[1] );// maybe, 过滤掉 重复边
        }

        std::deque<int> que {start};

        while( !que.empty() ){
            int e = que.front();
            que.pop_front();
            //--//
            if( vis[e]==1 ){ continue; }
            vis[e]=1;
            if( nexts[e].count(target)>0 ){ return true; }//find
            for( int nxt : nexts[e] ){
                if( vis[nxt]==0 ){ que.push_back(nxt); }
            }
        }
        return false;

    }
};



//=========================================================//
void main_(){

    

    



    debug::log( "\n~~~~ leet: m04_01 :end ~~~~\n" );
}
}//~

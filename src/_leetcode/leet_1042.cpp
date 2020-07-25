/*
 * ====================== leet_1042.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.23
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1042. 不邻接植花
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1042 {//~



// 无向图：邻接表法：
// 每个元素，维护一个容器，存储所有 和 自己相连的 其它元素


// 目标色为 [1,2,3,4]
// 先为所有元素，上色0，
// 然后遍历 邻接表中的每个元素，检查它的 关联元素（0～3个），将关联元素的 已使用色去掉，
// 剩下的颜色区间里，挑一个用在自己身上


//   29%  66%
class S{
public:
    // 共 N 个元素 [1,N]
    // 1 <= N <= 10000
    // 0 <= paths.size <= 20000
    // 不存在花园有 4 条或者更多路径可以进入或离开。
    // 保证存在答案。
    std::vector<int> gardenNoAdj( int N, std::vector<std::vector<int>>& paths ){

        if( paths.empty() ){
            return std::vector<int>( N,1 );
        }

        std::vector<std::unordered_set<int>> adjs ( N+1, std::unordered_set<int>() );// [0]空置
        for( auto &e : paths ){
            adjs[e[0]].insert(e[1]);
            adjs[e[1]].insert(e[0]);
        }
        
        std::vector<int> outs (N, 0);
        for( int i=0; i<N; i++ ){
            std::unordered_set<int> colors {1,2,3,4};
            for( int ei : adjs[i+1] ){
                colors.erase( outs[ei-1] );// maybe
            }
            outs[i] = *colors.begin();
        }
        return outs;

        
    }
};



//=========================================================//
void main_(){


    
    debug::log( "\n~~~~ leet: 269 :end ~~~~\n" );
}
}//~

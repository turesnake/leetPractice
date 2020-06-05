/*
 * ====================== leet_m16_11.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 16.11. 跳水板
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m16_11 {//~


// 83%, 100%
class S{
public:
    std::vector<int> divingBoard( int shorter, int longer, int k ){

        if( k==0 ){ return {}; }
        int off = longer - shorter;
        int fst = shorter*k;
        if( off==0 ){ return {fst}; }

        std::vector<int> outs ( k+1, fst ); // 预分配大小
        for( int i=1; i<=k; i++ ){
            outs.at(i) += i*off;
        }
        return outs;
    }
};



//=========================================================//
void main_(){

    debug::log( "\n~~~~ leet: m16_11 :end ~~~~\n" );
}
}//~

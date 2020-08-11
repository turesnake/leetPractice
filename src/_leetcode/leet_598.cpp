/*
 * ====================== leet_598.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.11
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 598. 范围求和 II
 */
#include "innLeet.h"
#include "GraphNode1.h"


namespace leet_598 {//~

// 本质上，是个 不停地 在xy两个放心上 收缩区间的题


//  51%  54%
class S{
public:
    // m 和 n 的范围是 [1,40000]。
    // a 的范围是 [1,m]，b 的范围是 [1,n]。
    // 操作数目不超过 10000
    int maxCount(int m, int n, std::vector<std::vector<int>>& ops ){

        int minW = m;
        int minH = n;
        for( auto &e : ops ){
            minW = std::min( minW, e[0] );
            minH = std::min( minH, e[1] );
        }
        return minW*minH;

    }
};


//=========================================================//
void main_(){





    

    debug::log( "\n~~~~ leet: 598 :end ~~~~\n" );
}
}//~

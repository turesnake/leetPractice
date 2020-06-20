/*
 * ====================== leet_746.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 746. 使用最小花费爬楼梯
 */
#include "innLeet.h"


namespace leet_746 {//~



// 基础 dp 题， 类似 斐波契纳数列


//   99%   10%
class S{
public:
    // 2<= len <= 1000
    // 0<= [i] <= 999
    int minCostClimbingStairs( std::vector<int>& cost ){

        int N = static_cast<int>(cost.size());

        std::vector<int> dp (N, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for( int i=2; i<N; i++ ){
            dp[i] = std::min(dp[i-2], dp[i-1]) + cost[i];
        }
        return std::min(dp[N-1], dp[N-2]);


    }
};




//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 746 :end ~~~~\n" );
}
}//~

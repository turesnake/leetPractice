/*
 * ====================== leet_1259.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1259. 不相交的握手
 */
#include "innLeet.h"
#include "GraphNode1.h"


namespace leet_1259 {//~


// 可能是实现起来最简单的 困难题了


// 一维 dp
// 从 0 开始，计算 每个 偶数的 分配个数
// 将 数组 分为 l，r 两个区间，
// 对 l区间有要求，比如死 l区间 两端元素相连，内部元素自由组合
// r区间的元素，始终可以自由组合
// l 区间的长度，逐渐从 2，到 N


//   67%   19%
class S{
public:
    // 2 <= num_people <= 1000
    // num_people % 2 == 0
    // 每次计算结果，都取模 10^9+7
    int numberOfWays( int num_people ){

        if( num_people==2 ){ return 1; }

        std::vector<int64_t> dp (num_people+1, 0);
        dp[0] = 1;
        dp[2] = 1;

        for( int n=4; n<=num_people; n+=2 ){
            int64_t sum = 0;
            for( int l=2; l<=n; l+=2 ){
                int64_t Nl = dp[l-2];
                int64_t Nr = dp[n-l];
                sum += (Nl*Nr)%1000000007;
            }
            dp[n] = sum%1000000007;
        }
        return dp[num_people]%1000000007;

    }
};




//=========================================================//
void main_(){


    

    debug::log( "\n~~~~ leet: 1259 :end ~~~~\n" );
}
}//~

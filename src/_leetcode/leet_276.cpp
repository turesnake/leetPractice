/*
 * ====================== leet_276.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 276. 栅栏涂色
 */
#include "innLeet.h"


namespace leet_276 {//~




// dp
// 结构上类似 股票题，持有和不持有，变成了 同色 和 不同色
// 所以是一个 [n][2] dp


//   100%  100%
class S{

struct Elem{
    int same {0};// 末尾两杆 同色 
    int diff {0};// 末尾两杆 异色
};

public:
    // n 栏杆数量 >=0 
    // k 颜色数量 >=0
    int numWays( int n, int k ){

        if( k==0 || n==0 ){ return 0; }
        if( k==1 ){ return (n<=2) ? 1 : 0; }
        if( n==1 ){ return k; }
        // 往后，k>=2, n>=2

        std::vector<Elem> dp (n+1, Elem{});// [0],[1] 无效

        dp[2].same = k * 1;
        dp[2].diff = k * (k-1);

        for( int i=3; i<=n; i++ ){
            dp[i].same = dp[i-1].diff;
            dp[i].diff = (dp[i-1].same + dp[i-1].diff) * (k-1);
        }

        return dp[n].same + dp[n].diff;


    }
};




//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 276 :end ~~~~\n" );
}
}//~

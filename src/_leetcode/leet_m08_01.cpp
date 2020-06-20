/*
 * ====================== leet_m08_01.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 08.01. 三步问题
 */
#include "innLeet.h"


namespace leet_m08_01 {//~


//   23%   100%
class S{
public:
    // 1 <= n <= 1000000
    int waysToStep( int n ){

        if(n==1){ return 1; }
        if(n==2){ return 2; }
        if(n==3){ return 4; }

        std::vector<int> dp (n+1, 0);// [0] 空置
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for( int i=4; i<=n; i++ ){
            dp[i] = (dp[i-1]+dp[i-2])%1000000007 + dp[i-3];
            dp[i] %= 1000000007;
        }
        return dp[n];

    }
};


//=========================================================//
void main_(){


    
    debug::log( "\n~~~~ leet: m08_01 :end ~~~~\n" );
}
}//~

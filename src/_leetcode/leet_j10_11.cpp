/*
 * ====================== leet_j10_11.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 剑指 Offer 10- II. 青蛙跳台阶问题
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_j10_11 {//~


// 100% 100%
class S{
public:
    // 0 <= n <= 100
    int numWays( int n ){
        
        if( n==0 ){ return 1; }
        if( n<=2 ){ return n; }
        std::vector<int> dp (n+1, 1);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for( int i=3; i<=n; i++ ){// [i-2, i]
            dp[i] = (dp[i-1]+dp[i-2])%1000000007;
        }
        return dp[n];

    }
};



//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: j10_11 :end ~~~~\n" );
}
}//~

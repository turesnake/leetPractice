/*
 * ====================== leet_j14_1.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.15
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 剑指 Offer 14- I. 剪绳子
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_j14_1 {//~


// 与 343  题相同


class S{
public:
    // 2 <= n <= 58
    int cuttingRope( int n ){

        std::vector<int> dp (n+1, 1);// dp[2] 之前的空置

        for( int len=2; len<=n; len++ ){
            int tmax = 0;
            for( int k=1; k<len; k++ ){
                int inn = std::max(dp[k],k) * (len-k);
                tmax = std::max( tmax, inn );
            }
            dp[len] = tmax;
        }
        return dp[n];

    }
};


//=========================================================//
void main_(){





    debug::log( "\n~~~~ leet: j14_1 :end ~~~~\n" );
}
}//~

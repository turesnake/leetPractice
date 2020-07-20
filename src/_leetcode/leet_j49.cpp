/*
 * ====================== leet_j49.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.20
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 剑指 Offer 49. 丑数
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_j49 {//~


// 经典题，三指针


//  90%  100%
class S{
public:
    // 1 是丑数
    // n 不超过1690。
    // n>0
    int nthUglyNumber( int n ){

        if(n==1){ return 1; }
        std::vector<int> dp (n+1, 1);//dp[1]=1
        int p2 = 1;
        int p3 = 1;
        int p5 = 1;
        for( int i=2; i<=n; i++ ){
            dp[i] = std::min( std::min( dp[p2]*2, dp[p3]*3 ), dp[p5]*5 );
            if( dp[i]==dp[p2]*2 ){ p2++; }
            if( dp[i]==dp[p3]*3 ){ p3++; }
            if( dp[i]==dp[p5]*5 ){ p5++; }
        }
        return dp[n];


    }
};



//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: j49 :end ~~~~\n" );
}
}//~

/*
 * ====================== leet_j60.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.22
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 剑指 Offer 60. n个骰子的点数
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"



namespace leet_j60 {//~


// dp 思路
// 忠实计算出，要计算出每种值，存在多少种累加可能性
// 最后再计算 概率



//   40%   100%
class S{
public:
    // 1 <= n <= 11
    std::vector<double> twoSum( int n ){

        int W = n*6;
        int H = n;
        std::vector<std::vector<int>> dp (H+1, std::vector<int>( W+1, 0 ));

        // dp[1][w]
        for( int w=1; w<=6; w++ ){
            dp[1][w] = 1;
        }
        // dp[h][w], h>1
        for( int h=2; h<=H; h++ ){
            for( int w=h; w<=h*6; w++ ){
                int tsum = 0;
                for( int i=1; i<=w-h+1 && i<=6; i++ ){
                    tsum += dp[h-1][w-i];
                }
                dp[h][w] = tsum;
            }
        }
        //---//
        int allSum = 0;
        for( int w=n; w<=n*6; w++ ){
            allSum += dp[n][w];
        }
        std::vector<double> outs {};
        for( int w=n; w<=n*6; w++ ){
            outs.push_back( static_cast<double>(dp[n][w])/static_cast<double>(allSum) );
        }
        return outs;

    }
};





//=========================================================//
void main_(){


    auto ret = S{}.twoSum( 2 );



    
    debug::log( "\n~~~~ leet: j60 :end ~~~~\n" );
}
}//~

/*
 * ====================== leet_309.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 309. 最佳买卖股票时机含冷冻期
 */
#include "innLeet.h"


namespace leet_309 {//~


// 股票问题，一维dp，冷冻期 通过 “错位下标访问” 来实现
// 也就是说，dp[i][1] 只能购买 dp[i-2][0]


//   16%  14%
class S{
public:
    int maxProfit( std::vector<int>& prices ){

        size_t N = prices.size();
        if( N<=1 ){ return 0; }
        std::vector<std::vector<int>> dp (N, std::vector<int>{0,0} );
        // 手动写 dp[1]
        int off1 = prices[1]-prices[0];
        dp[1][0] = std::max( 0, 0+off1 );
        dp[1][1] = dp[1][0]; // 不受冻结期影响
        if( N==2 ){ return dp.back().at(0); }

        for( size_t i=2; i<N; i++ ){// [i-2],[i-1],[i]
            int off = prices[i]-prices[i-1];
            // [0] 本回合不持有
            dp[i][0] = std::max(
                dp[i-1][0],
                dp[i-1][1] + off
            );
            // [1] 本回合持有
            dp[i][1] = std::max(
                dp[i-2][0], // 此处体现出 冻结期
                dp[i-1][1] + off
            );
        }
        //cout<<"dp:"<<endl; for( auto &c : dp ){ cout<<"  "<<c[0]<<", "<<c[1]<<endl;}
        return dp.back().at(0);


    }
};







//=========================================================//
void main_(){

    std::vector<int> v { 1,2,3,0,2 };

    auto ret = S{}.maxProfit(v);
    cout<<"ret:"<<ret<<endl;


    debug::log( "\n~~~~ leet: 309 :end ~~~~\n" );
}
}//~

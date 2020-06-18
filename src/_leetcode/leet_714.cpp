/*
 * ====================== leet_714.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 714. 买卖股票的最佳时机含手续费
 */
#include "innLeet.h"


namespace leet_714 {//~


// 在转换方程上，允许 多次买卖
// 每次结算时，扣除 交易费 


class S{
public:
    // 0 < prices.len <= 50000
    // 0 < prices[i] < 50000
    // 0 <= fee < 50000
    int maxProfit( std::vector<int>& prices, int fee ){

        size_t N = prices.size();
        std::vector<std::vector<int>> dp ( N, std::vector<int>{0,0} );

        for( size_t i=1; i<N; i++ ){
            int off = prices.at(i) - prices.at(i-1);
            // 持有[1]
            dp[i][1] = std::max(
                dp[i-1][0],
                dp[i-1][1] + off
            );
            // 非持有[0]
            dp[i][0] = std::max(
                dp[i-1][0],
                dp[i-1][1] + off - fee // 本回合才卖出
            );
        }
        //cout<<"dp:"<<endl; for( auto &c : dp ){ cout<<"  "<<c[0]<<","<<c[1]<<endl;}
        return dp.back().at(0);
            

    }
};




//=========================================================//
void main_(){

    std::vector<int> v { 1,3,2,8,4,9 };

    auto ret = S{}.maxProfit(v,2);

    cout<<"ret:"<<ret<<endl;




    debug::log( "\n~~~~ leet: 714 :end ~~~~\n" );
}
}//~

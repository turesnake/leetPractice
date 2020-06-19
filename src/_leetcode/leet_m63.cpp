/*
 * ====================== leet_m63.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题63. 股票的最大利润
 */
#include "innLeet.h"


namespace leet_m63 {//~


// 因为只能购买一次
// 每一回合的 [i][1], 都可以选择 作为起始购买点，也就是无视 [i-1][0]
// 每一回合的 [i][0], 都可以从 [i-1][0] 和本回合卖出的 值之间，做选择


// dp   9%   100%
class S{
public:
    // 0 <= len <= 10^5
    int maxProfit( std::vector<int>& prices ){

        if(prices.empty()){ return 0; }
        int N = static_cast<int>(prices.size());
        std::vector<std::vector<int>> dp (N, std::vector<int>{0,0});

        for( int i=1; i<N; i++ ){//[i-1],[i]
            int off = prices[i]-prices[i-1];
            // 无论 [i-1][0] 是否已经卖出，
            // 每一回合的 [i][1] 都可以成为 买入点
            dp[i][1] = std::max(
                0,
                dp[i-1][1] + off
            );
            dp[i][0] = std::max(
                dp[i-1][0],
                dp[i-1][1] + off
            );
        }
        //cout<<"dp:"<<endl; for( auto &c : dp ){ cout<<" "<<c[0]<<", "<<c[1]<<endl; }cout<<endl;
        return dp[N-1][0];

    }
};




//=========================================================//
void main_(){

    std::vector<int> v { 7,6,4,3,2,1 };

    auto ret = S{}.maxProfit(v);
    cout<<"ret:"<<ret<<endl;

    
    debug::log( "\n~~~~ leet: m63 :end ~~~~\n" );
}
}//~

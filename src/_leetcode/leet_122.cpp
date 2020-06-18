/*
 * ====================== leet_122.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 122. 买卖股票的最佳时机 II
 */
#include "innLeet.h"


namespace leet_122 {//~



// 只需要 一维dp 就可以了 


//   95%   100%
class S{
public:
    // 1 <= prices.len <= 3*10^4
    // 0 <= prices[i] <= 10^4
    int maxProfit( std::vector<int>& prices ){

        size_t N = prices.size();
        std::vector<int> dp (N,0);

        for( size_t i=1; i<N; i++ ){
            int off = prices[i] - prices[i-1];
            dp[i] = std::max(
                dp[i-1],
                dp[i-1] + off
            );
        }
        //cout<<"dp:"<<endl; for( auto i : dp ){ cout<<"  "<<i<<endl;}
        return dp.back();
        
    }
};



//=========================================================//
void main_(){

    std::vector<int> v { 7,6,4,3,1 };

    auto ret = S{}.maxProfit(v);

    cout<<"ret:"<<ret<<endl;

    
    debug::log( "\n~~~~ leet: 122 :end ~~~~\n" );
}
}//~

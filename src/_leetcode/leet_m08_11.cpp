/*
 * ====================== leet_m08_11.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 08.11. 硬币
 */
#include "innLeet.h"


namespace leet_m08_11 {//~


// 只有在 被5整除 的数，才会发生变化 


// 目前的思路是对的，但是超时了，似乎有更快更直观的实现 

// 本质上还是 背包问题，
// 但是，为了优化时间，避免超时，一种解法中，将 4 次 h层的遍历，全部做进了一个 一维dp 中
// 


class S{

    const std::vector<int> bases { 1, 5, 10, 25 };

public:
    // 0 <= n <= 1000000
    int waysToChange( int n ){

        if( n==0 ){ return 1; }

        n/=5;
        std::vector<std::vector<int>> dp ( 4, std::vector<int>(n+1, 1) );

        // dp[0][w] 全为 1
        // dp[h][w]
        for( int h=1; h<4; h++ ){
            int base = bases[h];// 1,5,10,25

            for( int w=0; w<=n; w++ ){
                int val = w==0 ? 1 : w*5;
                int times = val/base;// 倍数
                if( times == 0 ){ 
                    dp[h][w] = dp[h-1][w];
                    continue; 
                }

                int sum = dp[h-1][w]; 
                for( int t=1; t<=times; t++ ){
                    int tm = (val-t*base)/5;
                    sum += dp[h-1][tm];
                    sum %= 1000000007;
                }
                dp[h][w] = sum;
            }
        }
        //cout<<"dp:\n"; for( auto &c : dp ){ for( int i:c ){ cout<<i<<", "; }cout<<endl; }

        return dp[3][n];
    }
};




//=========================================================//
void main_(){

    auto ret = S{}.waysToChange( 31 );

    cout<<"ret: " <<ret<<endl;
    
    


    debug::log( "\n~~~~ leet: m08_11 :end ~~~~\n" );
}
}//~

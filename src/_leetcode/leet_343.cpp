/*
 * ====================== leet_343.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 343. 整数拆分
 */
#include "innLeet.h"


namespace leet_343 {//~



// 一维dp


// 此题有个小机关， 将数 n 拆分为 数个子数后的乘积，不一定比 数n 本身大
// 所以，可拆可不拆，都要纳入比较范围


//  100%  100%
class S{
public:
    // 2 <= n <= 58
    int integerBreak(int n) {


        std::vector<int> dp (n+1,0);
        dp[0] = 0;// 无意义
        dp[1] = 1;

        for( int i=2; i<=n; i++ ){
            int mmax = 0;
            for( int l=1; l<i; l++ ){
                int r = i-l;
                int inn = std::max(dp[l],l) * r; // 核心！！
                mmax = std::max( mmax, inn );
            }
            dp[i] = mmax;
        }
        //cout<<"dp:"<<endl; 
        //for( int i=0; i<=n; i++ ){  cout<<"  "<<i<<":"<<dp[i]<<endl; }
        return dp.back();

    }
};




//=========================================================//
void main_(){

    auto ret = S{}.integerBreak( 10 );

    cout<<"ret:"<<ret<<endl;



    
    debug::log( "\n~~~~ leet: 343 :end ~~~~\n" );
}
}//~

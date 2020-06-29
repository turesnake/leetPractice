/*
 * ====================== leet_410.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.28
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 410. 分割数组的最大值
 */
#include "innLeet.h"


namespace leet_410 {//~



// 写起来特别烦


//   33%   100%%
//  为防止数据溢出，内部使用 int64_t
class S{
public:
    // 1 <= n <= 1000
    // 1 <= m <= min(50, n) 意味着，所有被划分的区间，一定非空
    // [i] >= 0
    int splitArray( std::vector<int>& nums, int m ){

        int N = static_cast<int>(nums.size());
        std::vector<std::vector<int64_t>> dp (N, std::vector<int64_t>(m+1, 0));

        // [i][1], [i][i+1]
        int64_t sum = 0;
        int mmax = 0;
        for( int i=0; i<N; i++ ){
            sum += nums[i];
            dp[i][1] = sum;
            if( i+1 <= m ){
                mmax = std::max( mmax, nums[i] );
                dp[i][i+1] = mmax;
            }
        }
        //cout<<"dp1: "<<endl; for( auto &c : dp ){ for(int64_t i: c){ cout<<i<<", "; } cout<<endl; }cout<<endl;

        // oth
        for( int r=1; r<N; r++ ){
            for( int k=2; k<=m && k<=r; k++ ){// 分成 k 个区间

                int64_t minMax = LONG_MAX; // 最小的 ”最大值“
                int64_t rSum = 0;

                for( int ki=r; ki>=k-1; ki-- ){
                    rSum += nums[ki];
                    int64_t tMax = std::max( dp[ki-1][k-1], rSum );
                    minMax = std::min( minMax, tMax );
                }
                minMax = std::min( minMax, dp[r][1] );
                dp[r][k] = minMax;
                //debug::log( "dp[{}][{}] = {}\n", r, k, minMax );
            }
        }
        //cout<<"dp2: "<<endl; for( auto &c : dp ){ for(int64_t i: c){ cout<<i<<", "; } cout<<endl; }cout<<endl;
        return  static_cast<int>(dp[N-1][m]);


    }
};




//=========================================================//
void main_(){

    std::vector<int> v { 1,2147483647 };

    auto ret = S{}.splitArray( v, 2 );

    cout<<"ret: "<<ret<<endl;


    
    debug::log( "\n~~~~ leet: 410 :end ~~~~\n" );
}
}//~

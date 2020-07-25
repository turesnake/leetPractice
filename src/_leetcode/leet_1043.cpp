/*
 * ====================== leet_1043.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.25
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1043. 分隔数组以得到最大和
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1043 {//~


// 两层dp，


//   64%  100%
class S{
public:
    // 1 <= K <= A.length <= 500
    // 0 <= A[i] <= 10^6
    int maxSumAfterPartitioning( std::vector<int>& A, int K ){

        int N = static_cast<int>(A.size());
        //=== dp 1 ===//
        std::vector<std::vector<int>> maxdp ( K+1, std::vector<int>(N,0) );// maxdp[0][w] 空置
        // maxdp[1][w]
        for( int w=0; w<N; w++ ){
            maxdp[1][w] = A[w];
        }
        // maxdp[h][w],h>1
        for( int h=2; h<=K; h++ ){
            for( int w=h-1; w<N; w++ ){
                maxdp[h][w] = std::max( maxdp[h-1][w-1], A[w] );
            }
        }
        //=== dp 2 ===//
        std::vector<int> dp (N,0);
        // 0 <= i < K
        int i=0;
        for(; i<K; i++ ){
            dp[i] = maxdp[i+1][i] * (i+1);
        }
        // i >= K
        for(; i<N; i++ ){
            int mmax = INT_MIN;
            for( int j=1; j<=K; j++ ){
                int tsum = maxdp[j][i]*j + dp[i-j];
                mmax = std::max( mmax, tsum );
            }
            dp[i] = mmax;
        }
        return dp[N-1];


    }
};



//=========================================================//
void main_(){





    
    debug::log( "\n~~~~ leet: 1043 :end ~~~~\n" );
}
}//~

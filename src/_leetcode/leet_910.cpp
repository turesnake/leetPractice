/*
 * ====================== leet_910.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.20
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 910. 最小差值 II
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_910 {//~


// dp， 形式上类似 股票题


// 实践证明，目前的 dp 法是不正确的。


// 先改用 回溯+dfs 法   妥妥的超时
class S{

    std::vector<std::vector<int>> v {};
    int N {};
    int outOff {INT_MAX};


    void work( int idx, int mmin, int mmax ){

        if( idx==N ){
            outOff = std::min( outOff, mmax-mmin );
            return;
        }
        // [0]
        int nmin = std::min( mmin, v[idx][0] );
        int nmax = std::max( mmax, v[idx][0] );
        if( nmax-nmin<outOff ){ work( idx+1, nmin, nmax ); }
        // [1]
        nmin = std::min( mmin, v[idx][1] );
        nmax = std::max( mmax, v[idx][1] );
        if( nmax-nmin<outOff ){ work( idx+1, nmin, nmax ); }        
    }

public:
    // 1 <= A.length <= 10000
    // 0 <= A[i] <= 10000
    // 0 <= K <= 10000
    int smallestRangeII( std::vector<int>& A, int K ){

        N = static_cast<int>(A.size());
        v.resize(N, std::vector<int>(2,0));
        for( int i=0; i<N; i++ ){
            v[i][0] = A[i]-K;
            v[i][1] = A[i]+K;
        }
        work(0, INT_MAX, INT_MIN );
        return outOff;

    }
};




// 官方思路, 本质上是 贪心算法


//  朴素排序版   56%  25%
class S2{
public:
    // 1 <= A.length <= 10000
    // 0 <= A[i] <= 10000
    // 0 <= K <= 10000
    int smallestRangeII( std::vector<int>& A, int K) {

        int N = static_cast<int>(A.size());
        if( N<=1 ){ return 0; }

        std::sort( A.begin(), A.end() );
    
        int outMin = A.back()-A[0];
        int fstUp = A[0]+K;
        int lstDown = A.back()-K;
        
        // 将 [0,i] 区间 划分为 左区间
        for( int i=0; i<N-1; i++ ){// [i],[i+1]
            int off = std::max(A[i]+K, lstDown) - std::min(fstUp, A[i+1]-K);
            outMin = std::min( outMin, off );
        }
        return outMin;

    }
};








//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: 910 :end ~~~~\n" );
}
}//~

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







class S2{
public:
    int smallestRangeII( std::vector<int>& A, int K) {

        



        return 0;//tmp



    }
};





//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: 910 :end ~~~~\n" );
}
}//~

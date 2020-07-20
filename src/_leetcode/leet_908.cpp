/*
 * ====================== leet_908.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.20
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 908. 最小差值 I
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_908 {//~


//   98%  50%
class S{
public:
    // 1 <= A.length <= 10000
    // 0 <= A[i] <= 10000
    // 0 <= K <= 10000
    int smallestRangeI( std::vector<int>& A, int K ){

        int mmin = INT_MAX;
        int mmax = INT_MIN;
        for( int i : A ){
            mmin = std::min( mmin, i );
            mmax = std::max( mmax, i );
        }
        mmin += K;
        mmax -= K;
        return mmin>=mmax ? 0 : mmax-mmin;

    }
};


//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: 908 :end ~~~~\n" );
}
}//~

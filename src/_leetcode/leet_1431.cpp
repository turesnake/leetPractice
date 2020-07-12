/*
 * ====================== leet_1431.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.12
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1431. 拥有最多糖果的孩子
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1431 {//~



//   100%   100%
class S{
public:
    // 2 <= candies.length <= 100
    // 1 <= candies[i] <= 100
    // 1 <= extraCandies <= 50
    std::vector<bool> kidsWithCandies( std::vector<int>& candies, int extraCandies) {

        //=== find mmax ===//
        int mmax = INT_MIN;
        for( int i : candies ){
            mmax = std::max( mmax, i );
        }

        //=== check ===//
        int N = static_cast<int>(candies.size());
        std::vector<bool> outs ( N, false );

        for( int i=0; i<N; i++ ){
            outs[i] = (mmax-candies[i]) <= extraCandies;
        }
        return outs;

    }
};



//=========================================================//
void main_(){

    


    debug::log( "\n~~~~ leet: 1431 :end ~~~~\n" );
}
}//~

/*
 * ====================== leet_977.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 977. 有序数组的平方
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_977 {//~


// 朴素法 8%, 25%
// 这题 其实考的是 排序
// 如果借用现成的 mset 来排序，成绩不会太好看 ...
class S{
public:
    // 1<= len <= 10000
    // -10000 <= [i] <= 10000
    std::vector<int> sortedSquares( std::vector<int>& A ){

        std::multiset<int> mset {};
        for( int i : A ){
            mset.insert(  i*i );
        }
        return std::vector<int>(mset.begin(), mset.end());
    }
};




//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 977 :end ~~~~\n" );
}
}//~

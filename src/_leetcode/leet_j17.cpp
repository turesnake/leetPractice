/*
 * ====================== leet_j17.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.15
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 剑指 Offer 17. 打印从1到最大的n位数
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_j17 {//~


//  99%  100%
class S{
public:
    // n>0
    std::vector<int> printNumbers( int n ){

        int maxVal = 9;
        for( int i=1; i<n; i++ ){
            maxVal = 10*maxVal + 9;
        }

        std::vector<int> outs {};
        for( int i=1; i<=maxVal; i++ ){
            outs.push_back(i);
        }
        return outs;


    }
};


//=========================================================//
void main_(){





    debug::log( "\n~~~~ leet: j17 :end ~~~~\n" );
}
}//~

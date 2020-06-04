/*
 * ====================== leet_1085.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1085 {//~


// 似乎没有什么 鸡贼法

// 朴素法 74%， 100%
class S{
public:
    // 数组非空
    int sumOfDigits( std::vector<int>& A ){

        int mmin {INT_MAX};
        for( int i : A ){
            if( i < mmin ){ mmin=i; }
        }
        int out = 0;
        for( ; mmin!=0; mmin/=10 ){
            out += mmin%10;
        }
        return (out&1)==0 ? 1 : 0;
    }
};




//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 1085 :end ~~~~\n" );
}
}//~

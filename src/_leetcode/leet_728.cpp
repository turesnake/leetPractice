/*
 * ====================== leet_728.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.20
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 728. 自除数
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_728 {//~



// 朴素法   100%   100%
class S{
public:
    // l,r 包含在 区间内
    // 1 <= left <= right <= 10000
    std::vector<int> selfDividingNumbers( int left, int right ){


        std::vector<int> outs {};

        for( int num=left; num<=right; num++ ){
            bool isLegal = true;
            for( int i=num; i>0; i/=10 ){
                int v = i%10;
                if( v==0 || num%v!=0 ){
                    isLegal = false;
                    break;
                }
            }
            if( isLegal ){
                outs.push_back( num );
            }
        }
        return outs;

    }
};



//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: 728 :end ~~~~\n" );
}
}//~

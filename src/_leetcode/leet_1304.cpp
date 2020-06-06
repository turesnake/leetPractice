/*
 * ====================== leet_1304.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1304. 和为零的N个唯一整数
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1304 {//~


// 52% 100%
class S{
public:
    // 1 <= n <= 1000
    std::vector<int> sumZero( int n ){

        std::vector<int> outs {};
        if( (n&1)==1 ){//奇数个
            outs.push_back(0);
            n--;
        }
        for( int i=1; i<=n/2; i++ ){
            outs.push_back( i );
            outs.push_back( -i );
        }
        return outs;
    }
};





//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 1304 :end ~~~~\n" );
}
}//~
